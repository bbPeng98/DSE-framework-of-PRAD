from ..generator.from_magma import FromMagma
from ..generator.generator import Generator, PortReference
import magma
from typing import List, Union, Iterable, Tuple
from ordered_set import OrderedSet
from collections import OrderedDict
from .pipeline_register import PipelineRegister


def pass_signal_through(gen: Generator, signal):
    """Takes in an existing input of the tile and creates and output
       to pass the signal through
       returns the new output port reference
    """
    pass_through = None
    if signal in gen.ports.values():
        pass_through = signal
    elif signal in gen.ports.keys():
        pass_through = gen.ports[signal]
    assert pass_through is not None, "Cannot find " + pass_through
    # Create output port for pass through
    output_name = pass_through.qualified_name() + "_out"
    gen.add_port(output_name, magma.Out(pass_through.base_type()))
    # Actually make the pass through connection
    gen.wire(pass_through, gen.ports[output_name])
    return gen.ports[output_name]


def or_reduction(gen: Generator, sub_circuit_name: str, signal_name: str,
                 config_data_width: int,
                 sub_circuit_port_name: str = "O"):
    """Embeds @signal_name reduction network in tile by accepting a @signal_name
       input from another tile and ORing it with the origin @@signal_name
       output of this tile to create a new read_data output.

        @signal_name has to be connected to @sub_circuit_name
    """
    pass_through = gen.ports[signal_name]
    input_name = pass_through.qualified_name() + "_in"
    # Create input port for pass through @signal_name reduction
    gen.add_port(input_name, magma.In(pass_through.base_type()))
    # get the sub circuit
    sub_circuit = getattr(gen, sub_circuit_name)
    # Remove the current connection to the @signal_name output
    gen.remove_wire(sub_circuit.ports[sub_circuit_port_name], pass_through)
    read_data_reduce_or = FromMagma(magma.Bits[config_data_width]._declare_binary_op("or"))
    read_data_reduce_or.underlying.name = f"{signal_name}_or"
    # OR previous read_data output with @signal_name input to create NEW
    # @signal_name output
    gen.wire(sub_circuit.ports[sub_circuit_port_name],
             read_data_reduce_or.ports.I0)
    gen.wire(gen.ports[input_name], read_data_reduce_or.ports.I1)
    gen.wire(read_data_reduce_or.ports.O, pass_through)

    return gen.ports[input_name]


def replace(parent: Generator, old_gen: Generator, new_gen: Generator):
    """
    replace the old_gen with the new generator. The interfaces of
    @old_gen has to be the same as the @new_gen
    :param parent: parent generator that holds the old_gen
    :param old_gen: target generator to be replaced
    :param new_gen: new generator to use
    :return: None
    """
    # we first make sure that the interfaces are the same
    assert len(old_gen.ports) == len(new_gen.ports)
    for port_name, old_port in old_gen.ports.items():
        assert port_name in new_gen.ports
        new_port = new_gen.ports[port_name]
        assert old_port.base_type() == new_port.base_type()

    # looping through the wires in parent that need to be replaced
    wires = set()
    for conn_from, conn_to in parent.wires:
        if conn_from.owner() == old_gen:
            wires.add((conn_from, conn_to))
        if conn_to.owner() == old_gen:
            wires.add((conn_from, conn_to))

    # remove the wires
    for conn_from, conn_to in wires:
        parent.remove_wire(conn_from, conn_to)

    # adding wires back using the new generator
    for conn_from, conn_to in wires:
        if conn_from.owner() == old_gen:
            next_port = conn_to
            current_port = conn_from
        else:
            assert conn_to.owner() == old_gen
            next_port = conn_from
            current_port = conn_to

        # reconstructing the port based on the ops stored in the original port
        # slices
        new_port = current_port.get_port(new_gen.ports)
        parent.wire(new_port, next_port)


def pipeline_wire(gen: Generator, in_port, *out_ports, **kwargs):
    """
    Connects in_port to all out_ports with a single pipeline register in between.
    If port0 and an out_port are already connected, this will remove
    that wire, and replace it with a pipelined connection.
    """
    pipe_reg = PipelineRegister(in_port.type())
    gen.wire(in_port, pipe_reg.ports.I)
    gen.wire(kwargs['clk'], pipe_reg.ports.clk)
    for out_port in out_ports:
        gen.remove_wire(in_port, out_port)
        gen.wire(pipe_reg.ports.O, out_port)




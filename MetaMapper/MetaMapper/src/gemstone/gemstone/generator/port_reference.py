from abc import ABC, abstractmethod
import magma


class Op(ABC):
    @abstractmethod
    def __call__(self, obj):
        pass

    @abstractmethod
    def transform_name(self, name):
        pass


class GetItem(Op):
    def __init__(self, index):
        self.index = index

    def __call__(self, obj):
        try:
            return type(obj).__getitem__(obj, self.index)
        except TypeError:
            # this is due to magma's Bits[1] vs Bit
            assert self.index == 0
            return obj

    def transform_name(self, name):
        return name


class GetAttr(Op):
    def __init__(self, name):
        self.name = name

    def __call__(self, obj):
        return getattr(obj, self.name)

    def transform_name(self, name):
        return self.name


class PortReferenceBase(ABC):
    def __init__(self):
        self._ops = []
        self._connections = []

    @abstractmethod
    def get_port(self, inst):
        pass

    @abstractmethod
    def owner(self):
        pass

    @abstractmethod
    def clone(self):
        pass

    @abstractmethod
    def base_type(self):
        pass

    def __getitem__(self, index):
        clone = self.clone()
        clone._ops.append(GetItem(index))
        return clone

    def __getattr__(self, name):
        clone = self.clone()
        clone._ops.append(GetAttr(name))
        return clone

    def type(self):
        T = self.base_type()
        inst = T()
        for op in self._ops:
            inst = op(inst)
        return type(inst)


class PortReference(PortReferenceBase):
    def __init__(self, owner, name, T):
        super().__init__()
        self._owner = owner
        self._name = name
        self._T = T
        self._global = False

    def get_port(self, inst):
        port = getattr(inst, self._name)
        for op in self._ops:
            port = op(port)
        return port

    def owner(self):
        return self._owner

    def clone(self):
        clone = PortReference(self._owner, self._name, self._T)
        clone._ops = self._ops.copy()
        clone._connections = self._connections.copy()
        return clone

    def base_type(self):
        return self._T

    def qualified_name(self):
        name = self._name
        for op in self._ops:
            name = op.transform_name(name)
        return name

    @staticmethod
    def __get_bit_width(t):
        if issubclass(t, magma.Digital):
            return 1
        if issubclass(t, magma.Bits):
            return len(t)

    def __hash__(self):
        return hash(self._name) ^ \
            hash(PortReference.__get_bit_width(self._T)) ^ \
            hash(self._owner.name())


class ConvertedPortReference(PortReference):
    def __init__(self, reference, converter):
        super().__init__(reference._owner, reference._name, reference._T)
        self._converter = converter

    def get_port(self, inst):
        return self._converter(super().get_port(inst))

def __init__(self):

    # Data registers
    self.rega: DataReg = DataReg()
    self.regb: DataReg = DataReg()

    # Bit Registers
    self.regd: BitReg = BitReg()
    self.rege: BitReg = BitReg()
    self.regf: BitReg = BitReg()

    #ALU
    self.alu: ALU = ALU()

    #Condition code
    self.cond: Cond = Cond()

    #Lut
    self.lut: LUT = LUT()

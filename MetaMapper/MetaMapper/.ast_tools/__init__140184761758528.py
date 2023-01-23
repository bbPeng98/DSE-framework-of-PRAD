def __init__(self):

    # Data registers
    self.rega: DataReg = DataReg()
    self.regb: DataReg = DataReg()

    # Bit Registers
    # self.regd: BitReg = BitReg()
    # self.rege: BitReg = BitReg()
    # self.regf: BitReg = BitReg()
    # self.regg: BitReg = BitReg()
    # self.regh: BitReg = BitReg()
    # self.regi: BitReg = BitReg()
    #need generate bit registers
    self.regd: BitReg = BitReg()
    self.rege: BitReg = BitReg()

    #ALU
    self.alu: ALU = ALU()

    #Condition code
    self.cond: Cond = Cond()

    #Lut
    self.lut: LUT = LUT()

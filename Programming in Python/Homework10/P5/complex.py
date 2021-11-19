class Complex(object):

    # constructor
    def __init__(self, real=0, imag=0):  # default values, if unset
        self.real = real
        self.imag = imag

    def __str__(self):  # for more convenience printing the numbers
        if self.imag > 0:  # naive approach to print the + sign
            return str(self.real) + '+' + str(self.imag) + 'i'
        elif self.imag < 0:  # minus is printed by default
            return str(self.real) + str(self.imag) + 'i'
        else:  # imag == 0
            return str(self.real)

    # arithmetic operators, formulas from the slides
    def __add__(self, other):
        return Complex(self.real + other.real, self.imag + other.imag)

    def __sub__(self, other):
        return Complex(self.real - other.real, self.imag - other.imag)
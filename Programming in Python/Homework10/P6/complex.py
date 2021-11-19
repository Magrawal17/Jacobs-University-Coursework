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

    def __mul__(self, other):
        return Complex(self.real * other.real - self.imag * other.imag,
                       self.real * other.imag + self.imag * other.real)

    def __truediv__(self, other):
        try:  # trial block as there might be exceptions
            # separate by numerators and denominators
            real_num = self.real * other.real + self.imag * other.imag
            real_den = other.real * other.real + other.imag * other.imag
            imag_num = self.imag * other.real - self.real * other.imag
            imag_den = other.real * other.real + other.imag * other.imag
            new_real = real_num / real_den
            new_imag = imag_num / imag_den
            return Complex(new_real, new_imag)
        except ZeroDivisionError as err:  # handling error case 0 division
            print(err)

    # relation operators
    def __eq__(self, other):
        if self.real == other.real and self.imag == other.imag:
            return True
        else:
            return False

    def __ne__(self, other):  # similar to the equality
        if not self==other:
            return True
        else:
            return False
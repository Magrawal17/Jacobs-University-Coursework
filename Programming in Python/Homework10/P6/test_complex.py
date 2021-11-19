from complex import *  # include the class from file


def main():  # example implementation

    # creating two complex numbers
    c1 = Complex(2, 3)
    c2 = Complex(3, -4)
    c4=Complex(3,-4)
    c3 = Complex()  # default values (0, 0)
    # I am going to use it to show exceptional case
    print("[c1] =", c1)
    print("[c2] =", c2)
    print("[c3] =", c3)
    print("\nIs c1 == c2?", c1 == c2)
    print("Is c1 != c2?", c1 != c2)
    print("Is c2 != c4?", c2 != c4)
    print("\nc1 + c2 = ", c1 + c2)
    print("c1 - c2 = ", c1 - c2)
    print("c1 * c2 = ", c1 * c2)
    print("c1 / c2 = ", c1 / c2, '\n')
    print("c1 / c3 = ", c1 / c3)

main()
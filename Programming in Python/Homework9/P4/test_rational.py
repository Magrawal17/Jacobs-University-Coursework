from rational import *

def main():

    n=int(input("Enter numerator for first number = "))
    d=int(input("Enter denominator for first number = "))

    n2=int(input("Enter numerator for second number = "))
    d2=int(input("Enter denominator for second number = "))

    print()
    
    R1=Rational(n,d)
    R2=Rational(n2,d2)

    print("The first number's numberator is {0} and denominator is {1}".format(R1.numerator(),R1.denominator()))
    print("The second number's numberator is {0} and denominator is {1}".format(R2.numerator(),R2.denominator()))

    print("The result of addition of {0} and {1} is = {2}".format(R1,R2,R1+R2))
main()
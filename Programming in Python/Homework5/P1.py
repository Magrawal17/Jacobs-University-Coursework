def main():
    cups=float(input("Enter value for cups = "))
    gallons=float(input("Enter value for gallons = "))
    print("The input in litres is =",to_liter(gallons,cups))
def to_liter(gallon,cup):
    return ((3.7854*gallon)+(0.2366*cup))
main()
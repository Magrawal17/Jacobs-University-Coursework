def convert(miles):
    km = miles * 1.609344
    return km

miles = float(input("Enter miles: "))
km = convert(miles)
print(miles, "miles =", km, "km")
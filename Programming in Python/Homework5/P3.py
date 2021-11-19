from math import pi
r=float(input("Enter a float value = "))

def volume(r):
    return ((4/3)*pi*(r**3))

print("Volume is =",volume(r))
mins = int(input("Enter a positive value: "))
if mins < 0:
    print("Illegal: Entered value is negative!")
else:
    hours = mins//60
    minutes = mins%60
    print("Hours:", hours, "\nMinutes:", minutes)
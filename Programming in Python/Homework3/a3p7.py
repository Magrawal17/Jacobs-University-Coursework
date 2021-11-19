integer = int(input("Enter an integer: "))
if integer < 1:
    print("Illegal: Entered integer is smaller than 1")
else:
    n = 1
    while n <= integer:
        if n == 1:
            print("{} minute = {} seconds".format(n, n*60))
        else:
            print("{} minutes = {} seconds".format(n, n*60))
        n += 1
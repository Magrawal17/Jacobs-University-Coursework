# asking for the integers
int_1 = int(input("Enter an integer: "))
int_2 = int(input("Enter the 2nd integer: "))
 
# using try and except for zerodivision error
try:
    # if no error, printing the division
    print("Division:", int_1, "/", int_2,"=", int_1/int_2)
except ZeroDivisionError as arr:
    # printing the error
    print("Error: ", arr)
 
# asking for integer
s = input("Enter a string: ")
 
# using try and except for type error
 
try:
    print(s+int_1)
except TypeError as err:
    print("Error: ", err)
 
# taking a input
mode = input("Enter the mode of opening the file:")
# using try and except for value error
try:
    f = open('myfile.txt', mode)
    print(f.read())
    f.close()
except ValueError as prr:
    print("Error: ", prr)
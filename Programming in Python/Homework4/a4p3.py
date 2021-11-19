while True:
    char = input("Enter a character: ")
    if "A" <= char <= "Z":
        break
    print("Please enter an uppercase alphabet! Try again")

while True:
    n= input("Number")
    if 0 <= n <= 30:
        break
    print("Try again")

for i in range(ord(char),ord(char)+n+1):
    char_new = chr(i)
    print(char_new)
char = input("Enter a character: ")
n = int(input("Enter iterations: "))
for i in range(ord(char),ord(char)+n+1):
    char_new = chr(i)
    print(char_new, end=" ")
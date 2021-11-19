def print_rectangle(n, m, c):
    for row in range(n):
        for column in range(m):
            print(c, end="")
        print() 

n = int(input("Enter n: "))
m = int(input("Enter m: "))
c = input("Enter char: ")
print_rectangle(n, m, c)

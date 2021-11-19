s=input("Enter a string = ")
l=len(s)

while True:
    a=int(input("Enter first integer = "))
    # a can go form 0 to n-1
    if a<l and a>=0:#should be less than the length to get the last character as the indexing of last character is [n-1]
        break

while True:
    b=int(input("Enter second integer = "))
    #b can go from 1 (also 0 if we return empty string) to n
    #should be equal to length as the stop value should be 1 value greater than the exact stop position for [n] it should be [n+1]
    if b<=l and b>=0:#can also think of stop as total characters that we want to read so we cant read upto length of the string 
        break

print(s[a:b])



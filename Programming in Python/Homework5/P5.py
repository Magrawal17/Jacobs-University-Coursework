st=input("Enter a string = ")

i=0
while(i<len(st)):
    print(" "*i,end="") #or can also loop another loop here
    print(st[i])
    i+=1

for i in range(len(st)):
    print(" "*i,end="") #or can also loop another loop here
    print(st[i])
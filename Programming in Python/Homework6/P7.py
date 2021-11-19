lst=[]
while(True):
    a=int(input("Enter integer = "))
    if a==0:
        break
    else:
        lst.append(a)

lst.sort()
b=len(lst)

min=lst[0]
max=lst[b-1]

print("Max = {0} and min = {1}".format(max,min))
def main():

    lst1=[]
    lst2=[]

    print("Enter first list:")
    while(True):
        a=int(input("Enter integer = "))
        if a<0:
            break
        else:
            lst1.append(a)
    
    print("\nEnter second list:")
    while(True):
        a=int(input("Enter integer = "))
        if a<0:
            break
        else:
            lst2.append(a)

    if overlapping(lst1,lst2)==True:
        print("\nThe two lists are overlapping")
    else:
        print("\nThe two lists are not overlapping")

def overlapping(list1,list2):
    answer=False

    for i in list1:
        for j in list2:
            if i==j:
                answer=True
    return answer

main()
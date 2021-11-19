def main():

    lst=[] 

    n=int(input("Enter an integer = "))
    print("Enter {} float values:".format(n))

    for i in range(n):
        a=float(input("Enter a floating point value ="))
        lst.append(a)
    
    lst2=[]
    for element in lst: #imp for this question
        lst2.append(element)
    
    print("Original lsit:")
    print_list(lst)

    add(lst,1.5)
    print("After adding 1.5")
    print_list(lst)

    multiply(lst2,5)
    print("After multiplying by 5")
    print_list(lst2)

def add(lst,val):
    count=0
    for i in lst:
        lst[count]=lst[count]+val
        count+=1

def multiply(lst,val):
    count=0
    for i in lst:
        lst[count]=lst[count]*val
        count+=1

def print_list(lst):
    for i in lst:
        f=float(i)
        print(f)

main()
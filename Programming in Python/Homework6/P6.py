def main():
    lst=[] 

    n=int(input("Enter an integer = "))
    print("Enter {} integer values:".format(n))

    for i in range(n):
        a=int(input("Enter a value ="))
        lst.append(a)
        
    histogram(lst)

def histogram(lst):
    for i in lst:
        print (i*'*')

main()


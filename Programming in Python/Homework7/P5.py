def main():
    tup=()
    while(1):
        a=int(input("Enter an integer = "))
        if a<0:
            break
        tup=tup+(a,)
    print(tup)

    new_tup=()
    
    #method 1

    for i in reversed(tup):
        new_tup=new_tup+(i,)

    print(new_tup)

    #method2
    new_tup2=()

    i=len(tup)-1
    while i>=0:
        new_tup2=new_tup2+(tup[i],)
        i-=1

    print(new_tup2)

main()
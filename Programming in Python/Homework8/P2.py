def main():
    #read three values start, end, step (gap)
    s=float(input("Enter start value = "))
    e=float(input("Enter start value = "))
    g=float(input("Enter start value = "))
    fm = "{0:>5.1f}{1:>7.1f}{2:>8.4f}{3:>12.7f}\n"

    #now print all the table into a file
    fil=open("Output.txt","w")
    fil.write("{0:>5}{1:>7}{2:>8}{3:>12}\n".format("inch","cm","m","km"))
    i=s
    while(i<=e):
        cm=i*2.54
        m=cm/100
        km=m/1000
        fil.write(fm.format(i,cm,m,km))
        i+=g
    fil.close()
main()
def in2cm_table(s, e, g):    
    fm = "{0:>5.1f}{1:>7.1f}"
    print("{0:>5}{1:>7}".format("inch","cm"))
    i=s
    while(i<=e):
        conv=i*2.54
        print(fm.format(i,conv))
        i+=g

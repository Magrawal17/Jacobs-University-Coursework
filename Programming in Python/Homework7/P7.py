def main():
    sampleDict = {'Physics': 82, 'Math': 85, 'History': 75,'Management': 70, 'Chemistry': 72}
    
    key=input("Enter the key value = ")

    a=sampleDict.get(key,None)

    if a==None:
        print("The key does not exist!")
    else:
        print("The key has the following value:",a)

main()
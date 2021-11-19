def main():
    while(True):
        s=input("Enter a string = ")
        if s=="":
            break
        else:
            print("Total vowles in string =",count_vowels(s))

def count_vowels(s):
    s=s.lower()
    count=0
    for i in s:
        if i=='a' or i=='e' or i== 'i'\
            or i=='o' or i=='u':
           count+=1
    return count 
main()
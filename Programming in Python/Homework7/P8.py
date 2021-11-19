def main():
    stack=[]
    while(1):
        ch=input()
        if (ch=='s'):
            n=int(input())
            push(stack,n)
        elif (ch=='p'):
            pop(stack)
        elif(ch=='e'):
            empty(stack)
        elif(ch=='q'):
            break
        else:
            print("Invalid value entered! Input again")
    print("Good Bye!")

def isEmpty(stack):
    if (len(stack)==0): #can also use if not a: return empty else: return not empty
        return True
    else:
        return False

def push(stack,val):
    print("Pushing",val)
    stack.append(val)
    
def pop(stack):
    if (isEmpty(stack)==True):
        print("Stack underflow")
        return
    else:
        print("Popping element",stack.pop())
        return

def empty(stack):
    print("Emptying stack")
    while (isEmpty(stack)!=True):
        pop(stack)
    return



main()
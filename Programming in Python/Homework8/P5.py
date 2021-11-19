queue = [] 

def main():
    #implement queue using a list
    #need three functions enequeu, dequeue and printq
    while(True):
        ch=int(input("Enter your option\n1:Add data to queue\
            \n2:Remove data fromn queue\n3:Print queue\n4:Exit\n"))
        if ch==1:
            enqueue()
        elif ch==2:
            dequeue()
        elif ch==3:
            printq()
        elif(ch==4):
            print("Good bye!")
            break
        else:
            print("Incorrect input try again")

def enqueue():
    val=int(input("Input number to add to the queue = "))
    queue.append(val)
    print("\n{} added to the queue".format(val))
    print()

def dequeue():
    if len(queue)!=0:
        print("\nThe value removed from the queue is",queue.pop(0))
        print()
    else:
        print("Queue underflow!")
        print()
        return

def printq():
    print("\nThe elements of the queue are:")
    for elem in queue:
        print(elem, end=" ")
    print()
    print()
    return
main()

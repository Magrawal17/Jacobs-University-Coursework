from module_queue import * 

queue = [] 

def main():
    #implement queue using a list
    #need three functions enequeu, dequeue and printq
    while(True):
        ch=int(input("Enter your option\n1:Add data to queue\
            \n2:Remove data fromn queue\n3:Print queue\n4:Exit\n"))
        if ch==1:
            enqueue(queue)
        elif ch==2:
            dequeue(queue)
        elif ch==3:
            printq(queue)
        elif(ch==4):
            print("Good bye!")
            break
        else:
            print("Incorrect input try again")

main()
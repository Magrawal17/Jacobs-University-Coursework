def enqueue(queue):
    val=int(input("Input number to add to the queue = "))
    queue.append(val)
    print("\n{} added to the queue".format(val))
    print()
    return

def dequeue(queue):
    if len(queue)!=0:
        print("\nThe value removed from the queue is",queue.pop(0))
        print()
    else:
        print("Queue underflow!")
        print()
    return

def printq(queue):
    print("\nThe elements of the queue are:")
    for elem in queue:
        print(elem, end=" ")
    print()
    print()
    return

import random
random.seed() # why do we use seed in random?

minval=1
maxval=30

r=random.randint(minval,maxval)
count=0
while True:
    guess=int(input("Enter yours guess = "))
    count+=1
    if r==guess:
        print("You got it")
        print("Total attempts =",count)
        break
    elif guess<r:
        print("Your guess is too small!")
        print("Total attempts =",count)
    else:
        print("Your guess is too high!")
        print("Total attempts =",count)

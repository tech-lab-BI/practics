import random

com = random.randrange(100)
attpmt = int(input("Enter How many  attempt you take : "))

for i in range(attpmt):

    user = int(input("Guess a number between 1 and 100: "))

    if user  < com :
        print("Too low, try again!")
    elif user > com :
        print("Too high, try again!")
    else:
        print("You guessed it!")
        break

if i == attpmt - 1 :
    print("Better luck next time !!")
    print("Ans :- ",com);


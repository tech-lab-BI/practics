import random

words = ['hello','python','programme','computer','technology']

com = random.choice(words)
attpmt = int(input("Enter how many attpmt you take : "))

for i in range(attpmt):
    user = input("Enter word : ")
    if user != com:
        print("Incorrect ! try again")
    else:
        print("Congratulations ! you guessed it")
        break
    if i == attpmt - 1:
        print("Sorry ! you didn't guess it")
        print("ANS :- ",com)
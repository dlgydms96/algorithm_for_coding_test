f = open("input.txt", 'r')
line = f.readline()
n=int(line)
trip=list(map(int, f.readline().split()))
f.close()

pcnt=0
gcnt=0
trip.sort() #sort ascending
for t in trip:
    pcnt+=1 # add adventurer in a guild
    if(pcnt==t): # check if the guild meets the minimum number of adventurer
        gcnt+=1
        pcnt=0

print(gcnt)
n=1260
cnt=0

change=[500,100,50,10]

for c in change: #divide the money in large monetary order for greedy algorithm.
    cnt+=n//c #// means quotient with integer value(/ means quotient with float value)
    n%=c

print(cnt)
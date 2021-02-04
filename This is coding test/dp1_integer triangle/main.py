
f=open('input.txt','r')
n=int(f.readline())
tri=[]
for l in range(1,n+1):
    tri.append(list(map(int,f.readline().split())))

import sys
n=int(sys.stdin.readline().rstrip())
tri=[]
for l in range(1,n+1):
    tri.append(list(map(int,sys.stdin.readline().rstrip().split())))

#print(tri)
memo=[[0 for _ in range(n)] for _ in range(n)]
for i in range(len(tri)):
    for j in range(len(tri[i])):
        #print(tri[i][j])
        if i==0: memo[i][j]=tri[i][j]
        elif j==0: memo[i][j]=memo[i-1][j]+tri[i][j]
        elif j==i: memo[i][j]=memo[i-1][j-1] + tri[i][j]
        else:
            memo[i][j]=max(memo[i-1][j-1], memo[i-1][j]) + tri[i][j]

print(max(memo[n-1]))
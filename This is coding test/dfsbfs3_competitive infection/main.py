f = open("input.txt", 'r')
n,k = map(int,f.readline().split())
graph=[[] for _ in range(n)]
for i in range(n):
    g = list(map(int,f.readline().split()))
    graph[i]=g
s,ox,oy = map(int,f.readline().split())
f.close()
'''
import sys
n,k = map(int,sys.stdin.readline().rstrip().split())
graph=[[] for _ in range(n)]
for i in range(n):
    g = list(map(int,sys.stdin.readline().rstrip().split()))
    graph[i]=g
s,ox,oy = map(int,sys.stdin.readline().rstrip().split())
'''

qlist=[[] for _ in range(k+1)]
for x in range(n):
    for y in range(n):
        if(graph[x][y]): qlist[graph[x][y]].append((x,y))

head=[1,-1,0,0]
def dfs(q,num):
    newq=[]
    for r,c in q:
        for i in range(len(head)):
            x=r+head[i]
            y=c+head[len(head)-1-i]
            if(x<n and y<n and x>=0 and y>=0 and graph[x][y]==0):
                graph[x][y]=num
                newq.append((x,y))
    print()
    return newq

for t in range(s):
    for i in range(k):
        qlist[i+1]=dfs(qlist[i+1], i+1)
    for g in range(n):print(graph[g])

print(graph[ox-1][oy-1])
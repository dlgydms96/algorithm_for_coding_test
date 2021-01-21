f = open("input.txt", 'r')
n,m,k,x = map(int,f.readline().split())
graph=[[] for _ in range(n+1)]
for _ in range(m):
    s,g = map(int,f.readline().split())
    graph[s].append(g)
f.close()
'''
import sys
n,m,k,x = map(int,sys.stdin.readline().rstrip().split())
graph=[[] for _ in range(n+1)]
for _ in range(m):
    s,g = map(int,sys.stdin.readline().rstrip().split())
    graph[s].append(g)
'''
from collections import deque

nxt=deque()
check=[0]*(n+1)
res=[]
nxt.appendleft((x,0))

while(not len(nxt)==0):
    cur,idx=nxt.pop()
    if(check[cur]): continue
    check[cur]=1
    if(idx==k): res.append(cur); continue
    for g in graph[cur]:
        nxt.appendleft((g,idx+1))

if(len(res)==0): print(-1)
else:
    res.sort()
    for i in res: print(i)
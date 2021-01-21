'''
f = open("input.txt", 'r')
n,m = map(int,f.readline().split())
graph=[[] for _ in range(n)]
for i in range(n):
    g = list(map(int,f.readline().split()))
    graph[i]=g
f.close()
'''
import sys
n,m = map(int,sys.stdin.readline().rstrip().split())
graph=[[] for _ in range(n)]
for i in range(n):
    g = list(map(int,sys.stdin.readline().rstrip().split()))
    graph[i]=g

area=list()
virs=list()
for r in range(n):
    for c in range(m):
        if(graph[r][c]==0): area.append((r,c))
        elif(graph[r][c]==2): virs.append((r,c))

from itertools import combinations
from copy import deepcopy

head=[1,-1,0,0]
def dfs(grph, v):
    r,c=v
    for i in range(len(head)):
        x=r+head[i]
        y=c+head[len(head)-i-1]
        if(x<n and y<m and x>=0 and y>=0 and grph[x][y]==0):
            grph[x][y]=2
            dfs(grph, (x,y))

def cnt_zero(grph):
    c=0
    for l in grph:
        for i in l:
            if i==0: c+=1
    return c

cnt=0
for comb in combinations(area,3):
    test=deepcopy(graph)
    for r,c in comb:
        test[r][c]=1
    for v in virs:
        dfs(test,v)
    cnt=max(cnt, cnt_zero(test))

print(cnt)
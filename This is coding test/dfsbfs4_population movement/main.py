f = open("input.txt", 'r')
n,l,r = map(int,f.readline().split())
graph=[[] for _ in range(n)]
for i in range(n):
    g = list(map(int,f.readline().split()))
    graph[i]=g

f.close()
'''
import sys
n,l,r = map(int,sys.stdin.readline().rstrip().split())
graph=[[] for _ in range(n)]
for i in range(n):
    g = list(map(int,sys.stdin.readline().rstrip().split()))
    graph[i]=g

'''
from collections import deque
check=[[-1]*n for _ in range(n)]

q=deque()
head=[1,-1,0,0]
mainflag=True

def bfs(c,yeonhap):
    bef=0
    num=0
    global mainflag
    while(q):
        x, y=q.pop()
        if(not check[x][y]==-1): continue
        yeonhap.append((x,y))
        check[x][y]=c
        for i in range(len(head)):
            xx=x+head[i]
            yy=y+head[len(head)-1-i]
            if(xx<n and yy<n and xx>=0 and yy>=0 and check[xx][yy]==-1):
                if(l<= abs(graph[x][y]-graph[xx][yy]) <=r):
                    mainflag=True
                    q.appendleft((xx,yy))
        bef+=graph[x][y]
        num+=1
    return bef//num

result=0
while(mainflag):
    cnt=0
    res=[]
    mainflag=False
    for x in range(n):
        for y in range(n):
            flag=False
            if(check[x][y]==-1):
                yeonhap=[]

                for i in range(len(head)):
                    xx=x+head[i]
                    yy=y+head[len(head)-1-i]
                    if(xx<n and yy<n and xx>=0 and yy>=0 and check[xx][yy]==-1):
                        if(l<= abs(graph[x][y]-graph[xx][yy]) <=r):
                            flag=True

                if(flag):
                    q.appendleft((x,y))
                    pop=bfs(cnt, yeonhap)
                    cnt+=1
                    for a,b in yeonhap: graph[a][b]=pop
    #if(check[n-1][n-1]==n*n-1): break
    #input()
    result+=1
    check=[[-1]*n for _ in range(n)]

print(result-1)
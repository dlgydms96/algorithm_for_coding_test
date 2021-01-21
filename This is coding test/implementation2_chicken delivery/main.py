f = open("input.txt", 'r')
n,m = map(int,f.readline().split())
board=[]
for i in range(n):
    line = list(map(int,f.readline().split()))
    board.append(line)
f.close()

from itertools import combinations

def get_chk(brd):
    chk=[]
    home=[]
    for row in range(n):
        for col in range(n):
            if(brd[row][col]==2): 
                chk.append((row, col))
            elif(brd[row][col]==1):
                home.append((row, col))
    return chk,home

def sum_dist(home,it):
    res=0
    for h in home:
        dis=n*2
        hx, hy=h
        for i in it:
            ix, iy=i
            dis=min(dis,abs(hx-ix)+abs(hy-iy))
        res+=dis
    return res

def select_chk(crd, hom):
    tot=1000000000000000
    for i in combinations(crd, m):
        tot=min(tot,sum_dist(hom,i))
    return tot

crd,home=get_chk(board)
print(select_chk(crd,home))
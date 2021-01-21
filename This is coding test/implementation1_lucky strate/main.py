f = open("input.txt", 'r')
line = f.readline()
n=int(line)
line = f.readline()
k=int(line)
apple=[]
for i in range(k):
    line = tuple(map(int,f.readline().split()))
    apple.append(line)

line = f.readline()
L=int(line)
head=[]
for i in range(L):
    line = tuple(f.readline().split())
    head.append(line)

f.close()

'''
line = input()
n=int(line)
line = input()
k=int(line)
apple=[]
for i in range(k):
    line = tuple(map(int,input().split()))
    apple.append(line)

line = input()
L=int(line)
head=[]
for i in range(L):
    line = tuple(input().split())
    head.append(line)
'''

sela = {
    (0,1):(1,0),
    (0,-1):(-1,0),
    (-1,0):(0,1),
    (1,0):(0,-1),
}

def move(cx, cy, snake):
    curr=(cx,cy)
    if(cx>n or cy >n or cx<=0 or cy<=0 or curr in snake):
        return True
    snake.append(curr)
    if(not any(curr== a for a in apple)):
        #move tail
        snake.pop(0)
    else: apple.remove(curr)
    return False

def main():
    x=0
    y=1
    curr=(1,1)
    cx,cy=curr
    snake=[curr]
    cnt=0
    crash=False
    for h in head:
        t,a=h
        t=int(t)
        cx, cy=curr
        while(cnt<t):
            cnt+=1
            cx+=x; cy+=y
            curr=(cx,cy)
            print(snake)
            crash=move(cx,cy,snake)
            if(crash):
                print(cnt)
                return 0
        if(a=='D'):
            x,y=sela[(x,y)]
        elif(a=='L'):
            for k,v in sela.items():
                if(v==(x,y)):
                    x,y=k
                    break
    while(not crash):
        cnt+=1
        cx+=x; cy+=y
        curr=(cx,cy)
        print(snake)
        crash=move(cx,cy, snake)
    print(cnt)
    return 0
main()

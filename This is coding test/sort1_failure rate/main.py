f = open("input.txt", 'r')
n = int(f.readline())
g = list(map(int,f.readline().split()))

f.close()

def rtrate(data):
    return data[1]

def solution(N, stages):
    answer = []
    summary=[0]*(N+1)
    tot=len(stages)
    for s in stages:
        if(s<=N): summary[s]+=1

    off=0
    rate=[]

    for i,s in enumerate(summary):
        if(tot==off): rate.append((i,0))
        else: rate.append((i,s/(tot-off)))
        off+=s

    rate.sort(key=rtrate,reverse=True)
    for i,r in rate:
        if(0 < i <= N):answer.append(i)

    return answer

print(solution(n,g))
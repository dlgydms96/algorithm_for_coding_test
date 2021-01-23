
import heapq
f = open("input.txt", 'r')
n = int(f.readline())
card_list=[]
for _ in range(n):
    heapq.heappush(card_list, int(f.readline()))
f.close()
'''
import sys
n = int(sys.stdin.readline().rstrip())
card_list=[]
for _ in range(n):
    card_list.append(int(sys.stdin.readline().rstrip()))
'''
def grouping_cards(cards):
    cnt=0
    while(not len(cards)==1):
        bef=heapq.heappop(cards)
        aft=heapq.heappop(cards)
        cnt+=(bef+aft)
        heapq.heappush(cards,bef+aft)
        print(cnt)
    cnt+=cards[0]
    return cnt
        
curr=grouping_cards(card_list)
print(curr)
print(card_list)
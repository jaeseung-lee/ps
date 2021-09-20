import sys
import heapq

T = int(sys.stdin.readline())
for t in range(T):
    k = int(sys.stdin.readline())
    q = []
    for k in range(k):
        a, b = map(str, sys.stdin.readline().split())
        b = int(b)
        if a == 'I':
            heapq.heappush(q, b)
        elif len(q) != 0:
            if b == -1:
                heapq.heappop(q)
            else:
                max_value = heapq.nlargest(1, q)
                q.remove(max_value[0])
    if len(q) == 0:
        print("EMPTY")
    elif len(q) == 1:
        ans = heapq.heappop(q)
        print(f"{ans} {ans}")
    else:
        M = heapq.nlargest(1, q)[0]
        m = heapq.heappop(q)
        print(f"{M} {m}")


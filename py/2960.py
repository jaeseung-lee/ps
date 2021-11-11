import sys

N, K = map(int, sys.stdin.readline().split())
numbers = list([False for _ in range(N + 1)])
for i in range(2, N+1):
    if not numbers[i]:
        j = 1
        while i * j <= N:
            if not numbers[i*j]:
                numbers[i*j] = True
                K = K - 1
                if K == 0:
                    print(i*j)
                    exit(0)
            j = j + 1

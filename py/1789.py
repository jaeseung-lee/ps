import sys

N = int(sys.stdin.readline())
count = 1
sum = 0
while True:
    if sum + count > N:
        break
    else:
        sum = sum + count
        count = count + 1
print(count-1)

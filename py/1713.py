import sys

N = int(sys.stdin.readline())
R = int(sys.stdin.readline())
num = list(map(int, sys.stdin.readline().split()))

pic = list([])
index = 0
for now in num:
    is_contained = False
    for element in pic:
        if element[0] == now:
            element[2] = element[2] + 1
            is_contained = True
            break
    if not is_contained:
        if len(pic) < N:
            pic.append([now, index, 1])
        else:
            target_index = 0
            for now_index in range(N):
                if pic[target_index][2] > pic[now_index][2]:
                    target_index = now_index
                elif pic[target_index][2] == pic[now_index][2] and pic[target_index][1] > pic[now_index][1]:
                    target_index = now_index
            pic[target_index] = [now, index, 1]
    index = index + 1
pic.sort()

for ans in pic:
    print(ans[0], end=' ')

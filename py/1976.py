import sys


N = int(sys.stdin.readline())

parent = list([])
for i in range(N):
    parent.append(i)


def find(target_index):
    parent_index = parent[target_index]
    if parent_index == target_index:
        return parent_index
    else:
        parent[target_index] = find(parent_index)
        return parent[target_index]


def union(index1, index2):
    parent1 = find(index1)
    parent2 = find(index2)
    if parent1 != parent2:
        if parent1 > parent2:
            parent[parent1] = parent2
        else:
            parent[parent2] = parent1


M = int(sys.stdin.readline())

edges = list([])
for i in range(N):
    edges.append(list(map(int, sys.stdin.readline().split())))

for i in range(N):
    for j in range(N):
        if edges[i][j] == 1:
            union(i, j)

target = list(map(int, sys.stdin.readline().split()))
is_answer = True
for i in range(1, len(target)):
    if parent[target[i]-1] != parent[target[i-1]-1]:
        is_answer = False
        break

if is_answer:
    print("YES")
else:
    print("NO")

import sys

N = list(map(int, sys.stdin.readline().split()))


def is_answer():
    global N
    index = 1
    for element in N:
        if element != index:
            return False
        else:
            index = index + 1
    return True


def print_N():
    global N
    for element in N:
        print(element, end=' ')
    print()


while not is_answer():
    for i in range(4):
        if N[i] > N[i+1]:
            temp = N[i]
            N[i] = N[i+1]
            N[i+1] = temp
            print_N()

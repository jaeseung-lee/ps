import sys

dir = list([(1, 0), (-1, 0), (0, -1), (0, 1),
           (1, 1), (-1, 1), (1, -1), (-1, -1)])
K, Q, N = map(str, sys.stdin.readline().split())
N = int(N)
K = (ord(K[0])-65, int(K[1]))
Q = (ord(Q[0])-65, int(Q[1]))


def is_valid_index(A):
    return 0 <= A[0] < 8 and 1 <= A[1] <= 8


def change_dir(dr, A):
    if dr == 'R\n':
        A = (A[0]+dir[0][0], A[1]+dir[0][1])
    elif dr == 'L\n':
        A = (A[0]+dir[1][0], A[1]+dir[1][1])
    elif dr == 'B\n':
        A = (A[0]+dir[2][0], A[1]+dir[2][1])
    elif dr == 'T\n':
        A = (A[0]+dir[3][0], A[1]+dir[3][1])
    elif dr == 'RT\n':
        A = (A[0]+dir[4][0], A[1]+dir[4][1])
    elif dr == 'LT\n':
        A = (A[0]+dir[5][0], A[1]+dir[5][1])
    elif dr == 'RB\n':
        A = (A[0]+dir[6][0], A[1]+dir[6][1])
    else:
        A = (A[0]+dir[7][0], A[1]+dir[7][1])
    return A


for _ in range(N):
    d = str(sys.stdin.readline())
    T_K = change_dir(d, K)
    if is_valid_index(T_K):
        if T_K == Q:
            T_Q = change_dir(d, Q)
            if is_valid_index(T_Q):
                Q = T_Q
                K = T_K
        else:
            K = T_K

K = chr(K[0] + 65) + str(K[1])
print(K)
Q = chr(Q[0] + 65) + str(Q[1])
print(Q)

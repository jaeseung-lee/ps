import sys


M, N, H = map(int, sys.stdin.readline().split())
tomato_list: list[list[list]] = []

for _ in range(H):
    temp_tomato_list: list[list] = []
    for _ in range(N):
        temp_tomato_list.append(list(map(int, sys.stdin.readline().split())))
    tomato_list.append(temp_tomato_list)


def is_valid_index(m: int, n: int, h: int):
    return (
        n >= 0
        and n < N
        and m >= 0
        and m < M
        and h >= 0
        and h < H
        and tomato_list[h][n][m] == 0
    )


def get_close_index_list(index_list: tuple[int, int, int]):
    m, n, h = index_list

    result: list[tuple[int, int, int]] = []

    if is_valid_index(m - 1, n, h):
        result.append((m - 1, n, h))

    if is_valid_index(m + 1, n, h):
        result.append((m + 1, n, h))

    if is_valid_index(m, n - 1, h):
        result.append((m, n - 1, h))

    if is_valid_index(m, n + 1, h):
        result.append((m, n + 1, h))

    if is_valid_index(m, n, h - 1):
        result.append((m, n, h - 1))

    if is_valid_index(m, n, h + 1):
        result.append((m, n, h + 1))

    return result


not_ripped_tomato = 0
target_tomato_list: list[tuple[int, int, int]] = []

for h, tomato_square in enumerate(tomato_list):
    for n, tomato_row in enumerate(tomato_square):
        for m, tomato in enumerate(tomato_row):
            if tomato == 1:
                target_tomato_list.append((m, n, h))
            if tomato == 0:
                not_ripped_tomato += 1

days = 0


while not_ripped_tomato > 0:
    num_ripped_tomato_in_now_step = 0
    next_target_tomato_list: list[tuple[int, int, int]] = []

    for target_tomato in target_tomato_list:
        # print("current : ", target_tomato)
        close_index_list = get_close_index_list(target_tomato)
        for close_index in close_index_list:
            m, n, h = close_index
            # print("m,n,h", m, n, h)
            if tomato_list[h][n][m] == 0:
                tomato_list[h][n][m] = 1
                num_ripped_tomato_in_now_step += 1
                next_target_tomato_list.append(close_index)

    # print("num_ripped_tomato_in_now_step", num_ripped_tomato_in_now_step)
    if num_ripped_tomato_in_now_step == 0:
        break

    not_ripped_tomato -= num_ripped_tomato_in_now_step
    days += 1
    target_tomato_list = next_target_tomato_list
    # print("not_ripped_tomato", not_ripped_tomato)

    # for tomato_square in tomato_list:
    #     for tomato_row in tomato_square:
    #         for tomato in tomato_row:
    #             print(tomato, end=" ")
    #         print()

if not_ripped_tomato == 0:
    print(days)
else:
    print(-1)

import sys


K = int(sys.stdin.readline())
move_pair_list: list[(int, int)] = []


def get_sanitized_number(source: int, swap_number_1: int, swap_number_2: int):
    if source == swap_number_1:
        return swap_number_2
    if source == swap_number_2:
        return swap_number_1
    return source


def get_swapped_list(
    pair_list: list[(int, int)], swap_number_1: int, swap_number_2: int
) -> list[(int, int)]:
    new_list: list[(int, int)] = []
    for source, destination in pair_list:
        new_list.append(
            (
                get_sanitized_number(source, swap_number_1, swap_number_2),
                get_sanitized_number(destination, swap_number_1, swap_number_2),
            )
        )
    return new_list


for index in range(K):
    swapped_2_3_list = get_swapped_list(move_pair_list, 2, 3)
    last_move_pair = [(1, 3)]
    swapped_1_2_list = get_swapped_list(move_pair_list, 1, 2)

    move_pair_list = swapped_2_3_list + last_move_pair + swapped_1_2_list

print(len(move_pair_list))
for answer_pair in move_pair_list:
    print(f"{answer_pair[0]} {answer_pair[1]}")

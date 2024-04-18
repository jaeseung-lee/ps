import sys


N = int(sys.stdin.readline())
star_list: list[list] = list([list([True for _ in range(N)]) for _ in range(N)])


def find_hole(square_width: int, x: int, y: int):
    return x + square_width // 3, y + square_width // 3


def find_holes(square_width: int):
    y = 0
    while y < N:
        x = 0
        while x < N:
            start_hole_x, start_hole_y = find_hole(square_width, x, y)
            # print(f"hole_x:{start_hole_x} hole_y:{start_hole_y}")
            for x_index in range(square_width // 3):
                for y_index in range(square_width // 3):
                    star_list[y_index + start_hole_y][x_index + start_hole_x] = False

            x += square_width
        y += square_width


square_width = 3
while square_width <= N:
    find_holes(square_width)
    square_width *= 3

for star_list_row in star_list:
    for star in star_list_row:
        if star:
            print("*", end="")
        else:
            print(" ", end="")
    print()

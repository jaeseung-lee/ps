import sys

N, K = map(int, sys.stdin.readline().split())

coin_list: list[int] = []
for _ in range(N):
    coin_list.append(int(sys.stdin.readline()))

num_method_to_make_coin_list: list[int] = [0 for _ in range(K + 1)]


def is_valid_index(index: int):
    return index >= 0


def is_valid_coin(coin: int):
    return coin >= 0


# num_method_to_make_coin_list[k] : coin_list의 n번째 동전을 사용하여 k를 만드는 가짓수
# num_method_to_make_coin_list[k] = num_method_to_make_coin_list[k-coin_list[n]] + num_method_to_make_coin_list[k] (n>0 and k-coin_list[n]>=0)
# num_method_to_make_coin_list[k] = num_method_to_make_coin_list[k-coin_list[n]] (n=0 and k-coin_list[n] >=0)
# num_method_to_make_coin_list[0] = 1 (n>=0)
num_method_to_make_coin_list[0] = 1

for index in range(N):
    target_coin = 1
    while target_coin <= K:
        if is_valid_coin(target_coin - coin_list[index]):
            num_method_to_make_coin_list[target_coin] += num_method_to_make_coin_list[
                target_coin - coin_list[index]
            ]

        target_coin += 1

print(num_method_to_make_coin_list[K])

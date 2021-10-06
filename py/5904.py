import sys

N = int(sys.stdin.readline())

MooLeng = list([0])
value = 3
index = 0
while True:
  MooLeng.append(value)
  if value >= N:
    N = N - MooLeng[index]
    break
  else:
    value = value * 2 + index + 4
    index = index + 1

while True:
  if 0 < N <= index + 3:
    if N == 1:
      print("m")
    else:
      print("o")
    break
  else:
    N = N - index - 3
    while index >= 0:
      if MooLeng[index] <= N:
        N = N - MooLeng[index]
        break
      else:
        index = index - 1

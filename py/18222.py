import sys

print(bin(int(sys.stdin.readline())-1).count('1')%2)

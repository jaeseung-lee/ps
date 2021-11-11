import sys

N = int(sys.stdin.readline())
ans = 0
for _ in range(N):
    word = str(sys.stdin.readline())
    is_answer = True
    alphabets = list([False for i in range(26)])
    prev_letter = '\n'
    for letter in word:
        if letter == '\n':
            break
        else:
            if not alphabets[ord(letter)-ord('a')]:
                alphabets[ord(letter)-ord('a')] = True
                prev_letter = letter
            elif prev_letter != letter:
                is_answer = False
                break
    if is_answer:
        ans = ans + 1
print(ans)

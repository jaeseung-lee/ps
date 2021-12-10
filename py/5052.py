import sys

t = int(sys.stdin.readline())

class Node:
  def __init__(self, key, count=0):
    self.key = key
    self.child = {}

class Trie:
  def __init__(self):
    self.head = Node(None)

  def insert(self, word):
    cur = self.head

    for ch in word:
      if ch not in cur.child:
        cur.child[ch] = Node(ch)
      cur = cur.child[ch]
      if '*' in cur.child:
        return False
    if len(cur.child) != 0:
        return False
    cur.child['*'] = True
    return True

for _ in range(t):
  trie = Trie()
  is_answer = True
  Words = list([])
  for n in range(int(sys.stdin.readline())):
    Words.append(str(sys.stdin.readline()).strip())
  for word in Words:
    if not trie.insert(word):
      is_answer = False
      break

  if is_answer:
    print("YES")
  else:
    print("NO")

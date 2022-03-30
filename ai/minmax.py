# Minmax tree

import math

class Tree:
    def __init__(self, val):
        self.left = None
        self.right = None
        self.step = 0 # 0 for min, 1 for max
        self.val = val
        self.a = math.inf
        self.b = -math.inf

vals = [Tree(int(i)) for i in input("Enter minmax vals:").split(" ")]

for i in vals: i.step=1

step = min
while len(vals) > 1:
    lst = []
    for i in range(0,len(vals),2):
        thing = Tree(step(vals[i].val, vals[i+1].val))
        thing.left = vals[i]
        thing.right = vals[i+1]
        thing.step = step == max
        lst.append(thing)
    step = min if step == max else max
    vals = lst

root = vals[0]

queue = []
v = []
def bfs(visited, node):
    visited.append(node)
    queue.append(node)
    curr = node.step
    while queue:
        m = queue.pop(0)
        # print(m.step)
        if curr != m.step:
            print("")
            curr = m.step
            
        print(m.val, end=" ")
        for n in [m.left, m.right]:
            if (n not in visited) and n:
                visited.append(n)
                queue.append(n)
    print()

bfs(v, root)

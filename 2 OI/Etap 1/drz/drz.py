class Node:
    def __init__(self, data=None, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

def do_tree(top, index = 0, new_data = 2):
    print(level_recording)
    for i in range(level_recording[index]):
        if rote.left == None:
            pass

if __name__ == "__main__":
    input()
    level_recording = [int(x) for x in input().split()]
    rote = Node(1)
    do_tree(rote)

'''
5
2 2 3 3 2
=
0 1 2 2 1 5 6 6 5 
((()())((()())()))

4
1 2 2 3 
=
NIE

5
2 3 3 2 2
=
0 1 2 2 4 4 1 7 7
((()(()()))(()()))
'''
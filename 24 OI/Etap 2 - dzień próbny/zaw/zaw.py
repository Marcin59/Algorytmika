from collections import defaultdict
from sys import setrecursionlimit

def find_loops(node, countries):
    global loops, visited
    visited.append(node)
    for position in countries[node]:
        possible_positions = positions[position]
        if len(possible_positions) == 1 and result[node-1] == 0:
            result[node-1] = position
        elif possible_positions[0] == node:
            if possible_positions[1] not in visited:
                find_loops(possible_positions[1], countries)
            else:
                loops += 1

def do_graph(i):
    global visited
    positions = defaultdict(list)
    countries = defaultdict(list)
    for j in range(1, i+1):
        input_data = input().split()
        if input_data[0] == 'T':
            result[j-1] = int(input_data[1])
            #visited.append(j)
        else:
            a, b = int(input_data[1]), int(input_data[2])
            countries[j].append(a)
            countries[j].append(b)
            positions[a].append(j)
            positions[b].append(j)
    return positions, countries

if __name__ == "__main__":
    setrecursionlimit(1000000000)
    n = int(input())
    result = [0 for x in range(n)]
    loops = 0
    visited = []
    positions, countries = do_graph(n)
    # print(visited)
    for i in range(1, n+1):
        if i not in visited:
            find_loops(i, countries)
    if loops == 0:
        print('TAK')
    else:
        print("NIE")
        print(2**loops)
'''
3
N 2 3
T 3
N 2 1

3
N 2 1
T 3
N 2 1

4
N 2 1
N 3 4
N 2 1
N 3 4

4
N 1 2
N 2 3
N 3 4
N 4 1
'''
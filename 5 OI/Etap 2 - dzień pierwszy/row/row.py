from collections import defaultdict
import sys

def count_the_trees(graph):
    result = 0
    visited = []
    for key in graph.copy():
        if key not in visited:
            visited.append(key)
            childs = graph[key]
            while childs:
                child = childs.pop()
                if child not in visited:
                    visited.append(child)
                    childs += graph[child]
            result += 1
    return result

def remove_the_root(key, graph):
    childs = graph[key]
    del graph[key]
    for child in childs:
        remove_the_root(child, graph)

def do_graph(left, right, graph):
    for i in range(len(left)):
        graph[left[i]].append(right[i])
        graph[right[i]].append(left[i])
    if '1' in graph:
        remove_the_root('1', graph)
    if '0' in graph:
        remove_the_root('0', graph)

def solve_the_equation():
    sys.setrecursionlimit(100000)
    variables = defaultdict(int)
    variables_number = int(input())
    for count, elem in enumerate(list(map(int, input().split()))):
        variables[alphabet[count]] = elem
    input()
    left_len = 0
    left_input = input()
    left = []
    for elem in left_input:
        if elem in zero_one:
            left_len += 1
            left.append(elem)
        else:
            left_len += variables[elem]
            for j in range(int(variables[elem])):
                left.append((elem, j))

    input()
    right_len = 0
    right_input = input()
    right = []
    for elem in right_input:
        if elem in zero_one:
            right_len += 1
            right.append(elem)
        else:
            right_len += variables[elem]
            for j in range(int(variables[elem])):
                right.append((elem, j))

    if left_len != right_len:
        print(0)
    else:
        graph = defaultdict(list)
        do_graph(left, right, graph)
        print(2**count_the_trees(graph))

if __name__ == "__main__":
    alphabet = list(x for x in 'abcdefghijklmnopqrstuvwxyz')
    zero_one = ['0', '1']
    equations = int(input())
    variables = defaultdict(int)
    for _ in range(equations):
        solve_the_equation()

'''
1
5
4 2 4 4 2
5
1bad1
4
acbe
=
16

1 
3
2 3 4
4
1ab0
2
bc
=
4

'''
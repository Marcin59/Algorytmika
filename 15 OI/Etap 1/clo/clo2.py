from collections import defaultdict
import sys

def DFS_with_assign(node, graph, visited):
    for child in graph[node].copy():
        if visited[child] == 0:
            graph[node].remove(child)
            graph[child].remove(node)
            result[child] = node
            visited[node] = 1
            DFS_with_assign(child, graph, visited)

def DFS(node, graph, root, parent = 0):
    for child in graph[node]:
        if child == parent:
            continue
        if child not in root:
            DFS(child, graph, root+[child], node)
        else:
            result[child] = node
            graph[node].remove(child)
            graph[child].remove(node)
            visited = defaultdict(lambda: 0)
            visited[child] = 0
            DFS_with_assign(child, graph, visited)

def do_graph():
    graph = defaultdict(list)
    for _ in range(roads):
        city1, city2 = list(map(int, input().split()))
        graph[city1].append(city2)
        graph[city2].append(city1)
    return graph

if __name__ == "__main__":
    cities, roads = list(map(int, input().split()))
    sys.setrecursionlimit(100000000)
    if roads < cities:
        print("NIE")
    else:
        print("TAK")
        graph = do_graph()
        result = [0 for x in range(cities+1)]
        for elem in range(1, cities):
            if result[elem] == 0:
                root = [elem]
                DFS(elem, graph, root)
        for elem in result[1:]:
            print(elem)

'''
4 5
1 2
2 3
1 3
3 4
1 4

=

TAK
3
3
4
1

10 13
1 2
2 3
3 4
4 5
5 6
6 7
1 7
1 8
3 9
5 10
8 9
9 10
8 10


4 4
1 2
3 4
1 3
2 4

'''
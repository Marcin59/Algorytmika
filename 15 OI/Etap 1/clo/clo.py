from collections import defaultdict
import sys

def BFS(node, graph):
    for child in graph[node]:
        if child not in visited:
            visited.append(child)
            BFS(child, graph)
        elif result[node-1] == 0:
            result[node-1] = child
            graph[node].remove(child)
            graph[child].remove(node)
        if len(graph[child]) == 1 and result[child-1] == 0:
            x = graph[child].pop()
            result[child-1] = x
            graph[x].remove(child)

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
        print(graph)
        visited = []
        result = [0 for x in range(cities)]
        for elem in graph.copy():
            if elem not in visited:
                visited.append(elem)
                BFS(elem, graph)
        for elem in result:
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
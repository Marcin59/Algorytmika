from collections import defaultdict

def DFS(visited, lenght, node):
    pass

def find_way():
    visited = set()
    lenght = 1
    DFS(visited, lenght, (1, 1))

def do_graph():
    graph = defaultdict(list)
    for i in range(1, n):
        for j in range(1, m):
            graph[(i, j)].append((i, j+1))
            graph[(i, j+1)].append((i, j))
            graph[(i, j)].append((i+1, j))
            graph[(i+1, j)].append((i, j))

    for i in range(1, n):
        graph[(i, m)].append((i+1, m))
        graph[(i+1, m)].append((i, m))

    for j in range(1, m):
        graph[(n, j)].append((n, j+1))
        graph[(n, j+1)].append((n, j))

    print(graph)

if __name__ == '__main__':
    n, m, k = list(map(int, input().split()))
    if n+m-2 <= k <= n*m-1:
        print('TAK')
        do_graph()
        find_way()
    else:
        print('NIE')
from collections import defaultdict

def check(v, k, parent):
    result = 0
    for elem in graph[v]:
        if elem != parent:
            result += check(elem, k, v) + 1
    return max(0, result-k)

if __name__ == '__main__':
    cities = int(input())
    graph = defaultdict(list)
    for _ in range(cities-1):
        a, b = list(map(int, input().split()))
        graph[a].append(b)
        graph[b].append(a)

    k = 0
    while True:
        if check(1, k, 0) == 0:
            break
        k += 1

    print(k)

'''
7
1 2
1 3
2 5
2 6
7 2
4 1

'''
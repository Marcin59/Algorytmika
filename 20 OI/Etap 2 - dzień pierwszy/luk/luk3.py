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

    max_builders = cities
    min_builders = 0

    while min_builders < max_builders:
        cent_builders = int((max_builders+min_builders)/2)

        if check(1, cent_builders, 0) == 0:
            max_builders = cent_builders

        else:
            min_builders = cent_builders+1
    if cities == 1:
        print(0)
    else:
        print(min_builders)


'''
7
1 2
1 3
2 5
2 6
7 2
4 1

'''
from collections import defaultdict
from sys import setrecursionlimit

def DFS(node, price, root):
    global min_price, min_price_root
    if graph[node]:
        new_node = root+[node]
        for child in graph[node]:
            DFS(child, price+prices[child], new_node)
    else:
        if price < min_price:
            min_price = price
            min_price_root = root

def find_fastest(node, root):
    if graph[node]:
        return find_fastest(graph[node][-1], root+[node])
    else:
        return root

if __name__ == "__main__":
    setrecursionlimit(10000000)
    lenght, hotels = list(map(int, input().split()))
    max_distance_to_travel = 800
    graph = defaultdict(list)
    prices = defaultdict(int)
    hotels_in_range = []
    for _ in range(hotels):
        distance, price = list(map(int, input().split()))
        prices[distance] = price

        if lenght - distance <= max_distance_to_travel:
            graph[distance].append(lenght)

        if len(hotels_in_range) == 0:
            hotels_in_range.append(distance)
            continue

        while hotels_in_range[0] < distance - max_distance_to_travel:
            hotels_in_range.pop(0)
            if len(hotels_in_range) == 0:
                hotels_in_range.append(distance)
                break

        for hotel in hotels_in_range:
            graph[hotel].append(distance)

        hotels_in_range.append(distance)

    min_price = float('inf')
    min_price_root = []
    n = 0
    for i in list(graph.keys()).copy():
        if i <= max_distance_to_travel:
            DFS(i, prices[i], [])
            n = i
        else:
            break
    fastest_root = find_fastest(n, [])
    print(*min_price_root)
    print(*fastest_root)
'''
2000 7
100 54
120 70
400 17
700 38
1000 25
1200 18
1440 40

'''
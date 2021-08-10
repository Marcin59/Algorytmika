from collections import defaultdict

if __name__ == "__main__":
    chambers, corridors, entrance, princess_chamber, s = list(map(int, input().split()))
    costs = [0] + list(map(int, input().split()))
    graph = defaultdict(list)
    for _ in range(corridors):
        a, b = list(map(int, input().split()))
        graph[a].append(b)
        graph[b].append(a)
    queue = [entrance]
    moneys = [costs[entrance]]
    ways = [[entrance]]
    result = False
    while queue and not result:
        print(queue)
        print(moneys)
        print(ways)
        chamber = queue.pop(0)
        money = moneys.pop(0)
        way = ways.pop(0)
        for elem in graph[chamber]:
            if money + costs[elem] < s:
                queue.append(elem)
                moneys.append(money + costs[elem])
                ways.append(way + [elem])
            elif money + costs[elem] == s and elem == princess_chamber:
                result = True
                break
    for i in way+[princess_chamber]:
        print(i, end=' ')
'''
5 6 3 4 9
1 2 3 4 5
2 4
5 4
1 5
1 2
2 3
3 1

'''

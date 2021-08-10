# Marcin Kapiszewski

from collections import defaultdict
from sys import setrecursionlimit
class Node:

    def __init__(self):
        self.parent = None
        self.childs = defaultdict(int)  # słownik w którym klucz to dziecko wierzchołka a wartość to waga boku

    def add_child(self, new_child, weight):
        self.childs[new_child] = weight

    def change_parent(self, new_parent):
        self.parent = new_parent

class Graph:

    def __init__(self):
        self.graph = [Node() for _ in range(n+1)]
        self.parent = None

    def add_side(self, a, b, weight):
        self.graph[a].childs[b] = weight
        self.graph[b].childs[a] = weight

    def repare_graph(self):
        for key in self.graph[1].childs.keys():
            self.dfs_fix(key, 1)

    def dfs_fix(self, node, parent):
        self.graph[node].childs.pop(parent)
        self.graph[node].parent = parent
        for key in self.graph[node].childs.keys():
            self.dfs_fix(key, node)

    def find_result(self, node):
        biciaki = set()
        parent = self.graph[node].parent
        while parent is not None:
            new_biciak = self.graph[parent].childs[node]
            if new_biciak not in biciaki:
                biciaki.add(new_biciak)
            node, parent = parent, self.graph[parent].parent
        return len(biciaki)

    def change_weight(self, way_number, new_weight):
        a, b = ways[way_number]
        if self.graph[a].parent == b:
            self.graph[b].childs[a] = new_weight
        else:
            self.graph[a].childs[b] = new_weight

if __name__ == "__main__":
    setrecursionlimit(100000000)
    n, m, z = list(map(int, input().split()))
    network_of_roads = Graph()
    ways = [0]
    for _ in range(n-1):
        a, b, c = list(map(int, input().split()))
        network_of_roads.add_side(a, b, c)
        ways.append([a, b])
    network_of_roads.repare_graph()

    for _ in range(z):
        data = input().split()
        if data[0] == 'Z':
            print(network_of_roads.find_result(int(data[1])))
        else:
            network_of_roads.change_weight(int(data[1]), int(data[2]))

'''
6 3 5
1 2 3
1 3 2
3 4 3
5 3 1
6 4 2
Z 5
Z 6
B 2 1
Z 5
Z 6

'''
from collections import defaultdict

class Metals:
    def __init__(self, price):
        self.price = price
        self.transformations = []
        self.transformations_prices = []

    def add_transformation(self, metal, transformation_price):
        self.transformations.append(metal)
        self.transformations_prices.append(transformation_price)

def BFS(metal_number, parent, actual_price):
    pass


if __name__ == '__main__':
    metals_number = int(input())
    metals = [0]
    for n in range(metals_number):
        metals.append(Metals(int(input())))
    processes_number = int(input())
    for _ in range(processes_number):
        a, b, transformation_price = list(map(int, input().split()))
        metals[a].add_transformation(b, transformation_price)

    minimum_cost = metals[1].price/2
    print(minimum_cost)
    print(metals)

'''
4
200
100
40
2
6
1 2 10
1 3 5
2 1 25
3 2 10
3 4 5
4 1 50

'''
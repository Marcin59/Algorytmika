
if __name__ == "__main__":
    max_fuel = int(input())
    numberOfStations = int(input())
    actual_distance = 0
    actual_index = 0
    new_index = 0
    prices = []
    distances = []
    for i in range(numberOfStations):
        price, distance = list(int(x) for x in input().split())
        prices.append(price)
        distances.append(distance)


'''
40
3
2 10
2 15
1 5

'''

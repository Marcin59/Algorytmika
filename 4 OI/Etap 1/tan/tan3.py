from collections import defaultdict
from sys import setrecursionlimit

if __name__ == "__main__":
    setrecursionlimit(10000000)
    lenght, hotels = list(map(int, input().split()))
    max_distance_to_travel = 800
    distances = []
    prices = []

    for _ in range(hotels):
        distance, price = list(map(int, input().split()))
        distances.append(distance)
        prices.append(price)
    distances.append(lenght)
    prices.append(0)

    min_prices = defaultdict(lambda: float('inf'))
    min_prices[lenght] = 0
    min_prices[distances[-1]] = prices[-1]
    min_price_root = defaultdict(int)
    fastest_root = defaultdict(int)
    # print(distances)
    # print(prices)

    for i in range(hotels+1, 0, -1):
        for j in range(i+1, hotels+1):
            if distances[i] + max_distance_to_travel >= distances[j]:
                if min_prices[distances[i]] > prices[i]+min_prices[distances[j]]:
                    min_prices[distances[i]] = prices[i] + min_prices[distances[j]]
                    min_price_root[distances[i]] = distances[j]

            else:
                break
            fastest_root[distances[i]] = distances[j]

    # print(min_prices)
    # print(min_price_root)
    # print(fastest_root)

    min_value = [float('inf'), 0]
    for key in list(min_prices.keys())[::-1]:
        if key <= max_distance_to_travel:
            if min_value[0] > min_prices[key]:
                min_value = [min_prices[key], key]
        else:
            break

    actual_distance = min_value[1]
    root = []
    while min_price_root[actual_distance]:
        root.append(actual_distance)
        actual_distance = min_price_root[actual_distance]
    print(*root)

    root = []
    actual_distance = distances[-1]
    i = hotels
    while True:
        while actual_distance - max_distance_to_travel <= distances[i] and i >= 0:
            i -= 1
        if i < 0:
            if actual_distance > max_distance_to_travel:
                root.append(distances[i + 1])
                break
            else:
                break
        actual_distance = distances[i + 1]
        root.append(actual_distance)

    print(*root[::-1])


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
if __name__ == "__main__":
    max_fuel = int(input())
    numberOfStations = int(input())
    prices = []
    actual_distance = 0
    for i in range(numberOfStations):
        price, distance = list(int(x) for x in input().split())
        for j in range(max_fuel):
            try:
                prices[actual_distance + j] = min(prices[actual_distance+j], price)
            except:
                prices.append(price)
        actual_distance += distance
    print(sum(prices[:actual_distance]))


def corect_boundaries():
    global price, rightDistance, rightOrders, leftDistance, leftOrders, leftCityIndex, rightCityIndex
    while rightDistance + distances[rightCityIndex] < leftDistance:
        price += orders[leftCityIndex] * (rightDistance + distances[rightCityIndex]) - orders[leftCityIndex] * leftDistance
        rightOrders += orders[leftCityIndex]
        leftOrders -= orders[leftCityIndex]
        rightDistance += distances[rightCityIndex]
        leftDistance -= distances[leftCityIndex]
        leftCityIndex = (leftCityIndex+1)%cities
        rightCityIndex = (rightCityIndex+1)%cities

if __name__ == "__main__":
    cities = int(input())
    orders = []
    distances = []
    for _ in range(cities):
        order, distance = list(map(int, input().split()))
        orders.append(order)
        distances.append(distance)

    actual_city = 0
    leftCities = 0
    leftCityIndex = 1
    leftDistance = 0
    leftOrders = 0
    rightCities = 0
    rightCityIndex = 0
    rightDistance = 0
    rightOrders = 0
    price = 0
    minimum_price = 0

    for i in range(cities-1, 0, -1):
        leftDistance += distances[i]
        leftOrders += orders[i]
        price += leftDistance*orders[i]
    minimum_price = price

    corect_boundaries()
    for i in range(1, cities):
        D = distances[i-1]
        price = price - rightOrders * D + (leftOrders + orders[i-1]) * D
        rightOrders -= orders[i]
        leftOrders += orders[i-1]
        rightDistance -= D
        leftDistance += D
        corect_boundaries()
        minimum_price = min(minimum_price, price)
    print(minimum_price)

'''
6
1 2
2 3
1 2
5 2
1 10
2 3


3 
1 1
1 1
1 1
'''
if __name__ == "__main__":
    distance, distance_to_taxi, taxis_number = list(map(int, input().split()))
    distance_from_taxi_to_end = distance - distance_to_taxi
    taxis = list(map(int, input().split()))
    taxis = sorted(taxis, reverse=True)
    taxis.append(0)
    result = 0
    last_taxi = 0
    for i in range(taxis_number):
        if taxis[i+1] >= distance_from_taxi_to_end or last_taxi != 0:
            if last_taxi >= distance_to_taxi*2 + distance_from_taxi_to_end:
                result += 1
                distance_to_taxi = 0
                break
            if taxis[i] > distance_to_taxi:
                result += 1
                distance_to_taxi -= taxis[i] - distance_to_taxi
            else:
                result = 0
                break
        else:
            last_taxi = taxis[i]

    print(result)

'''
42 23 6
20 25 14 27 30 7

'''
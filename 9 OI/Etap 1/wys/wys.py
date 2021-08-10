def corect_borders():
    global left_distance, right_distance, left_index, right_index
    while right_distance + distances[right_index] < left_distance:
        right_distance += distances[right_index]
        left_distance -= distances[right_index]
        right_index = (right_index+1)%cities
        left_index = (left_index+1)%cities
    if right_distance != 0 and left_distance != 0:
        return min(left_distance, right_distance)
    elif right_distance == 0:
        return left_distance
    else:
        return right_distance

if __name__ == '__main__':
    cities = int(input())
    distances = []
    left_distance = 0
    right_distance = 0
    actual_index = 0
    left_index = 1
    right_index = 0
    for _ in range(cities):
        distance = int(input())
        distances.append(distance)
        left_distance += distance

    max_distance = 0
    for index in range(cities):
        actual_max_distance = corect_borders()
        if actual_max_distance > max_distance:
            max_distance = actual_max_distance
        right_distance -= distances[actual_index]
        left_distance += distances[actual_index]
        actual_index += 1
    print(max_distance)
'''
5
1
2
3
4
5
'''
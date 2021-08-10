from collections import defaultdict
if __name__ == "__main__":
    lines_number, capital_residents = list(map(int, input().split()))
    capital_festival_cost = 0
    residents = defaultdict(list)
    residents_in_lines = defaultdict(int)
    all_residents = capital_residents
    distances = defaultdict(list)
    for line in range(lines_number):
        data = list(map(int, input().split()))
        locality = data.pop(0)
        actual_distance = 0
        for _ in range(locality):
            distance_to_next_city = data.pop(0)
            city_residents = data.pop(0)
            actual_distance += distance_to_next_city
            residents_in_lines[line] += city_residents
            distances[line].append(distance_to_next_city)
            residents[line].append(city_residents)
            capital_festival_cost += actual_distance * city_residents
        all_residents += residents_in_lines[line]

    min_cost_position = [0, 0]
    min_cost = capital_festival_cost

    for line in range(lines_number):
        actual_cost = capital_festival_cost
        R_residence = residents_in_lines[line]
        L_residence = all_residents - R_residence
        for count, distance in enumerate(distances[line]):
            actual_cost += (L_residence - R_residence)*distance
            if actual_cost < min_cost:
                min_cost = actual_cost
                min_cost_position = [line+1, count+1]
            L_residence += residents[line][count]
            R_residence -= residents[line][count]
    print(min_cost)
    print(*min_cost_position)

'''
3 12
2 2 3 2 3
3 3 2 2 0 2 3
3 3 4 1 3 2 3
= 
87
0 0

3 10
1 1 0
1 1 0
1 1 32
=
10
3 1

'''
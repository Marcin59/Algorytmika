if __name__ == '__main__':
    activities_number = int(input())
    times = [0 for x in range(activities_number+1)]
    activities = [[0, 0]]
    for _ in range(activities_number):
        activities.append(list(map(int, input().split())))

    activities.sort(key=lambda x: x[1])
    for count, activity in enumerate(activities[1:], 1):
        actual_activity_time = 1
        time_of_earlier_classes = next((j for j in range(count - 1, 0, -1)
                                        if activities[j][1] <= activity[0]),
                                       0)
        times[count] = max(times[count-1], times[time_of_earlier_classes]+activity[1]-activity[0])

    print(times[-1])
'''
12
1 2
3 5
0 4
6 8
7 13
4 6
9 10
9 12
11 14
15 19
14 16
18 20

'''

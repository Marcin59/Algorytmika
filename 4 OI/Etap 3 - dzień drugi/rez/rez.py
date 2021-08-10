if __name__ == '__main__':
    times = [0 for x in range(30000)]
    activities_number = int(input())
    activities = [[0, 0]]
    for _ in range(activities_number):
        activities.append(list(map(int, input().split())))

    activities.sort(key=lambda x: x[1])
    print(activities)
    for count, activity in enumerate(activities[1:], 1):
        actual_activity_time = 1
        time_of_earlier_classes = times[activities[next((j for j in range(count - 1, 0, -1)
                                                         if activities[j][1] < activity[0]),
                                                        0)][1]-1]
        print(activity)
        print(time_of_earlier_classes)
        #print(time_of_earlier_classes)
        for i in range(activity[0], activity[1]):
            times[i] = max(times[i - 1], time_of_earlier_classes + actual_activity_time)
            print(times[:30])
            actual_activity_time += 1
    #print(times)
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

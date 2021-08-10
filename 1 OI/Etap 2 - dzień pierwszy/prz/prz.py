import numpy as np

def check_time(graph, times):
    actions_times = dict(times)
    if all(graph[x].size > 0 for x in graph):
        return "CYKL"

    else:
        time = 0
        action_done = np.array([])

        while sum(list(actions_times.values())) != 0:

            time_work = min(time for action, time in actions_times.items() if
                            [x for x in graph[action] if x not in action_done] == [] and action not in action_done)

            for i in graph:
                if [x for x in graph[i] if x not in action_done] == [] and i not in action_done:
                    actions_times[i] -= time_work

            for i in graph:
                if actions_times[i] == 0 and i not in action_done:
                    action_done = np.append(action_done, [i])

            time += time_work
    return time

if __name__ == '__main__':

    data_number = int(input())
    actions_graph = {}
    times = {}

    for i in range(data_number):
        action = [int(x) for x in input().split()]

        actions_graph[i+1] = np.array([])

        for previous_action in action[2:]:
            actions_graph[i+1] = np.append(actions_graph[i+1], previous_action)

        times[i + 1] = action[0]
    project_time = check_time(actions_graph, times)
    print(project_time)
    data_number = int(input())

    for _ in range(data_number):
        if project_time != 'CYKL':
            times_after_change = dict(times)
            data = [int(x) for x in input().split()]
            action_to_change, time_after_change = data
            times_after_change[action_to_change] += time_after_change
            if project_time != check_time(actions_graph, times_after_change):
                print("TAK")
            else:
                print("NIE")

'''
4
1 1 3
1 1 1
2 2 1 2
1 1 3
2
2 1
3 2
=
CYKL

6
1 0
1 2 1 6
5 2 5 4
5 0
4 1 1
2 1 4
6
4 1
2 1
6 2
1 1
2 3
6 3
= 
10
TAK
NIE
NIE
TAK
TAK
TAK
'''
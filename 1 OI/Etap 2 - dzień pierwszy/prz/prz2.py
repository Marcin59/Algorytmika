import numpy as np

if __name__ == '__main__':

    data_number = int(input())
    actions_graph = {}
    times = []

    for i in range(data_number):
        action = [int(x) for x in input().split()]

        actions_graph[i+1] = np.array([])

        for previous_action in action[2:]:
            actions_graph[i+1] = np.append(actions_graph[i+1], previous_action)

        times.append(action[0])

    print(actions_graph, times)
    periodicity = None

    if all(len(x) > 0 for x in actions_graph.values()):
        periodicity = True
        print('CYKL')

    if periodicity != True:
        pass






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
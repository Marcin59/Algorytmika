next_direction = {'u': 'r', 'r': 'd', 'd': 'l', 'l': 'u'}

straight = {'u': [-1, 0], 'r': [0, 1], 'd': [1, 0], 'l': [0, -1]}

if __name__ == '__main__':
    number_rows, number_columns = [int(x) for x in input().split()]
    matrix = []
    for i in range(number_rows):
        matrix.append([])
        row = input()
        for j in range(len(row)):
            matrix[i].append(row[j])

    A = [int(x) - 1 for x in input().split()]
    B = [int(x) - 1 for x in input().split()]
    queue = [['u', [A[0] - 1, A[1]]], ['r', [A[0], A[1] + 1]], ['d', [A[0] + 1, A[1]]], ['l', [A[0], A[1] - 1]]]
    ways = [[[A[0], A[1]], [A[0] - 1, A[1]]], [[A[0], A[1]], [A[0], A[1] + 1]], [[A[0], A[1]], [A[0] + 1, A[1]]],
            [[A[0], A[1]], [A[0], A[1] - 1]]]
    visited_elems = []
    while queue:
        data = queue.pop(0)
        way = ways.pop(0)
        if data not in visited_elems:
            visited_elems.append(data)
        else:
            continue
        if data[1] == B:
            break
        if 0 <= data[1][0] < number_rows and 0 <= data[1][1] < number_columns and \
                matrix[data[1][0]][data[1][1]] == '0':
            queue.append([data[0], [data[1][0] + straight[data[0]][0], data[1][1] + straight[data[0]][1]]])
            ways.append(way + [[data[1][0] + straight[data[0]][0], data[1][1] + straight[data[0]][1]]])
            queue.append([next_direction[data[0]], [data[1][0] + straight[next_direction[data[0]]][0],
                                                    data[1][1] + straight[next_direction[data[0]]][1]]])
            ways.append(way + [[data[1][0] + straight[next_direction[data[0]]][0],
                                data[1][1] + straight[next_direction[data[0]]][1]]])

    if queue:
        print(len(way))
        for elem in way:
            print(elem[0] + 1, elem[1] + 1)
    else:
        print('NIE')

'''
8 9
010011101
011010101
000000000
111010101
101000100
111010101
000000000
101011111
2 6
1 3
=
NIE

8 9
010011101
011010101
000000000
111010101
101000100
111010101
000000000
101011111
2 6
3 8
=
12
2 6
3 6
4 6
5 6
5 5
5 4
4 4
3 4
3 5
3 6
3 7
3 8


'''

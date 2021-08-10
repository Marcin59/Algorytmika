def MaxMin(data):
    max_list = []
    min_list = []

    for i in range(0, len(data)-1, 2):
        if data[i] > data[i+1]:
            max_list.append(data[i])
            min_list.append(data[i+1])
        else:
            max_list.append(data[i+1])
            min_list.append(data[i])

    max = max_list[0]
    min = min_list[0]
    for i in max_list[1:]:
        if i > max:
            max = i

    for i in min_list[1:]:
        if i < min:
            min = i

    if len(data) % 2:
        if data[-1] > max:
            max = data[-1]

        elif data[-1] < min:
            min = data[-1]

    print('min = {}, max = {}'.format(min, max))

if __name__ == '__main__':
    data = [1, 12, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, -1]
    MaxMin(data)
# Marcin Kapiszewski

from collections import defaultdict

def find_minimum_different(data_cos):
    differences = []

    for i in range(n):
        if data_cos != shelfs_type[i]:
            if shelfs_types_number[shelfs_type[i]] != 1:
                number = shelfs[shelfs_type[i]][i] - shelfs[data_cos][i]
                differences.append([number, i])
            else:
                number = shelfs[shelfs_type[i]][i] - shelfs[data_cos][i] + find_minimum_different(shelfs_type[i])[0][0]
                differences.append([number, i])

    differences.sort(key=lambda k: k[0])

    return differences

if __name__ == "__main__":
    n = int(input())
    result = 0
    shelfs_types_which_are = set()
    shelfs_type = []
    shelfs_types_number = defaultdict(int)
    shelfs = defaultdict(list)
    buns = False
    donuts = False
    croissants = False

    for _ in range(n):
        data = list(map(int, input().split()))
        shelfs['d'].append(data[0])
        if data[0] != 0:
            buns = True
        shelfs['p'].append(data[1])
        if data[1] != 0:
            donuts = True
        shelfs['r'].append(data[2])
        if data[2] != 0:
            croissants = True
        data[0] = [data[0], 'd']
        data[1] = [data[1], 'p']
        data[2] = [data[2], 'r']
        data.sort(key=lambda k: k[0])
        result += data[0][0] + data[1][0]
        shelf_type = data[2][1]
        shelfs_types_which_are.add(shelf_type)
        shelfs_type.append(shelf_type)
        shelfs_types_number[shelf_type] += 1

    if buns and 'd' not in shelfs_types_which_are:
        buns = find_minimum_different('d')
    else:
        buns = []
    if donuts and 'p' not in shelfs_types_which_are:
        donuts = find_minimum_different('p')
    else:
        donuts = []
    if croissants and 'r' not in shelfs_types_which_are:
        croissants = find_minimum_different('r')
    else:
        croissants = []

    if buns:
        if donuts:
            if buns[0][1] != donuts[0][1]:
                result += buns[0][0] + donuts[0][0]
            else:
                result += min(buns[1][0] + donuts[0][0], buns[0][0] + donuts[1][0])
        elif croissants:
            if buns[0][1] != croissants[0][1]:
                result += buns[0][0] + croissants[0][0]
            else:
                result += min(buns[1][0] + croissants[0][0], buns[0][0] + croissants[1][0])
        else:
            result += buns[0][0]
    elif donuts:
        if croissants:
            if donuts[0][1] != croissants[0][1]:
                result += donuts[0][0] + croissants[0][0]
            else:
                result += min(croissants[1][0] + donuts[0][0], croissants[0][0] + donuts[1][0])
        else:
            result += donuts[0][0]
    elif croissants:
        result += croissants[0][0]

    print(result)

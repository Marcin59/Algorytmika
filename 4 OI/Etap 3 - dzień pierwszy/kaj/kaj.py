if __name__ == '__main__':
    max_weight = int(input())
    participants = int(input())
    weights = []
    for _ in range(participants):
        weight = int(input())
        weights.append(weight)
    weights = sorted(weights)
    result = 0
    while len(weights) > 1:
        if weights[0] + weights[-1] <= max_weight:
            weights.pop(0)
            weights.pop()
        else:
            weights.pop()
        result += 1
    if weights:
        print(result+1)
    else:
        print(result)

'''
100
9
90
20
20
30
50
60
70
80
90

'''
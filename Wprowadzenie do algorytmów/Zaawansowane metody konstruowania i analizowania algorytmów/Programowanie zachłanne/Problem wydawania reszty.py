def calculate_change(amount, denominations):
    n = 0
    result = []
    while amount > 0:
        if denominations[n] <= amount:
            amount -= denominations[n]
            result.append(denominations[n])
        else:
            n += 1
    return result

if __name__ == '__main__':
    denominations = [5, 3, 1]
    k = calculate_change(132, denominations)
    print(k)
    print(sum(k))
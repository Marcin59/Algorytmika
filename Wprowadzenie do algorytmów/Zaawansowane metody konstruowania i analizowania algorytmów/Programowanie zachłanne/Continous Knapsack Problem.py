def knapSack(knapsack_weight, wt, val):
    wt, val = (list(x)[::-1] for x in zip(*sorted(zip(wt, val), key=lambda x: x[1]/x[0])))
    print(wt, val)
    result = 0
    for i in range(len(wt)):
        if wt[i] <= knapsack_weight:
            result += val[i]
            knapsack_weight -= wt[i]
        else:
            result += val[i] * knapsack_weight/wt[i]
            break
    return result

if __name__ == '__main__':
    val = [60, 100, 120]
    wt = [10, 20, 30]
    W = 50
    n = len(val)
    print(knapSack(W, wt, val))
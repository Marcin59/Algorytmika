'''

Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of minimum cost
path to reach (m, n) from (0, 0). Each cell of the matrix represents a cost to traverse through that cell. Total cost
of a path to reach (m, n) is sum of all the costs on that path (including both source and destination). You can only
traverse down, right and diagonally lower cells from a given cell, i.e., from a given cell (i, j), cells (i+1, j),
(i, j+1) and (i+1, j+1) can be traversed. You may assume that all costs are positive integers.

'''

def min_cost(costs):

    m = len(costs[0])
    n = len(costs)

    for i in range(1, m):
        costs[0][i] += costs[0][i-1]

    for i in range(1, n):
        costs[i][0] += costs[i-1][0]

    for i in range(1, len(costs[0])):
        for j in range(1, len(costs)):

            costs[i][j] += min(costs[i-1][j],
                                costs[i][j-1],
                                costs[i-1][j-1])
    print(costs)
    return costs[-1][-1]

if __name__ == '__main__':
    costs = [[1, 2, 3],
            [4, 8, 2],
            [1, 5, 3]]
    result = min_cost(costs)
    print(result)
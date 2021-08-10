# Marcin Kapiszewski

def change_rectable(array, i1, j1, i2, j2):
    for i in range(i1-1, i2):
        for j in range(j1-1, j2):
            if array[i][j] == 0:
                array[i][j] = 1
            else:
                array[i][j] = 0

def find_minimum_simple_operations():
    array_copy = [i.copy() for i in original_array]
    result = 0
    for i in range(n-1, -1, -1):
        for j in range(m-1, -1, -1):
            if array_copy[i][j] == 1:
                result += 1
                change_rectable(array_copy, 1, 1, i+1, j+1)

    return result

if __name__ == "__main__":
    n, m, q = list(map(int, input().split()))
    original_array = [[0 for i in range(m)] for j in range(n)]
    for _ in range(q):
        data = list(map(int, input().split()))
        change_rectable(original_array, *data)
        result = find_minimum_simple_operations()
        print(result)
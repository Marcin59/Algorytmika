matrixes = [[[1, 0, 0, 0],
      [0, 1, 0, 0],
      [1, 1, 3, 1],
      [0, 0, 0, 1]],
     [[1, 1, 0, 0],
      [0, 0, 0, 0],
      [0, 1, 1, 0],
      [1, 0, 1, 3]],
     [[3, 1, 1, 1],
      [0, 1, 0, 0],
      [0, 0, 1, 0],
      [0, 0, 0, 1]],
     [[1, 0, 0, 1],
      [1, 3, 1, 0],
      [0, 0, 1, 1],
      [0, 0, 0, 0]]]

def find_co_ordinanse(dimension, x, y, result):
    if dimension < 1:
        return result

    if x >= dimension:
        if y >= dimension:
            return find_co_ordinanse(dimension/2, x-dimension, y-dimension, result+[1])
        else:
            return find_co_ordinanse(dimension / 2, x - dimension, y, result + [2])
    else:
        if y >= dimension:
            return find_co_ordinanse(dimension/2, x, y-dimension, result+[4])
        else:
            return find_co_ordinanse(dimension / 2, x, y, result + [3])

def multiply(vector, matrix):

    result = []
    for i in range(4):
        result.append(0)
        for j in range(4):
            result[i] += vector[j]*matrix[j][i]

    return result

if __name__ == '__main__':
    n = int(input())
    x = int(input())
    y = int(input())
    dimension = 2**(n-1)
    co_ordinanse = find_co_ordinanse(dimension, x, y, [])
    v = [1, 0, 0, 0]
    for t in range(n):
        i = co_ordinanse[t]
        v = multiply(v, matrixes[i-1])
    print(v[0])

'''
2
2
2

'''
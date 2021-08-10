def find_longest_increasing_sub(arr):
    longest_subsequnces = [1]*n

    for i in range(1, n):
        for j in range(i):
            if arr[i] > arr[j] and longest_subsequnces[i] < longest_subsequnces[j] + 1:
                longest_subsequnces[i] = longest_subsequnces[j] + 1

    return max(longest_subsequnces)

if __name__ == '__main__':
    arr = [10, 22, 9, 33, 21, 50, 41, 60]
    n = len(arr)
    result = find_longest_increasing_sub(arr)
    print(result)
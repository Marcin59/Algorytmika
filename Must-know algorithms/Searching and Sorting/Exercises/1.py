'''

Find the Minimum length Unsorted Subarray, sorting which makes the complete array sorted

'''

def find_boundaries(arr):
    s = 0
    e = len(arr)-1
    for i in range(1, len(arr)):
        if arr[i] < arr[i-1]:
            break
        else:
            s += 1

    if s != len(arr)-1:
        for i in range(len(arr)-1, 0, -1):
            if arr[i] < arr[i - 1]:
                break
            else:
                e -= 1
    return s, e

def find_min_and_max_value(arr):
    min = float('inf')
    max = -float('inf')
    for i in range(0, len(arr)-1, 2):
        if arr[i] > arr[i+1]:
            smaller = arr[i+1]
            bigger = arr[i]
        else:
            smaller = arr[i]
            bigger = arr[i+1]
        if min > smaller:
            min = smaller
        if max < bigger:
            max = bigger

    if len(arr) % 2:
        if arr[-1] > max:
            max = arr[-1]
        if arr[-1] < min:
            min = arr[-1]

    return min, max

def find_min_unsorted_arr(arr):
    s, e = find_boundaries(arr)
    min, max = find_min_and_max_value(arr[s:e+1])

    for i in range(s):
        if arr[i] > min:
            s = i
            break

    for i in range(len(arr)-1, e-1, -1):
        if arr[i] < max:
            e = i
            break

    return s, e

if __name__ == '__main__':
    arr1 = [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60]
    arr2 = [1, 2, 3, 4, 5, 6]
    arr3 = [1, 2, 2, 3, 2, 2, 2, 2, 1, 1, 1]

    print(find_min_unsorted_arr(arr2))
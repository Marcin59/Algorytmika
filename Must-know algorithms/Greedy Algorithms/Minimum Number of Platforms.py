def find_minimum_number_of_platforms(arr, dep):
    i = j = 0
    n = len(arr)
    arr.sort()
    dep.sort()
    result = 0
    while i < n and j < n:
        print(i, j)
        if arr[i] > dep[j]:
            j += 1
        else:
            i += 1
        result = max(result, i-j)
    return result

if __name__ == "__main__":
    arr = [900, 940, 950, 1100, 1500, 1800]
    dep = [910, 1200, 1120, 1130, 1900, 2000]

    result = find_minimum_number_of_platforms(arr, dep)
    print(result)
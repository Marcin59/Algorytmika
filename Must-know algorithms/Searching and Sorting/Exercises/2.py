'''

Find the closest pair from two sorted arrays

'''

if __name__ == '__main__':
    number = 38
    arr1 = [1, 4, 5, 7]
    arr2 = [10, 20, 30, 40]
    lenght_arr1 = len(arr1)
    lenght_arr2 = len(arr2)

    arr1_index = 0
    arr2_index = lenght_arr2-1
    n = arr1[arr1_index] + arr2[arr2_index]
    dif = abs(n - number)
    result = (0, 0)

    while arr1_index < lenght_arr1 and arr2_index >= 0:
        n = arr1[arr1_index] + arr2[arr2_index] - number

        if abs(n) < dif:
            dif = abs(n)
            result = (arr1_index, arr2_index)

        if n > 0:
            arr2_index -= 1
        else:
            arr1_index += 1
    print(result)
    print(arr1[result[0]], arr2[result[1]])
def partition(A, start, end):
    partition_number = A[end]
    i = start - 1
    for j in range(start, end):
        if A[j] <= partition_number:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i + 1], A[end] = A[end], A[i + 1]
    return i+1

def quichsort(A, start, end):
    if start < end:
        partition_index = partition(A, start, end)
        quichsort(A, start, partition_index - 1)
        quichsort(A, partition_index + 1, end)

if __name__ == "__main__":
    data = [2, 8, 7, 1, 3, 5, 6, 4, 11, 9, 10, 12, 15, 14, 13]
    quichsort(data, 0, len(data)-1)
    print(data)
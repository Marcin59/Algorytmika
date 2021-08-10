def parent(index):
    return int(index/2 - 0.5)

def left(index):
    return index*2 + 1

def right(index):
    return index*2 + 2

def min_heapify(data, index):
    l = left(index)
    r = right(index)
    if l < heap_size and data[l] < data[index]:
        largest = l
    else:
        largest = index
    if r < heap_size and data[r] < data[largest]:
        largest = r
    if largest != index:
        data[index], data[largest] = data[largest], data[index]
        min_heapify(data, largest)

def build_max_heap(data):
    partition = int(len(data)/2-1)
    for i in range(partition, -1, -1):
        print(data)
        min_heapify(data, i)
    print(data)

def heapsort(A):
    global heap_size
    build_max_heap(A)
    for i in range(len(data)-1, 0, -1):
        data[0], data[i] = data[i], data[0]
        heap_size -= 1
        min_heapify(data, 0)


if __name__ == "__main__":
    data = [4, 1, 3, 2, 16, 9, 10, 14, 8, 7]
    heap_size = len(data)
    heapsort(data)
    print(data)
def BubbleSort(data):
    Kres= len(data) - 1
    while Kres > 0:
        k = 0
        for i in range(Kres):
            if data[i] > data[i + 1]:
                data[i], data[i+1] = data[i + 1], data[i]
                k = i
        Kres = k
    print(data)

if __name__ == '__main__':
    data = [2, 1, 3, 4, 1, 5, 1]
    BubbleSort(data)
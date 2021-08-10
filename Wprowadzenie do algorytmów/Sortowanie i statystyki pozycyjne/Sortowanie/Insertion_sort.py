def sort(data):
    result = [data[0]]
    for i in range(1, len(data)):
        key = data[i]
        result.append(key)
        j = i - 1
        while j > 0 and result[j] > key:
            result[j + 1] = result[j]
            j = j - 1
        result[j + 1] = key
    return result

if __name__ == "__main__":
    print(sort([1,2,2,1,4,3,3,2]))
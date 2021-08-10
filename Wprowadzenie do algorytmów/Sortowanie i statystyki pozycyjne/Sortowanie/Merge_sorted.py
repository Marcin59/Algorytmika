from math import inf

def merge(data, start, partition, stop):
    L = data[start:partition]
    R = data[partition:stop]
    L.append(inf)
    R.append(inf)
    L_index = 0
    R_index = 0
    for i in range(start, stop):
        if L[L_index] <= R[R_index]:
            data[i] = L[L_index]
            L_index += 1
        else:
            data[i] = R[R_index]
            R_index += 1

def merge_sort(data, start = None, stop = None):
    if start == None:
        start = 0
    if stop == None:
        stop = len(data)
    if start + 1 < stop:
        partition = int((start + stop)/2)
        merge_sort(data, start, partition)
        merge_sort(data, partition, stop)
        #print("data: {}, start: {}, partition:{}, stop:{}".format(data, start, partition, stop))
        merge(data, start, partition, stop)
    return data

if __name__ == "__main__":
    print(merge_sort([4,1,2,3,3,3,2]))
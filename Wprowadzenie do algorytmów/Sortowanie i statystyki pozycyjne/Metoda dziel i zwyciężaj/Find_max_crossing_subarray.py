from math import inf

def find_max_crossing_subarray(data, low, mid, high):
    left_sum = -inf
    right_sum = -inf
    max_left = 0
    max_right = 0
    sum = 0
    for i in range(mid, low-1, -1):
        sum += data[i]
        if sum > left_sum:
            left_sum = sum
            max_left = i
    sum = 0
    for i in range(mid+1, high):
        sum += data[i]
        if sum > right_sum:
            right_sum = sum
            max_right = i

    return max_left, max_right, left_sum + right_sum

def find_maximum_subarray(data, low = 0, high = None):
    print('data:{}, low:{}, high:{}'.format(data, low, high))
    if high == None:
        high = len(data)
    if low == high:
        return low, high, data[low-1]
    else:
        mid = int((high + low) / 2)
        left_low, left_high, left_sum = find_maximum_subarray(data, low, mid)
        right_low, right_high, right_sum = find_maximum_subarray(data, mid+1, high)
        cross_low, cross_high, cross_sum = find_max_crossing_subarray(data, low, mid, high)
    if left_sum >= right_sum and left_sum >= cross_sum:
        return left_low, left_high, left_sum
    elif right_sum >= left_sum and right_sum >= cross_sum:
        return right_low, right_high, right_sum
    else:
        return cross_low, cross_high, cross_sum

if __name__ == "__main__":
    data = [1, 3, 2, 4, 12, 1, 1, -10, 21]
    print(find_maximum_subarray(data))

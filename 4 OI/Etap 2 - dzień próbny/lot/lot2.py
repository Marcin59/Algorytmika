from collections import defaultdict


if __name__ == "__main__":
    airports = int(input())
    bandwidth = defaultdict(int)
    for i in range(1, airports + 1):
        data = int(input())
        bandwidth[i] = data
    sorted_bandwidth = sorted(bandwidth.items(), key=lambda kv: kv[1], reverse=True)
    while sorted_bandwidth[0][1] != 0:
        for i in range(1, sorted_bandwidth[0][1]+1):
            bandwidth[sorted_bandwidth[i][0]] -= 1
            print(sorted_bandwidth[0][0], sorted_bandwidth[i][0])
        bandwidth[sorted_bandwidth[0][0]] = 0
        sorted_bandwidth = sorted(bandwidth.items(), key=lambda kv: kv[1], reverse=True)

'''
6
2
3
2
4
1
2


'''
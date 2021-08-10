from collections import defaultdict

if __name__ == '__main__':
    airports = int(input())
    bandwidth = defaultdict(int)
    free_connections = []
    for i in range(1, airports+1):
        data = int(input())
        bandwidth[i] = data

    sorted_bandwidth = sorted(bandwidth.items(), key=lambda kv: kv[1], reverse=True)
    the_list = [x[0] for x in sorted_bandwidth]

    for i in the_list:
        if bandwidth[i] > 0:
            free_connections.append(i)

    for airport in the_list:
        items_to_del = []
        for i in free_connections.copy():
            if i == airport:
                continue
            if bandwidth[airport] == 0:
                try:
                    free_connections.remove(airport)
                    break
                except:
                    pass
            if bandwidth[i] > 0:
                bandwidth[i] -= 1
                bandwidth[airport] -= 1
                print(airport, i)
            else:
                free_connections.remove(i)

'''
6
2
3
2
4
1
2


'''
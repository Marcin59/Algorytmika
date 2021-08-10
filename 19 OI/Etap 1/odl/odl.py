from collections import defaultdict
from sys import setrecursionlimit


def do_graph(prime_numbers):
    queue = [1]
    graph = defaultdict(list)
    while queue:
        actual_number = queue.pop(0)
        for number in prime_numbers:
            next_elem = actual_number * number
            if next_elem <= max_number:
                graph[actual_number].append(next_elem)
                graph[next_elem].append(actual_number)
                queue.append(next_elem)
            else:
                continue
    return graph


def co_to_niby_ma_byc(ds, ms):
    dsv = defaultdict(int)
    msv = defaultdict(lambda: float('inf'))

    for v in numbers:
        dsv[v] = float('inf')
        #msv[v] = v

    # print(graph)
    for v in range(max_number + 1):
        for child in graph[v]:
            v_prim = ms[v]
            w_prim = ms[child]
            #print(v, w)

            if v_prim != w_prim:
                d = ds[v] + 1 + ds[child]
                if d <= dsv[v_prim] or (d == dsv[v_prim] and w_prim < msv[v_prim]):
                    dsv[v_prim] = d
                    msv[v_prim] = w_prim

    for number in numbers:
        print(numbers.index(msv[number]))
    return msv


def find_closest_numbers():
    Q = list()
    ds = defaultdict(list)
    ms = defaultdict(list)
    for v in graph.keys():
        ds[v] = float('inf')
    for v in numbers:
        ds[v] = 0
        ms[v] = v
        Q.append(v)

    while Q:
        v = Q.pop(0)
        for child in graph[v]:
            if ds[child] == float('inf'):
                ds[child] = ds[v] + 1
                ms[child] = ms[v]
                Q.append(child)
            elif ds[v] + 1 == ds[child] and ms[v] < ms[child]:
                ms[child] = ms[v]

    msv = co_to_niby_ma_byc(ds, ms)
    print(msv)

    return [msv[x] for x in numbers]


if __name__ == '__main__':
    setrecursionlimit(1000000000)
    primes = lambda l: l and l[:1] + primes([n for n in l if n % l[0]])
    elem_number = int(input())
    max_number = 0
    numbers = []
    for i in range(elem_number):
        input_data = int(input())
        if input_data > max_number:
            max_number = input_data
        numbers.append(input_data)
    prime_numbers = primes(list(range(2, max_number + 1)))
    # print(prime_numbers)
    graph = do_graph(prime_numbers)
    print(graph)
    # print(graph)
    closest_numbers = find_closest_numbers()
    print(closest_numbers)

'''
7
1
2
3
4
5
6
7

'''

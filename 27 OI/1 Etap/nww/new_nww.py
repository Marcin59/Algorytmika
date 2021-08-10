from collections import defaultdict

def nwd(a, b):
    if b > 0:
        return nwd(b, a%b)
    return a

def nww(a, b): return a*b//nwd(a, b)

def find_all_NWW():
    results = defaultdict(lambda k=0:k)

    for i in range(1, 10**6):
        results[nww(i, nww(i+1, i+2))] = (i, i+2)

    for i in range(1, 10**5):
        results[nww(nww(i, nww(i+1, i+2)), i+3)] = (i, i+3)

    for i in range(1, 10**4):
        results[nww(nww(nww(i, nww(i+1, i+2)), i+3), i+4)] = (i, i+4)

    for k in range(6, 18):
        for a in range(1, 100):
            new_result = a
            for i in range(a+1, a+k):
                new_result = nww(new_result, i)
            results[new_result] = (a, a+k)

    for k in range(18, 40):
        for a in range(1, 10):
            new_result = a
            for i in range(a+1, a+k):
                new_result = nww(new_result, i)
            results[new_result] = (a, a+k)

    return results


if __name__ == "__main__":
    n = int(input())
    NWWs = find_all_NWW()
    for i in range(n):
        data = NWWs[int(input())]
        if data == 0:
            print("NIE")
        else:
            print(data[0], data[1])


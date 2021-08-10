from collections import defaultdict

class KeyDict(defaultdict):
    def __missing__(self, key):
        return key

def nwd(a, b):
    if b > 0:
        return nwd(b, a%b)
    return a

def nww(a, b): return a*b//nwd(a, b)

def NWW(array):
    actual_nww = array[0]
    for elem in array[1:]:
        actual_nww = nww(actual_nww, elem)
    return actual_nww

def find_all_NWW():
    NWWs = defaultdict(KeyDict)
    for k in range(3, 51):
        print(k)
        for a in range(cases[k]):
            NWWs[a][a+k-1] = nww(NWWs[a][a+k-2], a+k-1)
    return NWWs

def find_answer(number):
    results = []
    for k in range(3, 51):
        print(k)
        for a in range(cases[k]):
            if NWW(list(range(a, a+k-1))) == number:
                results.append((a, a+k-2))
    print(results)

if __name__ == "__main__":
    n = int(input())
    cases = defaultdict(lambda k=1000: k)
    cases[3] = 200000
    cases[4] = 100000
    cases[5] = 50000
    cases[6] = 20000
    cases[7] = 10000
    NWWs = find_all_NWW()
    print(NWWs[9][12])
    for i in range(n):
        print(find_answer(int(input())))
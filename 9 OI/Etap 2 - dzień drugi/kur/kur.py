from collections import defaultdict

if __name__ == "__main__":
    glades, lower_glades = list(map(int, input().split()))

    ski_runs_number = int(input())
    ski_runs = defaultdict(list)
    for _ in range(ski_runs_number):
        a, b = list(map(int, input().split()))
        ski_runs[a].append(b)

    ski_lifts_number = int(input())
    ski_lifts = defaultdict(list)
    for _ in range(ski_lifts_number):
        a, b, price = list(map(int, input().split()))
        ski_lifts[a].append([b, price])
    print(ski_lifts, ski_runs)

'''
5 2
6
3 2
3 5
1 5
3 4
1 2
4 3
4
3 1 1
4 3 5
5 2 2
3 4 5
4 9

'''
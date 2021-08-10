from collections import defaultdict

def DFS(node, string=""):
    global result
    if node <= data_number:
        DFS(node + 1, string + graph[node][0])
        DFS(node + 1, string + graph[node][1])
    elif string == string[::-1]:
        result += 1

if __name__ == "__main__":
    data_number = int(input())
    graph = defaultdict(list)
    result = 0
    for i in range(1, data_number+1):
        graph[i].append(input())
    for i in range(1, data_number+1):
        graph[i].append(input())

    DFS(1)
    print(result)
'''
5
ab
a
a
ab
a
a
baaaa
a
a
ba
=
12
'''
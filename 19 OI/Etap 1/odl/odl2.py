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

def find_closest_number(n):
    queue = graph[n].copy()
    result = []
    ways = [set(([n])) for _ in range(len(queue))]
    while queue:
        if result:
            return min(result)

        way = ways.pop(0)
        for elem in queue.copy():
            if elem not in way:

                if repeats[elem]:
                    n = numbers.index(elem)
                    result.append(n)

                else:
                    for child in graph[elem]:
                        queue.append(child)
                        ways.append(way.union(set(([elem]))))

def primes(n):
    # Create a boolean array "prime[0..n]" and initialize
    # all entries it as true. A value in prime[i] will
    # finally be false if i is Not a prime, else true.
    prime = [True for i in range(n + 1)]
    p = 2
    while (p * p <= n):

        # If prime[p] is not changed, then it is a prime
        if (prime[p] == True):

            # Update all multiples of p
            for i in range(p * 2, n + 1, p):
                prime[i] = False
        p += 1
    prime[0] = False
    prime[1] = False
    # Print all prime numbers
    result = []
    for p in range(n + 1):
        if prime[p]:
            result.append(p)
    return result

if __name__ == '__main__':
    setrecursionlimit(1000000000)
    repeats = defaultdict(list)
    elem_number = int(input())
    max_number = 0
    results = defaultdict(lambda: 0)
    numbers = []
    for i in range(1, elem_number+1):
        input_data = int(input())
        if input_data > max_number:
            max_number = input_data

        if not repeats[input_data]:
            repeats[input_data].append(i)

        elif len(repeats[input_data]) == 1:
            results[i] = repeats[input_data][0]
            results[repeats[input_data][0]] = i
            repeats[input_data].append([i])

        else:
            results[i] = repeats[input_data][0]

        numbers.append(input_data)
    prime_numbers = primes(max_number+1)
    graph = do_graph(prime_numbers)
    for count, number in enumerate(numbers, 1):
        if results[count] == 0:
            print(find_closest_number(number) + 1)
        else:
            print(results[count])
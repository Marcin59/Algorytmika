from collections import deque

if __name__ == "__main__":
    number_blocks = int(input())
    stack = deque([0])
    result = 0
    for _ in range(number_blocks):
        weidth, height = list(int(x) for x in input().split())
        while len(stack) != 0 and stack[-1] > height:
            stack.pop()

        if stack[-1] != height:
            stack.append(height)
            result += 1

    print(result)


'''
5
1 2
1 3
2 2
2 5
1 4
'''
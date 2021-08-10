from collections import defaultdict

if __name__ == '__main__':
    rectangles_len = int(input())
    rectangles = []
    for _ in range(rectangles_len):
        x0, y0, x1, y1 = list(map(int, input().split()))
        rectangles.append([[x0, y0], [x1, y1]])

    places = defaultdict(lambda:-1)
    
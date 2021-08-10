if __name__ == '__main__':
    cards_number = int(input())
    cards = [0, 0]
    cards += list(map(int, input().split()))
    cards.sort()
    player1 = 0
    player2 = 0
    motion = 0
    while cards[-1] != 0:
        while cards[-1] - cards[-2] < cards[-2] - cards[-3]:
            cards.pop()
        if not motion%2:
            player1 += cards.pop()
        else:
            player2 += cards.pop()
        motion += 1
    print(player1-player2)



'''
3
1 3 1

'''
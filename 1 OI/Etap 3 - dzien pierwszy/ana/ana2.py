def add_new_ana(data):
    global anagrams

    key = ''.join(sorted(data))
    if key not in keys:
        anagrams[key] = [data]
        keys.append(key)

    else:
        if data not in anagrams[key]:
            anagrams[key].append(data)

if __name__ == "__main__":
    quantity_numbers = int(input())
    anagrams = {}
    elements = []
    keys = []

    for _ in range(quantity_numbers):
        elements.append(input())

    for i in sorted(elements):
        add_new_ana(i)

    for i in anagrams.values():
        print(' '.join(i))
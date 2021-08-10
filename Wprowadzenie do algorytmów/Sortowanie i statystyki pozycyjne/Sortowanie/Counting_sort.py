def counting_sort(original_data, sorted_data):
    max_number = max(original_data)
    auxiliary_data = list([0] * (max_number + 1))

    for i in range(len(original_data)):
        auxiliary_data[original_data[i]] += 1

    for i in range(1, max_number+1):
        auxiliary_data[i] += auxiliary_data[i-1]

    for i, value in enumerate(auxiliary_data):
        print("{}: {}".format(i, value))

    for j in range(len(original_data)):
        sorted_data[auxiliary_data[original_data[j]]-1] = original_data[j]
        auxiliary_data[original_data[j]] -= 1

if __name__ == "__main__":
    original_data = [2, 5, 3, 0, 2, 3, 0, 3]
    sorted_data = [*original_data]
    counting_sort(original_data, sorted_data)
    print(sorted_data)

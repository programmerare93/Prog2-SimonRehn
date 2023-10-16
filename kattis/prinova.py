def is_odd(n):
    return n % 2 != 0

def main():
    N = int(input())
    names = [int(x) for x in input().split()]
    (A, B) = tuple([int(x) for x in input().split()])
    """
    if max(names) < B:
        if (is_odd(B)):
            print(B)
        else:
            print(B - 1)
        return
    """
    names.sort()
    names = [x for x in names if x in range(A, B + 1)]
    if len(names) == 0:
        names.append(B)
    elif names[-1] != B:
        names.append(B)
    if min(names) > A:
        names.insert(0, A)

    x = 0
    largest_distance = 0
    for i in range(len(names)):
        distance = 0
        if i != len(names) - 1:
            distance = abs(names[i] - names[i + 1])
        if distance > largest_distance:
            x = names[i]
            largest_distance = distance
    if (not is_odd(x + round(largest_distance / 2))):
        print(int(x + largest_distance / 2 + 1))
    else:
        print(int(x + largest_distance/2))

    """
    best_distance = 0
    best_name = A
    for x in range(A, B + 1):
        if (not is_odd(x)):
            continue

        smallest_distance = B + 1
        for p in names:
            distance = abs(x - p)
            if distance < smallest_distance:
                smallest_distance = distance

        if smallest_distance > best_distance:
            best_distance = smallest_distance
            best_name = x
    print(best_name)
    """


if __name__ == "__main__":
    main()

import math

def main():
    N = int(input())
    seats = input()

    smallest_distance = math.inf
    current_seat = None
    for (i, c) in enumerate(seats):
        if c == '.':
            if current_seat == None:
                current_seat = i
            else:
                distance = i - (current_seat + 1)
                current_seat = i
                if distance < smallest_distance:
                    smallest_distance = distance
    print(smallest_distance)
            


if __name__ == "__main__":
    main()

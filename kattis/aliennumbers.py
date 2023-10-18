import math

T = int(input())
T_Orig = T

def to_decimal(num, source_lang):
    num = list(num)
    source_lang = list(source_lang)

    source_base = len(source_lang)

    decimal_num = 0
    reversed_num = num[::-1]
    for i, digit in enumerate(reversed_num):
        decimal_num += source_lang.index(digit) * (source_base ** i)

    return decimal_num

def bar(digit, target_lang):
    return target_lang[int(digit)]

def decimal_to_target(num, target_lang):
    num = int(num)
    target_lang = list(target_lang)

    target_base = len(target_lang)

    digits = ""
    while (num != 0):
        digits += str(num % target_base)
        num //= target_base
    digits = digits[::-1]

    result = ""
    for digit in digits:
        result += str(bar(digit, target_lang))
    print(f"Case #{T_Orig - T + 1}: {result}")


def translate(num, source_lang, target_lang):
    num = list(num)
    source_lang = list(source_lang)
    target_lang = list(target_lang)

    decimal_num = to_decimal(num, source_lang)
    decimal_to_target(str(decimal_num), target_lang)

while T > 0:
    foo = input().split()
    translate(foo[0], foo[1], foo[2])
    T -= 1

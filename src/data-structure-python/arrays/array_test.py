# Generator
def factors(n):
    k = 1
    while k * k < n:
        if n % k == 0:
            yield k
            yield n // k
        k += 1
    if k * k == n:
        yield k


# R1.1
def is_multiple(n, m):
    # Return true if n is a multiple of m
    return m % n == 0


# R1.2
def is_even(k):
    i = 0
    while i < k:
        i += 2
        if i == k:
            return True
    return False


# R1.3
def minmax(data):
    min, max = None, None
    for num in data:
        if min is None or num < min:
            min = num
        if max is None or num > max:
            max = num
    return min, max


# R1.4
def sum_square(n):
    sum = 0
    for i in range(n):
        sum += i * i
    return sum


# R1.5
def sum_square_2(n):
    return sum(i*i for i in range(n))

# R1.7
def sum_square_odd(n):
    return sum(i*i for i in range(n) if i % 2 == 1)

# C1.13
def reverse(data):
    for i in range(len(data) // 2):
        end = len(data) - 1 - i
        data[i], data[end] = data[end], data[i]

# C1.17
def scale(data, factor):
    for i in range(len(data)):
        data[i] *= factor

# C1.18
# [i + i*i for i in range(0, 10)]

# C1.19
# [chr(i) for i in range(ord('a'), ord('a') + 26)]

# P1.29
def permutations(str):
    n = len(str)
    res = [c for c in str]
    i = 0
    while i < n - 1:
        temp = []
        for c in str:
            for w in res:
                if c not in w:
                    temp.append(w + c)
        res = [w for w in temp]
        i += 1
    return res


def permutations_2(nums):
    res = []

    def helper(curr, i):
        if i == len(nums) - 1:
            res.append([i for i in curr])
            return
        for j in range(i, len(nums)):
            curr[i], curr[j] = curr[j], curr[i]
            helper(curr, i + 1)
            curr[i], curr[j] = curr[j], curr[i]
    helper(nums, 0)
    return res

# P-1.30
def power_of_two(n):
    i = 0
    while n >= 2:
        n //= 2
        i += 1
    return i


def main():
    assert is_even(999) == False
    assert is_even(1000) == True
    assert minmax([4,5,3,2,6,22,1]) == (1,22)
    # 1 + 4 + 9 + 16 = 30
    assert sum_square(5) == 30
    assert sum_square_2(6) == 55
    assert sum_square_odd(6) == 35
    a = [1,2,3,4,5]
    scale(a, 2)
    assert a == [2,4,6,8,10]

    # for factor in factors(100):
    #     print(factor)

    # a = [1,2,3,4,5,6,7,8]
    # reverse(a)
    # print(a)

    # abc, acb, bac, bca, cab, cba
    a = permutations_2([1,2,3])
    assert a == [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 2, 1], [3, 1, 2]]
    assert power_of_two(16) == 4, power_of_two(16)


if __name__ == '__main__':
    main()

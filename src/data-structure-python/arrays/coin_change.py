def coin_change(coins, amount):
    # top-down approach with memoization
    memo = {}

    def helper(amount, memo):
        if amount in memo:
            return memo[amount]
        if amount < 0:
            return float('inf')
        if amount == 0:
            return 0

        memo[amount] = min(1 + helper(amount - coin, memo) for coin in coins)
        return memo[amount]

    res = helper(amount, memo)
    return res if res < float('inf') else -1


def main():
    # assert coin_change([2,3,5], 11) == 3
    # assert coin_change([2], 11) == -1
    assert coin_change([2], 1001) == -1


if __name__ == '__main__':
    main()

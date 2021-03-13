package prob0322

func coinChange(coins []int, amount int) int {
	n := len(coins)
	if amount == 0 {
		return 0
	}
	if n == 0 {
		return -1
	}

	// dp[i][j] 表示考虑coins[0...i]，剩余j个数额的最小金币数
	// 状态转移方程：dp[i][j] = {dp[i-1][j], dp[i-1][j+k] + t}min
	// 存储优化去掉i的维度
	dp := make([]int, amount+1, amount+1)
	for i := 0; i < amount+1; i++ {
		dp[i] = 1001
	}
	dp[amount] = 0

	for i := 0; i < n; i++ {
		for j := amount; j >= 0; j-- {
			couldBuy := (amount - j) / coins[i]
			for k := 1; k <= couldBuy; k++ {
				if dp[j+k*coins[i]]+k < dp[j] {
					dp[j] = dp[j+k*coins[i]] + k
				}
			}
		}
	}

	if dp[0] == 1001 {
		return -1
	}
	return dp[0]
}

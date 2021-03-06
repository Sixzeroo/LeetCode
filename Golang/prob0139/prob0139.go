package prob0139

func wordBreak(s string, wordDict []string) bool {
	n := len(s)
	if n == 0 {
		return false
	}

	dp := make([][]bool, 0, n)
	for i := 0; i < n; i++ {
		dp = append(dp, make([]bool, n, n))
	}

	// dp[i][j] 表示s[i...j]是否满足条件
	// 限定一端的条件，结束位置始终为sLen-1
	for i := n - 1; i >= 0; i-- {
		for j := i; j < n; j++ {
			if strSliceContain(wordDict, s[i:j+1]) {
				dp[i][j] = true
			}
			if j != n-1 && (dp[i][j] && dp[j+1][n-1]) {
				dp[i][n-1] = true
			}
			//fmt.Println(i, j, dp[i][j], dp[i][n-1])
		}
	}

	return dp[0][n-1]
}

func strSliceContain(s []string, ele string) bool {
	for _, i := range s {
		if i == ele {
			return true
		}
	}
	return false
}

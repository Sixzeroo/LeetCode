package prob0115

func numDistinct(s string, t string) int {
	sByte, tByte := []byte(s), []byte(t)
	m, n := len(sByte), len(tByte)
	if m == 0 || n == 0 {
		return 0
	}

	dp := make([]int, m+1, m+1)
	// TODO: 解释为什么需要这一步
	for i := 0; i < m; i++ {
		if sByte[i] == tByte[0] {
			dp[i] = 1
		}
	}

	// dp[i][j] 表示 s[0,i] 与 t[0,j] 满足条件的结果数量
	// 状态转移方程：http://data3.liuin.cn/2021_02_11_00_58_35_IcOoZmYl.png
	// case 解析：http://data3.liuin.cn/2021_02_11_00_59_05_YgFpubAt.png
	for j := 1; j <= n; j++ {
		forwardNum := dp[j-1]
		dp[j-1] = 0
		for i := j; i <= m; i++ {
			newForwardNum := dp[i]
			if sByte[i-1] == tByte[j-1] {
				dp[i] = dp[i-1] + forwardNum
			} else {
				dp[i] = dp[i-1]
			}
			forwardNum = newForwardNum
		}
	}

	return dp[m]
}

package prob0097

func isInterleave(s1 string, s2 string, s3 string) bool {
	s1Byte, s2Byte, s3Byte := []byte(s1), []byte(s2), []byte(s3)
	m, n, t := len(s1), len(s2), len(s3)
	if m+n != t {
		return false
	}

	// m 的坐标向右边平移一位，原因：让代码统一
	// 状态转移方程：http://data3.liuin.cn/2021_02_09_01_18_30_kpyGbULN.png
	// dp[i][j] 表示 s1[0:i] s2[0:j] s3[0:i+j] 满足条件
	dp := make([]bool, m+1, m+1)
	dp[0] = true
	for i := 0; i < m; i++ {
		dp[i+1] = dp[i] && s1Byte[i] == s3Byte[i]
	}
	for j := 0; j < n; j++ {
		dp[0] = dp[0] && s2Byte[j] == s3Byte[j]
		for i := 0; i < m; i++ {
			dp[i+1] = (dp[i] && s1Byte[i] == s3Byte[i+j+1]) || (dp[i+1] && s2Byte[j] == s3Byte[i+j+1])
		}
	}
	return dp[m]
}

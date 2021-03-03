package prob0132

func minCut(s string) int {
	sByte := []byte(s)
	sLen := len(sByte)
	if sLen == 0 {
		return 0
	}

	// dp[i][j] 表示 s[i...j] 是否为一个回文串
	dp := make([][]bool, 0, sLen)
	for i := 0; i < sLen; i++ {
		dp = append(dp, make([]bool, sLen, sLen))
	}
	// cut[i] 表示s[i...n-1]要砍的刀数
	cut := make([]int, sLen, sLen)

	for i := sLen - 1; i >= 0; i-- {
		cut[i] = sLen - i - 1
		for j := i; j < sLen; j++ {
			if s[i] == s[j] && (j-i < 2 || dp[i+1][j-1]) {
				dp[i][j] = true
				if j+1 == sLen {
					cut[i] = 0
				} else if cut[j+1]+1 < cut[i] {
					cut[i] = cut[j+1] + 1
				}
			}
		}
	}

	return cut[0]
}

package prob0140

import "fmt"

func wordBreak(s string, wordDict []string) []string {
	n := len(s)
	if n == 0 {
		return nil
	}

	dp := make([][]bool, 0, n)
	resDP := make([][][]string, 0, n)
	for i := 0; i < n; i++ {
		dp = append(dp, make([]bool, n, n))
		resDP = append(resDP, make([][]string, n, n))
	}

	// dp[i][j] 表示s[i...j]是否满足条件
	// 限定一端的条件，结束位置始终为sLen-1
	for i := n - 1; i >= 0; i-- {
		for j := i; j < n; j++ {
			if strSliceContain(wordDict, s[i:j+1]) {
				dp[i][j] = true
				addString(resDP, i, j, s[i:j+1])
			}
			if j != n-1 && (dp[i][j] && dp[j+1][n-1]) {
				dp[i][n-1] = true
				//fmt.Println(i, j, resDP[i][j], resDP[j+1][n-1])
				if resDP[i][j] != nil && resDP[j+1][n-1] != nil {
					for _, leftS := range resDP[i][j] {
						for _, rightS := range resDP[j+1][n-1] {
							newS := fmt.Sprintf("%s %s", leftS, rightS)
							addString(resDP, i, n-1, newS)
							//fmt.Println(i, n-1, resDP[i][n-1])
						}
					}
				}
			}
			//fmt.Println(i, j, dp[i][j], dp[i][n-1])
		}
	}

	return resDP[0][n-1]
}

func addString(m [][][]string, i, j int, s ...string) {
	if m[i][j] == nil {
		m[i][j] = s
	} else {
		m[i][j] = append(m[i][j], s...)
	}
}

func strSliceContain(s []string, ele string) bool {
	for _, i := range s {
		if i == ele {
			return true
		}
	}
	return false
}

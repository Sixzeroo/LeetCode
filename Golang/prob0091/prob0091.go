package prob0091

import "fmt"

func numDecodings(s string) int {
	n := len(s)

	dp := make([]int, n+1)
	dp[n] = 1
	lastNum := getStrNum(s, n-1, n-1)
	if lastNum > 0 {
		dp[n-1] = 1
	} else {
		dp[n-1] = 0
	}

	// 图解：http://data3.liuin.cn/2021_03_17_00_42_53_9GzY6Ifo.png
	for i := n - 2; i >= 0; i-- {
		if s[i] == '0' {
			dp[i] = 0
		} else {
			dp[i] = dp[i+1]
			otherNum := getStrNum(s, i, i+1)
			fmt.Println(otherNum)
			if otherNum <= 26 {
				dp[i] = dp[i] + dp[i+2]
			}
		}
		fmt.Println(dp[i])
	}
	return dp[0]
}

// return int(s[l:r])
func getStrNum(s string, l, r int) int {
	res := 0
	for i := l; i <= r; i++ {
		res = res*10 + int(s[i]-'0')
	}
	return res
}

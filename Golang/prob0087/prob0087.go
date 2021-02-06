package prob0087

import "fmt"

func isScramble(s1 string, s2 string) bool {
	return isScrambleImpByDP([]byte(s1), []byte(s2))
}

func isScrambleImp(s1 []byte, s2 []byte) bool {
	strLen := len(s1)
	if strLen == 1 {
		return s1[0] == s2[0]
	}
	fmt.Println(len(s1), len(s2))
	fmt.Println(string(s1), string(s2))
	for i := 1; i < strLen; i++ {
		s1SubLeft := s1[:i]
		s1SubRight := s1[i:strLen]
		s2LeftSubLeft := s2[:i]
		s2LeftSubRight := s2[i:strLen]
		s2RightSubLeft := s2[:strLen-i]
		s2RightSubRight := s2[strLen-i : strLen]

		if string(s1SubLeft) == string(s2LeftSubLeft) && string(s1SubRight) == string(s2LeftSubRight) {
			return true
		}
		if string(s1SubLeft) == string(s2RightSubRight) && string(s1SubRight) == string(s2RightSubLeft) {
			return true
		}
		if isScrambleImp(s1SubLeft, s2LeftSubLeft) && isScrambleImp(s1SubRight, s2LeftSubRight) {
			return true
		}
		if isScrambleImp(s1SubLeft, s2RightSubRight) && isScrambleImp(s1SubRight, s2RightSubLeft) {
			return true
		}
	}
	return false
}

// dp[i][j][n] 表示s1的i位置开始，s2的j位置开始，长度为n的两个字符串是否Scrmble
// 状态转移方程：http://data3.liuin.cn/2021_02_06_09_50_08_LJvOhQpg.png
func isScrambleImpByDP(s1 []byte, s2 []byte) bool {
	strLen := len(s1)

	dp := make([][][]bool, 0, strLen)
	for i := 0; i < strLen; i++ {
		iSlice := make([][]bool, 0, strLen)
		for j := 0; j < strLen; j++ {
			iSlice = append(iSlice, make([]bool, strLen+1, strLen+1))
		}
		dp = append(dp, iSlice)
	}

	for n := 1; n <= strLen; n++ {
		for i := 0; i <= strLen-n; i++ {
			for j := 0; j <= strLen-n; j++ {
				if n == 1 {
					dp[i][j][n] = s1[i] == s2[j]
				} else {
					// 只要k中的任何一个情况满足，dp[i][j][n] 就为true
					for k := 1; k < n; k++ {
						dp[i][j][n] = (dp[i][j][k] && dp[i+k][j+k][n-k]) || (dp[i][j+n-k][k] && dp[i+k][j][n-k]) || dp[i][j][n]
					}
				}
			}
		}
	}

	return dp[0][0][strLen]
}

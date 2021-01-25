package prob0032

func longestValidParentheses(s string) int {
	b := []byte(s)
	bLen := len(b)

	dp := make([]int, bLen+1)
	res := 0
	for i := 2; i <= bLen; i += 1 {
		if b[i-1] == ')' && b[i-2] == '(' {
			dp[i] = dp[i-2] + 2
		} else if b[i-1] == ')' && b[i-2] == ')' &&
			i-dp[i-1]-2 >= 0 && b[i-dp[i-1]-2] == '(' {

			dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2
		}
		if dp[i] > res {
			res = dp[i]
		}
	}
	return res
}

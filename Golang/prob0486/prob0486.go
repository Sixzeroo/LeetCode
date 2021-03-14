package prob0486

func PredictTheWinner(nums []int) bool {
	n := len(nums)
	if n == 0 {
		return false
	}

	// a 表示考虑nums[i...j]我方获取的最大利益数
	// a[i][j] = max{b[i+1][j] + num[i], b[i][j-1] + num[j]}
	// b 表示考虑nums[i...j]对方决策以后我方能获取的最大利益数
	// b[i][j] = min{a[i+1][j], a[i][j-1]}
	a := make([][]int, 0, n-1)
	b := make([][]int, 0, n-1)
	sum := 0
	for i := 0; i < n; i++ {
		a = append(a, make([]int, n, n))
		b = append(b, make([]int, n, n))
		sum += nums[i]
	}

	for step := 0; step < n; step++ {
		for i := 0; i+step < n; i++ {
			j := i + step
			if i == j {
				a[i][j] = nums[i]
			} else {
				a[i][j] = max(b[i][j-1]+nums[j], b[i+1][j]+nums[i])
				b[i][j] = min(a[i+1][j], a[i][j-1])
			}
			//fmt.Printf("%d, %d, %d\n", i, j, a[i][j])
		}
	}

	return a[0][n-1]*2 >= sum
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func min(a, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}

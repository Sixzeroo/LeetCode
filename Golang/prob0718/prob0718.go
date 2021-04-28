package prob0718

func findLength(nums1 []int, nums2 []int) int {
	n, m := len(nums1), len(nums2)

	res := 0
	dp := make([]int, m+1, m+1)
	for i := 1; i <= n; i++ {
		for j := m; j > 0; j-- {
			if nums1[i-1] == nums2[j-1] {
				dp[j] = dp[j-1] + 1
			} else {
				dp[j] = 0
			}
			res = max(res, dp[j])
		}
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

package prob0152

func maxProduct(nums []int) int {
	n := len(nums)
	if n == 0 {
		return 0
	}

	// 优化，f g 数组前面的内容可以不要
	f, g := nums[0], nums[0]
	res := f
	for i := 1; i < n; i++ {
		a := f * nums[i]
		b := g * nums[i]
		c := nums[i]
		f = max(a, max(b, c))
		g = min(a, min(b, c))
		res = max(res, f)
	}

	return res
}

func maxProductV2(nums []int) int {
	n := len(nums)
	if n == 0 {
		return 0
	}

	// f[i] 表示一定包含nums[i]的[0...i]的最大子数组乘积
	// g[i] 表示一定包含nums[i]的[0...i]的最小子数组乘积
	// 那么 f[i]  g[i] 一定在 f[i-1]*num[i] 、 g[i-1]*nums[i] 和 nums[i] 产生
	f := make([]int, n, n)
	g := make([]int, n, n)
	f[0], g[0] = nums[0], nums[0]
	res := f[0]
	for i := 1; i < n; i++ {
		a := f[i-1] * nums[i]
		b := g[i-1] * nums[i]
		c := nums[i]
		f[i] = max(a, max(b, c))
		g[i] = min(a, min(b, c))
		res = max(res, f[i])
	}

	return res
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func max(a, b int) int {
	if a < b {
		return b
	} else {
		return a
	}
}

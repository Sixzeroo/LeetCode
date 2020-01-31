package prob0003

func lengthOfLongestSubstring(s string) int {
	// lastOpints 表示每一个字符最后出现的位置的数组
	lastOpints := make([]int, 256, 256)
	// start 表示的是当前扫描的不重复字符串的起点位置
	start := 0
	res := 0

	for i := 1; i <= len(s); i++ {
		// 当前不重复字符串的起点是否比当前扫描字符串最后出现位置大
		if start <= lastOpints[s[i-1]] {
			start = lastOpints[s[i-1]]
		}
		if i-start > res {
			res = i - start
		}
		lastOpints[s[i-1]] = i
	}
	if len(s)-start > res {
		res = len(s) - start
	}

	return res
}

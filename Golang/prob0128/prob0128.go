package prob0128

func longestConsecutive(nums []int) int {
	longestLenMap := make(map[int]int)
	longestLen := 0

	for _, num := range nums {
		// 重复数字跳过
		if _, found := longestLenMap[num]; found {
			continue
		}

		left, right := num, num
		if l, found := longestLenMap[num-1]; found {
			left = num - l
		}
		if l, found := longestLenMap[num+1]; found {
			right = num + l
		}
		currentLen := right - left + 1
		longestLenMap[num] = currentLen

		if left != num {
			longestLenMap[left] = currentLen
		}
		if right != num {
			longestLenMap[right] = currentLen
		}

		if currentLen > longestLen {
			longestLen = currentLen
		}
	}

	return longestLen
}

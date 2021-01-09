package prob0560

func subarraySum(nums []int, k int) int {
	res, preSum := 0, 0
	preSumMap := map[int]int{0: 1}

	for _, num := range nums {
		preSum += num
		// k = preSum[j] - preSum[i]
		// preSum[i] = preSum[j] - k
		res += preSumMap[preSum-k]
		if _, found := preSumMap[preSum]; found {
			preSumMap[preSum] += 1
		} else {
			preSumMap[preSum] = 1
		}
	}

	return res
}

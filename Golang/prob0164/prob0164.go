package prob0164

// 题目说的是排序以后的相邻两个数的最大差值
func maximumGap(nums []int) int {
	n := len(nums)
	if n < 2 {
		return 0
	}

	minv, maxv := nums[0], nums[0]
	for _, num := range nums {
		minv = min(minv, num)
		maxv = max(maxv, num)
	}
	// 分桶步长要让相邻两个数的最值不在一个桶内，最值一定比平均值要大
	span := (maxv-minv)/n + 1
	bucketNum := (maxv-minv)/span + 1
	buckets := make([][]int, 0, bucketNum)
	for i := 0; i < bucketNum; i++ {
		buckets = append(buckets, make([]int, 0))
	}

	// 最值一定出现在两个桶的边缘
	for _, num := range nums {
		bucketIndex := (num - minv) / span
		if len(buckets[bucketIndex]) == 0 {
			buckets[bucketIndex] = append(buckets[bucketIndex], num)
			buckets[bucketIndex] = append(buckets[bucketIndex], num)
		} else {
			buckets[bucketIndex][0] = min(buckets[bucketIndex][0], num)
			buckets[bucketIndex][1] = max(buckets[bucketIndex][1], num)
		}
	}

	res, preIndex := 0, 0
	for i := 1; i < bucketNum; i++ {
		if len(buckets[i]) == 0 {
			continue
		}
		res = max(res, buckets[i][0]-buckets[preIndex][1])
		preIndex = i
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

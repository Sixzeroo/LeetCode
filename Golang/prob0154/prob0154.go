package prob0154

func findMin(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	numsLen := len(nums)
	l, r, m := 0, numsLen-1, 0

	for l < r {
		m = (l + r) / 2
		//fmt.Println(l, r, m)
		// 如果需要最终没有l > r的情况：需要r 不+1，因为向下取整，所以右边的游标不能轻易-1
		if nums[m] < nums[r] {
			r = m
		} else if nums[m] > nums[r] {
			l = m + 1
		} else {
			// 不能 l += 1，因为丢失较大值没有关系，但是丢失较小值可能丢失了最大值
			r -= 1
		}
	}

	return nums[l]
}

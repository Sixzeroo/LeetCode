package prob0081

func search(nums []int, target int) bool {
	numsLen := len(nums)
	notGrowCur := 1
	for ; notGrowCur < numsLen; notGrowCur += 1 {
		if nums[notGrowCur] < nums[notGrowCur-1] {
			break
		}
	}
	if notGrowCur != numsLen {
		nums = append(nums[notGrowCur:], nums[:notGrowCur]...)
	}
	//fmt.Println(nums)

	l, r := 0, numsLen-1
	for l <= r {
		m := (l + r) / 2
		//fmt.Println(l, r, m)
		if target > nums[m] {
			l = m + 1
		} else if target < nums[m] {
			r = m - 1
		} else {
			return true
		}
	}

	return l == r && nums[l] == target
}

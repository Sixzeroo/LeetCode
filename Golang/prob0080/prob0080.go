package prob0080

func removeDuplicates(nums []int) int {
	dupCount, newSlicePtr, newSliceLen := 0, 0, 0
	for i, num := range nums {
		if i == 0 || num != nums[i-1] {
			dupCount = 0
			newSliceLen += 1
			nums[newSlicePtr] = num
			newSlicePtr += 1
		} else if num == nums[i-1] && dupCount < 1 {
			dupCount += 1
			newSliceLen += 1
			nums[newSlicePtr] = num
			newSlicePtr += 1
		}
	}
	nums = nums[:newSlicePtr]
	return len(nums)
}

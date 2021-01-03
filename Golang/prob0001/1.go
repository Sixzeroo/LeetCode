package prob0001

func twoSum(nums []int, target int) []int {
	numIndexMap := make(map[int]int)
	for index, num := range nums {
		if otherIndex, found := numIndexMap[target-num]; found {
			return []int{otherIndex, index}
		}
		numIndexMap[num] = index
	}
	return []int{}
}

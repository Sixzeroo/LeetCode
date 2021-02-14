package prob0042

import "fmt"

func trap(height []int) int {
	// 找到最大的值
	highttestVal, highttestIndex := -1, 0
	for i, val := range height {
		if val > highttestVal {
			highttestVal = val
			highttestIndex = i
		}
	}

	// 双指针
	leftVal, rightVal := 0, 0
	res := 0
	for leftIndex := 0; leftIndex < highttestIndex; leftIndex ++ {
		if height[leftIndex] > leftVal {
			leftVal = height[leftIndex]
		} else {
			res = res + leftVal - height[leftIndex]
			fmt.Println(leftIndex, res)
		}
	}
	for rightIndex := len(height) - 1; rightIndex > highttestIndex ; rightIndex-- {
		if height[rightIndex] > rightVal {
			rightVal = height[rightIndex]
		} else {
			res = res + rightVal - height[rightIndex]
			fmt.Println(rightIndex, res)
		}
	}

	return res
}

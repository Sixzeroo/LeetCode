package prob0085

type StackInt struct {
	Data []int
}

func (s *StackInt) Top() int {
	if len(s.Data) == 0 {
		return 0
	}
	return s.Data[len(s.Data)-1]
}

func (s *StackInt) Push(i int) {
	s.Data = append(s.Data, i)
}

func (s *StackInt) Pop() {
	if len(s.Data) == 0 {
	}
	s.Data = s.Data[0 : len(s.Data)-1]
}

func (s *StackInt) IsEmpty() bool {
	return len(s.Data) == 0
}

func NewStackInt() *StackInt {
	return &StackInt{
		Data: []int{},
	}
}

func largestRectangleArea(heights []int) int {
	incresStask := NewStackInt()
	// 最后结算
	heights = append(heights, 0)

	res := 0
	for i, h := range heights {
		for !incresStask.IsEmpty() && heights[incresStask.Top()] > h {
			popIndex := incresStask.Top()
			popH := heights[popIndex]
			incresStask.Pop()
			beginIndex := -1
			if !incresStask.IsEmpty() {
				beginIndex = incresStask.Top()
			}
			// 要找到前一个入栈元素的index，因为中间的元素都比 popH 大
			w := i - beginIndex - 1
			if popH*w > res {
				res = popH * w
			}
		}
		incresStask.Push(i)
	}

	return res
}

func maximalRectangle(matrix [][]byte) int {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return 0
	}

	// build prefix ssum
	prefixSum := make([][]int, 0)
	for _, a := range matrix {
		signlePrefix := make([]int, 0)
		prefix := 0
		for _, b := range a {
			if b == '1' {
				prefix += 1
			} else {
				prefix = 0
			}
			signlePrefix = append(signlePrefix, prefix)
		}
		prefixSum = append(prefixSum, signlePrefix)
	}

	w, h := len(prefixSum[0]), len(prefixSum)
	reversedPrefixSum := make([][]int, 0, w)
	for i := 0; i < w; i += 1 {
		reversedPrefixSum = append(reversedPrefixSum, make([]int, h, h))
	}
	for i := 0; i < w; i++ {
		for j := 0; j < h; j++ {
			reversedPrefixSum[i][j] = prefixSum[j][i]
		}
	}

	res := 0
	for _, list := range reversedPrefixSum {
		rowSum := largestRectangleArea(list)
		//fmt.Printf("%v, %v\n", list, rowSum)
		if rowSum > res {
			res = rowSum
		}
	}

	return res
}

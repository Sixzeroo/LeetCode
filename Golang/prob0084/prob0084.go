package prob0084

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

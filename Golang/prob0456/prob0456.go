package prob0456

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

func find132pattern(nums []int) bool {
	nums = reverseSliceInt(nums)

	// 维护一个单调栈 + 第3个数
	stack := NewStackInt()
	secondNum := -1000000001
	for _, num := range nums {
		if num < secondNum {
			return true
		}
		for !stack.IsEmpty() && num > stack.Top() {
			if secondNum < stack.Top() {
				secondNum = stack.Top()
			}
			stack.Pop()
		}
		stack.Push(num)
	}

	return false
}

func reverseSliceInt(s []int) []int {
	res := make([]int, len(s), len(s))
	l := len(s)
	for i, item := range s {
		res[l-1-i] = item
	}
	return res
}

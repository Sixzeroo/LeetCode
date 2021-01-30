package prob456

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
	stack := NewStackInt()

	for _, num := range nums {
		if stack.IsEmpty() || num > stack.Top() {
			stack.Push(num)
		} else if num < stack.Top() {
			for !stack.IsEmpty() && num < stack.Top() {
				stack.Pop()
				if stack.IsEmpty() {
					stack.Push(num)
					break
				} else {
					if num > stack.Top() {
						return true
					}
				}
			}
		}
	}

	return false
}

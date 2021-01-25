package prob0032

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

func longestValidParenthesesV2(s string) int {
	b := []byte(s)

	res := 0
	stack := NewStackInt()
	stack.Push(-1)
	for i, v := range b {
		if v == '(' {
			stack.Push(i)
		} else {
			stack.Pop()
			if stack.IsEmpty() {
				stack.Push(i)
			} else {
				top := stack.Top()
				if i-top > res {
					res = i - top
				}
			}
		}
	}

	return res
}

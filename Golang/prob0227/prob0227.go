package prob0227

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

func calculate(s string) int {
	stack := NewStackInt()

	b := []byte(s)
	b = tripStr(b)
	bLen := len(b)
	item, index := getNextIntStr(b)
	stack.Push(item)
	for index < bLen-1 {
		nextItem, nextIndex := getNextIntStr(b[index+1:])
		switch b[index] {
		case '+':
			stack.Push(nextItem)
		case '-':
			stack.Push(-nextItem)
		case '*', '/':
			top := stack.Top()
			newTop := top * nextItem
			if b[index] == '/' {
				newTop = top / nextItem
			}
			stack.Pop()
			stack.Push(newTop)
		}
		index += nextIndex + 1
	}

	res := 0
	for !stack.IsEmpty() {
		res += stack.Top()
		stack.Pop()
	}
	return res
}

func tripStr(s []byte) []byte {
	new := []byte{}
	for _, v := range s {
		if v != ' ' {
			new = append(new, v)
		}
	}
	return new
}

func getNextIntStr(b []byte) (res, index int) {
	for i, v := range b {
		index = i
		if v < '0' || v > '9' {
			break
		}
		res = res*10 + int(v-'0')
	}
	return res, index
}

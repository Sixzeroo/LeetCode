package prob0173

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// --------

type StackNode struct {
	Data []*TreeNode
}

func (s *StackNode) Top() *TreeNode {
	if len(s.Data) == 0 {
		return nil
	}
	return s.Data[len(s.Data)-1]
}

func (s *StackNode) Push(i *TreeNode) {
	s.Data = append(s.Data, i)
}

func (s *StackNode) Pop() {
	if len(s.Data) == 0 {
	}
	s.Data = s.Data[0 : len(s.Data)-1]
}

func (s *StackNode) IsEmpty() bool {
	return len(s.Data) == 0
}

func NewStackInt() *StackNode {
	return &StackNode{
		Data: []*TreeNode{},
	}
}

type BSTIterator struct {
	S *StackNode
}

func Constructor(root *TreeNode) BSTIterator {
	b := BSTIterator{
		S: NewStackInt(),
	}
	cursor := root
	for cursor != nil {
		b.S.Push(cursor)
		cursor = cursor.Left
	}
	return b
}

func (this *BSTIterator) Next() int {
	top := this.S.Top()
	if top == nil {
		return 0
	}
	res := top.Val

	this.S.Pop()
	if top.Right != nil {
		cursor := top.Right
		for cursor != nil {
			this.S.Push(cursor)
			cursor = cursor.Left
		}
	}

	return res
}

func (this *BSTIterator) HasNext() bool {
	return !this.S.IsEmpty()
}

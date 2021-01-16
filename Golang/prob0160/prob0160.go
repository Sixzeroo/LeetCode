package prob0160

type ListNode struct {
	Val  int
	Next *ListNode
}

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	if headA == nil || headB == nil {
		return nil
	}

	// 判断有没有相交
	cursor1, cursor2 := headA, headB
	for cursor1.Next != nil {
		cursor1 = cursor1.Next
	}
	for cursor2.Next != nil {
		cursor2 = cursor2.Next
	}
	if cursor1 != cursor2 {
		return nil
	}

	// 找到相交的点
	cursor1, cursor2 = headA, headB
	for cursor1 != cursor2 {
		if cursor1.Next != nil {
			cursor1 = cursor1.Next
		} else {
			cursor1 = headA
		}

		if cursor2.Next != nil {
			cursor2 = cursor2.Next
		} else {
			cursor2 = headB
		}
	}

	return cursor1
}

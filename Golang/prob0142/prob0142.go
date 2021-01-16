package prob0142

type ListNode struct {
	Val  int
	Next *ListNode
}

func detectCycle(head *ListNode) *ListNode {
	nodeMap := make(map[*ListNode]struct{})

	for cursor := head; ; {
		if cursor == nil {
			break
		}
		if _, found := nodeMap[cursor]; found {
			return cursor
		} else {
			nodeMap[cursor] = struct{}{}
		}
		cursor = cursor.Next
	}

	return nil
}

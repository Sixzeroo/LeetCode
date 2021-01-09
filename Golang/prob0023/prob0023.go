package prob0023

// Definition for singly-linked list.

type ListNode struct {
	Val  int
	Next *ListNode
}

type List struct {
	Head, Tail *ListNode
}

func (l *List) AppendNode(n *ListNode) {
	if l.Head == nil {
		l.Head = n
		l.Tail = n
	} else {
		l.Tail.Next = n
		l.Tail = l.Tail.Next
	}
}

func mergeKLists(lists []*ListNode) *ListNode {
	resList := &List{}

	for {
		minListIndex := getMinListIndex(lists)
		if minListIndex == -1 {
			break
		}

		resList.AppendNode(lists[minListIndex])
		lists[minListIndex] = lists[minListIndex].Next
	}
	return resList.Head
}

func getMinListIndex(lists []*ListNode) int {
	if len(lists) == 0 {
		return -1
	}
	minVal := 100000
	minIndex := -1
	for i, list := range lists {
		if list == nil {
			continue
		}
		if list.Val < minVal {
			minVal = list.Val
			minIndex = i
		}
	}
	return minIndex
}

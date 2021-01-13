package prob0138

type Node struct {
	Val    int
	Next   *Node
	Random *Node
}

func copyRandomList(head *Node) *Node {
	if head == nil {
		return nil
	}

	newNodeList := make([]*Node, 0)
	nodeMap := make(map[*Node]int)

	// copy node
	preHead := &Node{Next: head}
	cursor := preHead
	index := 0
	for cursor.Next != nil {
		cursor = cursor.Next

		newNodeList = append(newNodeList, copyNode(cursor))
		nodeMap[cursor] = index
		index += 1
	}

	// reorganization
	newPreHead := &Node{Next: newNodeList[0]}
	cursor = newPreHead
	for cursor.Next != nil {
		cursor = cursor.Next

		if cursor.Next != nil {
			cursor.Next = newNodeList[nodeMap[cursor.Next]]
		}
		if cursor.Random != nil {
			cursor.Random = newNodeList[nodeMap[cursor.Random]]
		}
	}

	return newPreHead.Next
}

func copyNode(n *Node) *Node {
	return &Node{
		Val:    n.Val,
		Next:   n.Next,
		Random: n.Random,
	}
}

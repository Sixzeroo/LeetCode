package prob0146

type LRUCache struct {
	cap   int
	m     map[int]*Node
	first *Node
	last  *Node
}

type Node struct {
	Key  int
	Val  int
	Pre  *Node
	Next *Node
}

func Constructor(capacity int) LRUCache {
	first := &Node{}
	last := &Node{}
	first.Next = last
	last.Pre = first
	res := LRUCache{
		cap:   capacity,
		m:     make(map[int]*Node),
		first: first,
		last:  last,
	}

	return res
}

func (this *LRUCache) Get(key int) int {
	node, found := this.m[key]
	if !found {
		return -1
	}

	this.move2First(node)

	return node.Val
}

func (this *LRUCache) Put(key int, value int) {
	node, found := this.m[key]
	if found {
		node.Val = value
	} else {
		if len(this.m) == this.cap {
			// 移除最后一个
			this.removeLastNode()
		}
		node = &Node{
			Key: key,
			Val: value,
		}
		this.m[key] = node
	}
	this.move2First(node)
}

func (this *LRUCache) move2First(node *Node) {
	if node.Next != nil {
		node.Next.Pre = node.Pre
	}
	if node.Pre != nil {
		node.Pre.Next = node.Next
	}

	node.Next = this.first.Next
	this.first.Next = node
	node.Pre = this.first
	node.Next.Pre = node
}

func (this *LRUCache) removeLastNode() {
	latestNode := this.last.Pre

	latestNode.Pre.Next = latestNode.Next
	this.last.Pre = latestNode.Pre

	delete(this.m, latestNode.Key)
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */

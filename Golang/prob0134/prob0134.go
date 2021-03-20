package prob0134

func canCompleteCircuit(gas []int, cost []int) int {
	heap, minHeap, minIndex := 0, 100000001, -1

	for i, v := range cost {
		gap := gas[i] - v
		heap += gap
		if heap < minHeap {
			minHeap = heap
			minIndex = i
		}
	}
	if heap < 0 {
		return -1
	} else {
		return (minIndex + 1) % len(gas)
	}
}

package prob0912

func sortArray(nums []int) []int {
	return sortRadix(nums)
}

// ref: https://www.runoob.com/w3cnote/insertion-sort.html

// 冒泡排序
func sortBubble(nums []int) []int {
	n := len(nums)

	sortedFlag := false
	for i := 0; i < n && !sortedFlag; i++ {
		sortedFlag = true
		for j := n - 1; j > i; j-- {
			if nums[j] < nums[j-1] {
				nums[j], nums[j-1] = nums[j-1], nums[j]
				sortedFlag = false
			}
		}
	}

	return nums
}

// 选择排序
func sortSelect(nums []int) []int {
	n := len(nums)

	for i := 0; i < n; i++ {
		minIndex := i
		minVal := nums[i]
		for j := i + 1; j < n; j++ {
			if nums[j] < minVal {
				minVal = nums[j]
				minIndex = j
			}
		}
		if i != minIndex {
			nums[i], nums[minIndex] = nums[minIndex], nums[i]
		}
	}

	return nums
}

// 插入排序
func sortInsertion(nums []int) []int {
	n := len(nums)

	for i := 1; i < n; i++ {
		for j := i; j > 0; j-- {
			if nums[j] < nums[j-1] {
				nums[j], nums[j-1] = nums[j-1], nums[j]
			}
		}
	}

	return nums
}

// 希尔排序
// 步长不同，最坏情况下的时间复杂度也不同：http://data3.liuin.cn/2021_03_24_08_25_23_FZ0tl2LH.png
func sortShell(nums []int) []int {
	n := len(nums)

	for step := n / 2; step > 0; step /= 2 {
		for i := step; i < n; i++ {
			for j := i - step; j >= 0 && nums[j+step] < nums[j]; j -= step {
				nums[j+step], nums[j] = nums[j], nums[j+step]
			}
		}
	}

	return nums
}

// 归并排序
func sortMerge(nums []int) []int {
	n := len(nums)
	if n == 1 {
		return nums
	}

	middle := n / 2
	left := nums[:middle]
	right := nums[middle:]
	return merge(sortMerge(left), sortMerge(right))
}

func merge(a, b []int) []int {
	na, nb := len(a), len(b)
	res := make([]int, 0, na+nb)

	ia, ib := 0, 0
	for ia < na && ib < nb {
		if a[ia] < b[ib] {
			res = append(res, a[ia])
			ia += 1
		} else {
			res = append(res, b[ib])
			ib += 1
		}
	}

	if ia != na {
		res = append(res, a[ia:]...)
	}
	if ib != nb {
		res = append(res, b[ib:]...)
	}

	return res
}

// 快速排序
func sortQuick(nums []int) []int {
	n := len(nums)
	sortQuickImp(&nums, 0, n-1)
	return nums
}

func sortQuickImp(nums *[]int, left, right int) {
	if left < right {
		base := left
		index := left + 1
		for i := index; i <= right; i++ {
			if (*nums)[i] < (*nums)[base] {
				(*nums)[i], (*nums)[index] = (*nums)[index], (*nums)[i]
				index += 1
			}
		}
		(*nums)[base], (*nums)[index-1] = (*nums)[index-1], (*nums)[base]
		sortQuickImp(nums, left, index-2)
		sortQuickImp(nums, index, right)
	}
}

// 堆排序
func sortHeap(nums []int) []int {
	n := len(nums)

	// build max heap
	for i := n / 2; i >= 0; i-- {
		heapIfy(nums, i, n)
	}

	for i := n - 1; i >= 0; i-- {
		nums[0], nums[i] = nums[i], nums[0]
		n -= 1
		heapIfy(nums, 0, n)
	}

	return nums
}

func heapIfy(a []int, i, n int) {
	left := i*2 + 1
	right := i*2 + 2
	maxIndex := i
	if left < n && a[left] > a[maxIndex] {
		maxIndex = left
	}
	if right < n && a[right] > a[maxIndex] {
		maxIndex = right
	}
	if maxIndex != i {
		a[i], a[maxIndex] = a[maxIndex], a[i]
		heapIfy(a, maxIndex, n)
	}
}

// 计数排序
func sortCounting(nums []int) []int {
	n := len(nums)
	if n == 0 {
		return nums
	}
	maxNum := nums[0]
	for num := range nums {
		if num > maxNum {
			maxNum = num
		}
	}
	bucket := make([]int, maxNum+1, maxNum+1)
	for _, num := range nums {
		bucket[num] = bucket[num] + 1
	}
	res := make([]int, 0, n)
	for i := 0; i <= maxNum; i++ {
		for bucket[i] > 0 {
			res = append(res, i)
			bucket[i]--
		}
	}
	return res
}

// 桶排序
func sortBucket(nums []int) []int {
	step := 10
	n := len(nums)
	if n == 0 {
		return nums
	}
	maxNum := nums[0]
	for num := range nums {
		if num > maxNum {
			maxNum = num
		}
	}
	bucketNum := maxNum/step + 1
	buckets := make([][]int, 0, bucketNum)
	for i := 0; i < bucketNum; i++ {
		buckets = append(buckets, make([]int, 0))
	}
	for _, num := range nums {
		bucketNum := num / step
		buckets[bucketNum] = append(buckets[bucketNum], num)
	}

	res := make([]int, 0, n)
	for _, bucket := range buckets {
		sortQuick(bucket)
		res = append(res, bucket...)
	}
	return res
}

// 基数排序
func sortRadix(nums []int) []int {
	n := len(nums)
	if n == 0 {
		return nums
	}
	maxDig := 0
	for _, num := range nums {
		maxDig = max(maxDig, getDig(num))
	}

	buckets := make([][]int, 0, 10)
	for i := 0; i < 10; i++ {
		buckets = append(buckets, make([]int, 0))
	}
	for i := 1; i <= maxDig; i++ {
		newNums := make([]int, 0, n)
		basic := 1
		for t := 1; t < i; t++ {
			basic *= 10
		}
		for _, num := range nums {
			bucketNum := num / basic
			bucketNum %= 10
			buckets[bucketNum] = append(buckets[bucketNum], num)
		}
		for i := 0; i < 10; i++ {
			newNums = append(newNums, buckets[i]...)
			buckets[i] = []int{}
		}
		nums = newNums
	}
	return nums
}

func getDig(num int) int {
	res := 0
	for num > 0 {
		num /= 10
		res += 1
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

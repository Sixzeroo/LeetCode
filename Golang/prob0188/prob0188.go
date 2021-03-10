package prob0188

func maxProfit(k int, prices []int) int {
	n := len(prices)
	if n == 0 {
		return 0
	}
	sell := make([]int, k+1, k+1)
	buy := make([]int, k+1, k+1)
	for i := 0; i <= k; i++ {
		buy[i] = -1000001
	}

	// 一种贪心思路
	for _, price := range prices {
		for i := 1; i <= k; i++ {
			buy[i] = max(sell[i-1]-price, buy[i])
			sell[i] = max(buy[i]+price, sell[i])
		}
		//fmt.Println("buy")
		//fmt.Println(buy)
		//fmt.Println("sell")
		//fmt.Println(sell)
	}

	return sell[k]
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

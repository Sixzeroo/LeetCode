package prob0121

func maxProfit(prices []int) int {

	res := 0
	minPrices := make([]int, 0, len(prices))
	minPrice := 100000
	for _, price := range prices {
		if price < minPrice {
			minPrice = price
		}
		minPrices = append(minPrices, minPrice)
	}
	l := len(prices)

	maxPrice := 0
	for i := l - 1; i >= 0; i-- {
		if prices[i] > maxPrice {
			maxPrice = prices[i]
		}
		if maxPrice-minPrices[i] > res {
			res = maxPrice - minPrices[i]
		}
	}
	return res
}

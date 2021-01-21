package prob0168

func convertToTitle(n int) string {
	res := ""

	base := n
	remainder := 0
	for base > 0 {
		remainder = base % 26
		base = base / 26
		// 整除的时候个位是0，特殊的表示
		if remainder == 0 {
			remainder = 26
			base -= 1
		}
		res = string('A'+remainder-1) + res
	}
	return res
}

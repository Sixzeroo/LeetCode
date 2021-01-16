package prob0050

func myPow(x float64, n int) float64 {
	powNegFlag := false
	if n < 0 {
		powNegFlag = true
		n = -n
	}

	// 快速幂运算
	res, tem := 1.0, x
	for n != 0 {
		if n%2 != 0 {
			res = res * tem
		}
		tem = tem * tem
		n = n / 2
	}

	if powNegFlag {
		res = 1 / res
	}
	return res
}

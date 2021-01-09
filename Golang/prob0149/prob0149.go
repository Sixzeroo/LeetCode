package prob0149

// 直线定义 y = kx + b
// k = Y / X
type Line struct {
	X int
	Y int
	B int
}

var (
	zeroLine = Line{X: 0, Y: 0, B: 0}
)

func maxPoints(points [][]int) int {
	res := 0
	// 遍历每个点能够与其他点构成的直线，查看最多有多少点落在同一直线上
	for i, originPoint := range points {
		lineMap := make(map[Line]int)
		baseCount := 1
		maxPoints4OriginPoint := 0
		for j, point := range points {
			if i == j {
				continue
			}
			line := getLineByTowPoint(originPoint, point)
			if line == zeroLine {
				baseCount += 1
				continue
			}
			_, found := lineMap[line]
			if found {
				lineMap[line] += 1
			} else {
				lineMap[line] = 1
			}
			if lineMap[line]+baseCount > maxPoints4OriginPoint {
				maxPoints4OriginPoint = lineMap[line] + baseCount
			}
		}
		if maxPoints4OriginPoint > res {
			res = maxPoints4OriginPoint
		}
		if baseCount > res {
			res = baseCount
		}
	}
	return res
}

func getLineByTowPoint(a, b []int) Line {
	devX := b[0] - a[0]
	devY := b[1] - a[1]
	if devX == 0 && devY == 0 {
		return zeroLine
	} else if devX == 0 {
		return Line{X: 0, Y: 1, B: a[0]}
	} else if devY == 0 {
		return Line{X: 1, Y: 0, B: a[1]}
	}
	g := gcd(absInt(devX), absInt(devY))
	moduls := (devX / devX) * (devY / devY)
	res := Line{X: absInt(devX) / g, Y: moduls * devY / g}
	res.B = (b[1]*res.X - res.Y*b[0])
	return res
}

func gcd(a, b int) int {
	if a%b == 0 {
		return b
	}
	return gcd(b, a%b)
}

func absInt(i int) int {
	if i < 0 {
		return -i
	}
	return i
}

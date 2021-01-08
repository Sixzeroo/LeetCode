package prob0149

import "fmt"

type Line struct {
	X int
	Y int
}

var (
	zeroLine = Line{X: 0, Y: 0}
)

func maxPoints(points [][]int) int {
	res := 0
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
			if i == 47 {
				fmt.Printf("%d, %d, %v, %v, %v\n", j, maxPoints4OriginPoint, originPoint, point, line)
			}
		}
		if maxPoints4OriginPoint > res {
			res = maxPoints4OriginPoint
		}
		if baseCount > res {
			res = baseCount
		}
		//fmt.Printf("%d, %d, %d, %d, %v\n", i, res, baseCount, maxPoints4OriginPoint, originPoint)
	}
	return res
}

// TODO: 完善直线定义条件
func getLineByTowPoint(a, b []int) Line {
	devX := b[0] - a[0]
	devY := b[1] - a[1]
	if devX == 0 && devY == 0 {
		return zeroLine
	} else if devX == 0 {
		return Line{X: 0, Y: 1}
	} else if devY == 0 {
		return Line{X: 1, Y: 0}
	}
	g := gcd(absInt(devX), absInt(devY))
	moduls := (devX / devX) * (devY / devY)
	res := Line{X: absInt(devX) / g, Y: moduls * devY / g}
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

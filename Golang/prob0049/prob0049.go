package prob0049

import (
	"sort"
	"strings"
)

func SortString(w string) string {
	s := strings.Split(w, "")
	sort.Strings(s)
	return strings.Join(s, "")
}

func groupAnagrams(strs []string) [][]string {
	anagramsMap := make(map[string][]string)
	for _, str := range strs {
		sortedStr := SortString(str)
		_, found := anagramsMap[sortedStr]
		if found {
			anagramsMap[sortedStr] = append(anagramsMap[sortedStr], str)
		} else {
			anagramsMap[sortedStr] = []string{str}
		}
	}

	res := make([][]string, 0, len(anagramsMap))
	for _, anagrams := range anagramsMap {
		res = append(res, anagrams)
	}
	return res
}

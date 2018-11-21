func twoSum(nums []int, target int) []int {
    m := make(map[int]int, len(nums))
    
    for i, v := range nums {
        if n, ok := m[target - v] ; ok {
            return []int{n, i}
        }
        
        m[v] = i
    }
    
    return nil
}
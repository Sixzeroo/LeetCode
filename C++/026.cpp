class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 使用erase删除重复元素
        for(vector<int>::iterator it = nums.begin() ; it != nums.end();++it)
        {
            while(*it == *(it+1) && (it+1) != nums.end())
                it = nums.erase(it);
        }
        return nums.size();
    }
};
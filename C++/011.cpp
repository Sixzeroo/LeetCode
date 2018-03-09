class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int res = min(height[i], height[j])*(j-i);
        // 从两边向中间扫描
        while(i<j)
        {
            if(height[i] < height[j])
                i++;
            else
                j--;
            res = max(res, min(height[i], height[j])*(j-i));
        }
        return res;
    }
};
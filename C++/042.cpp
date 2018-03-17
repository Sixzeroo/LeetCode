class Solution {
public:
    int trap(vector<int>& height) {
        // 双指针，从两边向中间计算
        int len = height.size(), res =0;
        if(len == 0) return res;
        int l = 0, r=len-1;
        int maxl = height[l], maxr = height[r];
        while(l<=r)
        {
            // 右边指针更新
            if(maxl<maxr)
            {
                if(height[l] > maxl) maxl = height[l];
                else res += (maxl - height[l]);
                l++;
            }
            // 左边指针更新
            else
            {
                if(height[r] > maxr) maxr = height[r];
                else res += (maxr - height[r]);
                r--;
            }
        }
        return res;
    }
};
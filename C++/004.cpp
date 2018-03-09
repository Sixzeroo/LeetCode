class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        // 对小的数组进行分割
        if(n > m)
        {
            swap(nums1, nums2);
            swap(n,m);
        }
        // 二分法确定两个界限
        int i, j, iMin = 0, iMax = n;
        while(iMin <= iMax)
        {
            i = (iMin + iMax)/2 ;
            j = (m+n+1)/2 - i;
            // i的取值过大
            if(i > iMin && nums1[i-1] > nums2[j])
            {
                iMax = i - 1;
            }
            // i的取值过小的情况
            else if(i < iMax && nums1[i] < nums2[j-1]) 
            {
                iMin = i + 1;
            }
            // 找到中位数
            else{
                int left = 0;
                if(i == 0) left = nums2[j-1];
                else if(j == 0) left = nums1[i-1];
                else left = max(nums1[i-1], nums2[j-1]);
                // 总数是奇数的时候
                if ( (m + n) % 2) return left;
                
                int right = 0;
                if(i == n) right = nums2[j];
                else if(j == m) right = nums1[i];
                else right = min(nums1[i], nums2[j]);
                return (left + right)/2.0;
            }
        }
        return 0.0;
    }
};

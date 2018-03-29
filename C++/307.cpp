class NumArray {
public:
    vector<int> tree;
    vector<int> Nums;
    int len;
    NumArray(vector<int> nums) {
        len = nums.size();
        Nums = nums;
        tree = vector<int>(len+1, 0);
        for (int i=0; i<len; i++) {
            init(i, Nums[i]);
        }
    }

    void init(int i, int val) {
        i++;
        while (i <= len) {
            tree[i] += val;
            i += (i & -i);
        }
    }

    void update(int i, int val) {
        int temp = val - Nums[i];
        Nums[i] = val;
        init(i, temp);
    }

    int getSum(int i) {
        int sum = 0;
        i++;
        while (i > 0) {
            sum += tree[i];
            i -= (i & -i);
        }
        return sum;
    }

    int sumRange(int i, int j) {
        return getSum(j) - getSum(i-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
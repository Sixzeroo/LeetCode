/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    // 自定义排序方法
    static bool compare(Interval &a, Interval &b)
    {
        if(a.start == b.start)
            return a.end<b.end;
        else
            return a.start<b.start;
    }
    
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), compare);
        int len = intervals.size();
        vector<Interval> res;
        for(int i=0; i<len; i++)
        {
            Interval tem = intervals[i];
            while(i+1<len && tem.end >= intervals[i+1].start)
            {
                tem.end = max(intervals[i+1].end,tem.end);
                i++;
            }
            res.push_back(tem);
        }
        return res;
    }
};
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a%b);
    }
    
    // O(n^2)时间复杂度算法
    int maxPoints(vector<Point>& points) {
        map<pair<int, int>, int> m;
        int len = points.size(), res = 0;
        // 固定一点，通过斜率判断是否在一条直线上面，通过map记录键值对
        for(int i = 0; i < len ; i++)
        {
            m.clear();
            int tem_max = 0, same_num = 0;
            for(int j = 0; j < len ; j++)
            {
                if(i == j) continue;
                int dx = points[i].x - points[j].x;
                int dy = points[i].y - points[j].y;
                if(dx == 0 && dy == 0) 
                {
                    same_num ++;
                    continue;
                }
                int g = gcd(dx, dy);
                pair<int, int> tem = g==0 ? make_pair(dx,dy) : make_pair(dx/g, dy/g);
                cout<<tem.first<<" "<<tem.second<<endl;
                if(m.find(tem) != m.end())
                    m[tem] ++;
                else
                    m[tem] = 2;
                tem_max = max(tem_max, m[tem]);
            }
            // 只有一个点的时候
            tem_max = tem_max == 0 ? 1 : tem_max;
            // 加上相同的点
            res = max(res, tem_max + same_num);
        }
        return res;
    }
};
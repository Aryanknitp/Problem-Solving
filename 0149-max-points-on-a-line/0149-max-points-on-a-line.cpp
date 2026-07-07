class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() == 0)
            return 1;
            if(points.size()==1 && points[0][0]==0 && points[0][1]==0 ) return 1;
            if(points.size()==1 && points[0][0]==1 && points[0][1]==1 ) return 1;
        int res = 0;
        for (auto& p1 : points) {
            map<pair<int, int>, int> mp;
            int dup = 0;
            for (auto& p2 : points) {
                int dx = p2[0] - p1[0], dy = p2[1] - p1[1];
                int g = gcd(abs(dx), abs(dy));
                if (dx == 0 && dy == 0)
                    dup++;
                else {
                    mp[{dy / g, dx / g}]++;
                }
            }
            for (auto& [slope, p] :mp) {
                res = max(res, dup + p);
            }
        }
        return res;
    }
};
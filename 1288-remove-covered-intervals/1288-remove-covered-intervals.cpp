class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        if (a[1] == b[1]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int n  = intervals.size();
        int cnt = 0;
            for(int i=0;i<n-1;i++) {
                  for(int j = i+1;j<n;j++) {
                       if(intervals[i][0]>=intervals[j][0]) {
                           cnt++;
                           break;
                       }
                       if(intervals[i][1]==intervals[j][1]) {
                          cnt++;
                          break;
                       }
                  }
            }
            return intervals.size()-cnt;
    }
};

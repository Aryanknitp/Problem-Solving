class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        //solve by myself aryan kumar...
        vector<int>g(n,0);
        int cg = 0;
        for(int i=1;i<n;i++){
             if(nums[i]-nums[i-1]>maxDiff) cg++;
             g[i] = cg;
        }

        vector<bool>res;
        for(auto &q:queries){
            int u =q[0] , v =q[1];
           res.push_back(g[u]==g[v]);
        }
        return res;
    }
};
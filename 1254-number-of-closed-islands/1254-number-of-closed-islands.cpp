class Solution {
public:
class dsu{
     public: vector<int>p;
     dsu(int n) {
         p.resize(n);
         for(int i=0;i<n;i++) p[i] =i;
     }
     int find(int i) {
        if(p[i]==i) return i;
       return  p[i] = find(p[i]);
     }
     void unite(int i,int j) {
         int ri= find(i);
         int rj = find(j);
         if(ri<rj) {
            p[ri] = rj;
         }
         else if(ri>rj){
             p[rj] = ri;
         }
         else{
             p[ri] = rj;
         }
     }
};

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size();
        int db = n*m;
        dsu ds(db+1);
        // step1 unite the border of grid
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==0){
                     int ci = i*m+j;
                     if(i==0 || i==n-1|| j==0 || j==m-1){
                        ds.unite(ci,db);
                     }
                }
            }
        }
        for(int i=0;i<n;i++) {
             for(int j=0;j<m;j++) {
                 if(grid[i][j]==0) {
                    //   right
                      int ci = i*m+j;
                      if(j+1<m && grid[i][j+1]==0){
                        ds.unite(ci,i*m+(j+1));
                      }
                    //   down
                      if(i+1<n && grid[i+1][j]==0){
                         ds.unite(ci,(i+1)*m+j);
                      }
                 }
             }
        }
        unordered_set<int> closedIslandRoots;
        int borderRoot = ds.find(db);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    int cellRoot = ds.find(i * m + j);
                    // If this land cell group does not touch the border, track its root
                    if (cellRoot != borderRoot) {
                        closedIslandRoots.insert(cellRoot);
                    }
                }
            }
        }
        
        return closedIslandRoots.size();
    }
};
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq ;
        for(auto it:stones)
            pq.push(it);
        while(pq.size()>1){
            int l = pq.top(); pq.pop();
            int s = pq.top(); pq.pop();
            if(l!=s){
               pq.push(l-s);
            }
        }
        if(pq.empty()) return 0;
        return pq.top() ;  
         }
};
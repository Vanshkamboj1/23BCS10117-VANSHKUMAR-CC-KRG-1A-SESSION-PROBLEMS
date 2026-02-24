class Solution {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        
        int n = deadline.size();
        
        vector<pair<int,int>> jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({profit[i], deadline[i]});
        }
        
        sort(jobs.rbegin(), jobs.rend());
        
        int maxDead = *max_element(deadline.begin(), deadline.end());
        vector<int> slot(maxDead+1, -1);
        
        int count = 0;
        int totalProfit = 0;
        
        for(int i=0;i<n;i++){
            int d = jobs[i].second;
            for(int j=d;j>0;j--){
                if(slot[j] == -1){
                    slot[j] = i;
                    count++;
                    totalProfit += jobs[i].first;
                    break;
                }
            }
        }
        
        return {count, totalProfit};
    }
};
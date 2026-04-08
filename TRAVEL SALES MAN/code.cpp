class Solution {
public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        int N = 1 << n;
        
        vector<vector<int>> dp(N, vector<int>(n, 1e9));
        dp[1][0] = 0;
        
        for(int mask = 1; mask < N; mask++) {
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    for(int j = 0; j < n; j++) {
                        if(!(mask & (1 << j))) {
                            dp[mask | (1 << j)][j] = min(
                                dp[mask | (1 << j)][j],
                                dp[mask][i] + cost[i][j]
                            );
                        }
                    }
                }
            }
        }
        
        int ans = 1e9;
        for(int i = 0; i < n; i++) {
            ans = min(ans, dp[N - 1][i] + cost[i][0]);
        }
        
        return ans;
    }
};
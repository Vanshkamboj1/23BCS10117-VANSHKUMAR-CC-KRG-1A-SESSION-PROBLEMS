class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int n = mat1.size();
        int m = mat1[0].size();
        int p = mat2[0].size();
        
        if(m != mat2.size()) return {};
        
        vector<vector<int>> result(n, vector<int>(p, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < p; j++) {
                for(int k = 0; k < m; k++) {
                    result[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        
        return result;
    }
};
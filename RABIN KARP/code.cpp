class Solution {
public:
    vector<int> search(string &pat, string &txt) {
        vector<int> result;
        
        int n = txt.length();
        int m = pat.length();
        
        if(m > n) return result;
        
        const int base = 256;
        const int mod = 1e9 + 7;
        
        long long patHash = 0;
        long long txtHash = 0;
        long long power = 1;
        
        for(int i = 0; i < m - 1; i++)
            power = (power * base) % mod;
        
        for(int i = 0; i < m; i++) {
            patHash = (patHash * base + pat[i]) % mod;
            txtHash = (txtHash * base + txt[i]) % mod;
        }
        
        for(int i = 0; i <= n - m; i++) {
            
            if(patHash == txtHash) {
                if(txt.substr(i, m) == pat)
                    result.push_back(i);
            }
            
            if(i < n - m) {
                txtHash = (txtHash - txt[i] * power % mod + mod) % mod;
                txtHash = (txtHash * base + txt[i + m]) % mod;
            }
        }
        
        return result;
    }
};
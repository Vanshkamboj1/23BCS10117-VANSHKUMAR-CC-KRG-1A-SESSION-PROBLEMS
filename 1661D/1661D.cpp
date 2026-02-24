#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    vector<long long> adds(n + 1, 0);
    
    long long total_ops = 0;
    long long sum_add = 0;
    long long active_ops = 0;
    for (int i = n; i >= 1; --i) {
        long long req = b[i] - sum_add;
        
        if (req > 0) {
            long long step = min((long long)i, (long long)k);
            long long c = (req + step - 1) / step;
            
            total_ops += c;
            sum_add += c * step;
            active_ops += c;
            adds[i - step + 1] += c;
        }
        sum_add -= active_ops;
        active_ops -= adds[i];
    }

    cout << total_ops << "\n";

    return 0;
}
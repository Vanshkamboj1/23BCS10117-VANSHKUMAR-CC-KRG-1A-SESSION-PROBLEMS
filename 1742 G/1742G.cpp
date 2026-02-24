#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int current_or = 0;
    int limit = min(n, 31);
    
    for (int i = 0; i < limit; ++i) {
        int best_or = current_or;
        int best_idx = -1;
        
        for (int j = i; j < n; ++j) {
            if ((current_or | a[j]) > best_or) {
                best_or = current_or | a[j];
                best_idx = j;
            }
        }
        
        if (best_idx == -1) break;
        
        swap(a[i], a[best_idx]);
        current_or |= a[i];
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
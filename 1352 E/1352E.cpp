#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> freq(n + 1, 0);
        for(int i = 0; i < n; i++)
            freq[a[i]]++;

        vector<bool> isSpecial(n + 1, false);

        for(int i = 0; i < n; i++){
            int sum = a[i];
            for(int j = i + 1; j < n; j++){
                sum += a[j];
                if(sum > n) break;
                isSpecial[sum] = true;
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(isSpecial[i])
                ans += freq[i];
        }

        cout << ans << "\n";
    }

    return 0;
}
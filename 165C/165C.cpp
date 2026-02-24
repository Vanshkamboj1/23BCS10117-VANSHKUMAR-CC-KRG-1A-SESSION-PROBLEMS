#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long k;
    cin >> k;

    string s;
    cin >> s;

    long long n = s.size();
    long long ans = 0;

    if(k == 0){
        long long cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                cnt++;
            } else {
                ans += (cnt * (cnt + 1)) / 2;
                cnt = 0;
            }
        }
        ans += (cnt * (cnt + 1)) / 2;
        cout << ans;
        return 0;
    }

    unordered_map<long long,long long> freq;
    freq[0] = 1;

    long long prefix = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == '1') prefix++;

        if(freq.count(prefix - k))
            ans += freq[prefix - k];

        freq[prefix]++;
    }

    cout << ans;
}
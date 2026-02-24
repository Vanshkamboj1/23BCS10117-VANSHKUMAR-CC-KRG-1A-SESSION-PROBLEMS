#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long S;
    cin >> n >> S;

    vector<long long> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int left = 0, right = n;
    int ans_k = 0;
    long long ans_cost = 0;

    while(left <= right) {
        int mid = (left + right) / 2;

        vector<long long> cost(n);
        for(int i = 0; i < n; i++)
            cost[i] = a[i] + 1LL * (i + 1) * mid;

        sort(cost.begin(), cost.end());

        long long total = 0;
        for(int i = 0; i < mid; i++)
            total += cost[i];

        if(total <= S) {
            ans_k = mid;
            ans_cost = total;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans_k << " " << ans_cost << "\n";
}
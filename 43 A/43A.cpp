#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string,int> mp;
    string team;

    for(int i=0;i<n;i++){
        cin >> team;
        mp[team]++;
    }

    string winner;
    int mx = 0;

    for(auto x : mp){
        if(x.second > mx){
            mx = x.second;
            winner = x.first;
        }
    }

    cout << winner;

    return 0;
}
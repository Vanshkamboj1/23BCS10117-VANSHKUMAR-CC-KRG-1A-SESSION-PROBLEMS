#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<long long>a(n+1),b(n+1),pref(n+1),cnt(n+2),extra(n+2);

        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            cin>>b[i];
            pref[i]=pref[i-1]+b[i];
        }

        for(int i=1;i<=n;i++){
            long long target=a[i]+pref[i-1];

            int pos=upper_bound(pref.begin()+1,pref.begin()+n+1,target)-pref.begin()-1;

            cnt[i]++;
            cnt[pos+1]--;

            if(pos+1<=n){
                extra[pos+1]+=target-pref[pos];
            }
        }

        for(int i=1;i<=n;i++){
            cnt[i]+=cnt[i-1];
        }

        for(int i=1;i<=n;i++){
            cout<<cnt[i]*b[i]+extra[i]<<" ";
        }

        cout<<"\n";
    }
}
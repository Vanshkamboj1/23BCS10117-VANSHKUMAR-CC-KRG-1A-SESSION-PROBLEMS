#include <bits/stdc++.h>
using namespace std;

const long long p = 31;
const long long mod = 1000000009;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<long long> power(600005);
    power[0]=1;

    for(int i=1;i<600005;i++)
        power[i]=(power[i-1]*p)%mod;

    unordered_set<long long> st;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;

        long long h=0;
        for(int j=0;j<s.size();j++){
            h=(h+(s[j]-'a'+1)*power[j])%mod;
        }
        st.insert(h);
    }

    while(m--){
        string s;
        cin>>s;

        long long h=0;
        for(int i=0;i<s.size();i++)
            h=(h+(s[i]-'a'+1)*power[i])%mod;

        bool ok=false;

        for(int i=0;i<s.size() && !ok;i++){
            char orig=s[i];

            for(char c='a';c<='c';c++){
                if(c==orig) continue;

                long long nh=h;
                nh=(nh-(orig-'a'+1)*power[i]%mod+mod)%mod;
                nh=(nh+(c-'a'+1)*power[i])%mod;

                if(st.count(nh)){
                    ok=true;
                    break;
                }
            }
        }

        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
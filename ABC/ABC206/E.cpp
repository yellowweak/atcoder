#include <bits/stdc++.h>
using namespace std;
// BEGIN LIB
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
#define print_grid(x) for(auto &r:x){for(auto &c:r)cout<<c<<" ";cout<<endl;}cout<<endl;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> grid;
typedef pair<ll, ll> pll;
// END LIB

void gen_div(ll n, vll &ps){
    for(ll i=2; i<=n && n>1;){
        if(n%i==0){
            ps.push_back(i);
            while(n%i==0)   n/=i;
        }
        i = (i*i<n)? i+1+(i%2):n;
    }
}

ll euler(ll r, vll &ps){
    gen_div(r, ps);
    for(auto &p:ps)     r=(r/p)*(p-1);
    return r;
}

ll re(ll x, vll &ps){
    ll cnt, u, ans=0;
    for(ll i=1; i<(1ll<ps.size()); i++){
        u=1;
        cnt=0;
        for(int j=0; j<ps.size(); j++){
            if((1ll<<j)&i){
                cnt++;
                u*ps[j];
            }
        }
        if(cnt%2==1)    ans+=x/u;
        else            ans-=x/u;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll l, r; cin >>l>>r;
    ll ans = (r-l+1)*(r-l);
    vll ps={};
    // ll e = euler(r,ps);
    ll lre = l-1-re(l-1,ps);
    for(int i=l; i<=r; i++){
        // ans -= (r/i-l/i);
        ps.clear();
        gen_div(i, ps);
        ans -= (i-re(i,ps))+lre;
        cout << endl;
    }
    
    cout << ans << endl;
    
    return 0;
}
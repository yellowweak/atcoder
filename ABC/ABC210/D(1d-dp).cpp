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
int mod = 1000000007;
// END LIB
ll mx = LLONG_MAX - INT_MAX;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int H,W; cin>>H>>W;
    ll ans=LLONG_MAX,C; cin >> C;
    grid g(H, vll(W));  rep(i,0,H) cin>>g[i];
    // let ia<=ib for general
    // for ja<=jb, and reverse grid for ja>jb
    // dp[i][j]: min cost of (start point + "road" to (i,j))
    vll dp1(W+1, mx), dp2(W+1, mx);
    rep(i,1,H+1){
        rep(j,1,W+1){
            dp2[j] = min(g[i-1][j-1], min(dp1[j]+C, dp2[j-1]+C));
            if(i!=1||j!=1)  ans = min(ans, min(dp1[j], dp2[j-1])+g[i-1][j-1]+C);
        }
        swap(dp1,dp2);
    }
    rep(i,0,W+1) dp1[i]=dp2[i]=mx;
    rep(i,0,H){
        int l=0, r=W-1;
        while(l<r)  swap(g[i][l++], g[i][r--]);
    }

    rep(i,1,H+1){
        rep(j,1,W+1){
            dp2[j] = min(g[i-1][j-1], min(dp1[j]+C, dp2[j-1]+C));
            if(i!=1||j!=1)  ans = min(ans, min(dp1[j], dp2[j-1])+g[i-1][j-1]+C);
        }
        swap(dp1,dp2);
    }

    cout << ans<<endl;
    
    return 0;
}
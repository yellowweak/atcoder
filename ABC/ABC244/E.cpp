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
ll mod = 998244353;
// END LIB

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M, K, S, T, X;
    cin >>N>>M>>K>>S>>T>>X;
    S--; T--; X--;
    unordered_map<int, unordered_set<int>> G;
    grid dp(N, vll(2,0)),dp2(N, vll(2,0));
    unordered_set<int> us, us2;
    rep(i,0,M){
        int u, v;
        cin >>u>>v;
        u--;v--;
        G[u].emplace(v);
        G[v].emplace(u);
    }

    us.emplace(S);
    dp[S][0] = 1;
    dp[S][1] = 0;
    rep(i,0,K){
        for(auto cur:us){
            for(auto next:G[cur]) {
                us2.emplace(next);
                if(next==X){
                    dp2[next][0] = (dp2[next][0] + dp[cur][1])%mod;
                    dp2[next][1] = (dp2[next][1] + dp[cur][0])%mod;
                } else {
                    dp2[next][0] = (dp2[next][0] + dp[cur][0])%mod;
                    dp2[next][1] = (dp2[next][1] + dp[cur][1])%mod;
                }
            }
        }
        swap(us, us2);
        us2.clear();
        swap(dp, dp2);
        rep(j,0,N)  dp2[j][0] = dp2[j][1] = 0;
    }
    cout << dp[T][0];

    return 0;
}
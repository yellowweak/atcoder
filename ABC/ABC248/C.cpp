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
int N,M,K;
unordered_map<int, unordered_map<int, ll>> dp;

ll dfs(int pos, int remain){
    if(pos==N-1 && remain>M)
        return M;

    if(dp.count(pos)==0 || dp[pos].count(remain)==0){
        ll sum=0;
        int limit = min(M, remain-(N-pos-1));
        for(int i=limit; i>=1; i--){
            ll tmp = dfs(pos+1, remain-i);
            sum = (sum + tmp)%mod;
        }
        dp[pos][remain] = sum;
    }
    return dp[pos][remain];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M>>K;
    for(int i=M; i>=1; i--) dp[N-1][i] = i;
    cout << dfs(0,K);

    return 0;
}
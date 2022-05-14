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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin>>N;
    vll A(N); cin>>A;
    vector<array<ll, 2>> dp(N, array<ll, 2>({0,0}));
    vector<array<bool, 2>> picked_a0(N, array<bool, 2>());
    dp[0][0] = 0; picked_a0[0][0] = false;
    dp[0][1] = A[0]; picked_a0[0][1] = true;
    for(int i=1; i<N-1; i++){
        dp[i][0] = dp[i-1][1];
        picked_a0[i][0] = picked_a0[i-1][1];
        dp[i][1] = A[i];
        if(dp[i-1][0]==dp[i-1][1]){
            picked_a0[i][1] = picked_a0[i-1][0] | picked_a0[i-1][1];
        } else if(dp[i-1][0] < dp[i-1][1]){
            dp[i][1] += dp[i-1][0];
            picked_a0[i][1] = picked_a0[i-1][0];
        } else {
            dp[i][1] += dp[i-1][1];
            picked_a0[i][1] = picked_a0[i-1][1];   
        }
    }
    // dp[N-1][0]
    if(!picked_a0[N-2][1]){
        dp[N-1][0] = LLONG_MAX;
        dp[N-1][1] = A[N-1] + min(dp[N-2][0], dp[N-2][1]);
    } else {
        dp[N-1][0] = dp[N-2][1];
        dp[N-1][1] = A[N-1]+min(dp[N-2][0], dp[N-2][1]);
    }

    cout << min(dp[N-1][0], dp[N-1][1]);
    return 0;
}
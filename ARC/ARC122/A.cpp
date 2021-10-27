#include <bits/stdc++.h>
using namespace std;
// BEGIN LIB
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
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
int mod=1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N, ans=0; cin>>N;
    vll nums(N);
    cin>>nums;
    if(N==1){
        cout << nums[0] <<endl;
        return 0;
    }
    vector<vll> dp(N, vll(2));
    dp[0][0]=1; dp[0][1]=0;
    for(int i=1; i<N; i++){
        dp[i][0] = nums[i]*2+dp[i-1][0]+dp[i-1][1];
        dp[i][1] = -nums[i]+dp[i-1][0];
    }
    cout << ans <<endl;
    
    return 0;
}
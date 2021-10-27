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
void dfs(vll &nums, ll &ans, int pos, ll tmp_sum, bool prev_minus){
    if(pos==nums.size())    {ans = (ans+tmp_sum)%mod; return;}
    dfs(nums, ans, pos+1, tmp_sum+nums[pos], false);
    if(!prev_minus) dfs(nums, ans, pos+1, tmp_sum-nums[pos], true);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N, ans=0; cin>>N;
    vll nums(N);
    cin>>nums;
    if(N==1){
        cout << nums[0] <<endl;
        return 0;
    } else if(N==2){
        cout << (nums[0]*2)%mod <<endl;
        return 0;
    }
    dfs(nums, ans, 1, nums[0], false);
    cout << ans <<endl;
    
    return 0;
}
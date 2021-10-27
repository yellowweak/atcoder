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
    
    unordered_map<char,int> um={{'c',0},{'h',1},{'o',2},{'k',3},{'u',4},{'d',5},{'a',6},{'i',7}};
    string s; cin>>s;
    vll dp(8,0);
    for(char c:s){
        if(um.count(c)>0){
            if(um[c]==0) dp[0]++;
            else{
                dp[um[c]] = (dp[um[c]] + dp[um[c]-1])%mod;
            }
        }
    }
    cout << dp[7] <<endl;
    return 0;
}
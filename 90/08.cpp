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
    string s; cin>>s;
    unordered_map<char, int> order = {
        {'a',0},{'t',1},{'c',2},{'o',3},{'d',4},{'e',5},{'r',6}
    };
    vll dp(7, 0);
    for(int i=0; i<sz(s); i++){
        if(order.count(s[i])==0)   continue;
        int ord = order[s[i]];
        if(ord==0)  dp[ord] = (dp[ord]+1)%mod;
        else    dp[ord] = (dp[ord-1]+dp[ord])%mod;
    }

    cout << dp.back() << endl;

    return 0;
}
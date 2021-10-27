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
void dfs(int n, vector<set<string>> &dp){
    if(n==2){
        
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    map<int, set<string>> dp;
    dp[2] = {"()"};
    if(n%2==0){
        set<string> tmp;
        for(int l=4; l<=n; l+=2){
            tmp.clear();
            for(int i=2; i<l; i+=2){
                for(auto &L:dp[i])
                    for(auto &R:dp[l-i])
                        tmp.emplace(L+R);
            }
            for(auto &sub:dp[l-2])  tmp.emplace("("+sub+")");
            dp[l] = tmp;
        }
        for(auto &a:dp[n]) cout << a << endl;
    }

    return 0;
}
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

int ans = INT_MAX;
bool check(vi &P){
    for(int i=1; i<sz(P); i++){
        if(P[i]<P[i-1]) return false;
    }
    return true;
}
string hs(vi &P){
    string res="";
    for(auto x:P)   res+=to_string(x);
    return res;
}
void dfs(unordered_map<string, int> &H, vi &P, int step){
    if(step>=ans)   return;
    string str = hs(P);
    if(H.count(str)==0){
        // if()
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    vi P(N); cin>>P;
    unordered_map<string, int> H;
    dfs(H, P, 0);

    return 0;
}
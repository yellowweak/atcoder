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
    vi S(N); cin >>S;
    // S[i]<=1000
    unordered_set<int> us;
    rep(a,1,142){
        rep(b,1,142){
            us.emplace(4*a*b+3*a+3*b);
        }
    }

    int ans=0;
    for(auto s:S){
        if(us.count(s)==0)  ans++;
    }
    cout << ans;

    return 0;
}
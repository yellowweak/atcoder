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

    ll N, ans=0; cin>>N;
    vll cube, squre;
    // 100000000000^(1/3) = 4641.58883
    for(ll a=0; a<=4641; a++){
        cube.emplace_back(a*a*a);
    }
    // 100000000000^(1/2) = 316227.166
    for(ll a=0; a<=316227; a++){
        squre.emplace_back(a*a);
    }
    ll n3 = upper_bound(all(cube), N)-cube.begin()-1;
    for(ll a=1; a<=n3; a++){
        ll n2 = upper_bound(all(squre), N/a)-squre.begin()-1;
        for(ll b=a; b<=n2; b++){
            ans+=N/(a*b)-b+1;
        }
    }

    cout << ans;

    return 0;
}
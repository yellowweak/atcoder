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

    int H,W,C,Q;cin>>H>>W>>C>>Q;
    vector<array<int, 3>> qs(Q);
    vll ans(C,0);
    unordered_set<int> painted_r, painted_c;
    rep(i,0,Q){
        cin >> qs[i][0] >> qs[i][1] >> qs[i][2];
        qs[i][1]--; qs[i][2]--;
    }

    // draw from the last query to the first
    for(int i=Q-1; i>=0; i--){
        auto &[type, target, color] = qs[i];
        if(type==1) { // draw row
            if(painted_r.count(target)>0) continue;
            ans[color] += (W-sz(painted_c));
            painted_r.emplace(target);
        } else { // draw col
            if(painted_c.count(target)>0) continue;
            ans[color] += (H-sz(painted_r));
            painted_c.emplace(target);
        }
    }

    for(ll x:ans) cout << x << " ";

    return 0;
}
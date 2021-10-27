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
    
    int H,W; cin>>H>>W;
    vvi matrix(H, vi(W));
    vi row_sum(H,0), col_sum(W,0);
    rep(i,0,H)  cin>>matrix[i];
    rep(r,0,H){
        rep(c,0,W){
            row_sum[r]+=matrix[r][c];
            col_sum[c]+=matrix[r][c];
        }
    }
    rep(r,0,H){
        rep(c,0,W){
            cout << (row_sum[r]+col_sum[c]-matrix[r][c]) << (c==W-1? '\n':' ');
        }
    }

    return 0;
}
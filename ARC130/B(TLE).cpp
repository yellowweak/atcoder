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
    // int t,n,c;
    vector<array<int, 3>> qs(Q);
    // unordered_map<int, vector<int>> rc, cc;
    vll ans(C,0);
    vi qr, qc;
    rep(i,0,Q){
        cin >> qs[i][0] >> qs[i][1] >> qs[i][2];
        qs[i][1]--;
        qs[i][2]--;
        if(qs[i][0]==1) qr.emplace_back(qs[i][1]);
        else            qc.emplace_back(qs[i][1]);
    }
    sort(all(qr));
    sort(all(qc));
    qr.erase(unique(all(qr)), qr.end());
    qc.erase(unique(all(qc)), qc.end());
    grid s_board(qr.size(), vll(qc.size(),-1));
    unordered_map<int,int> newr, newc;
    for(int i=0; i<sz(qr); i++) newr[qr[i]]=i;
    for(int i=0; i<sz(qc); i++) newc[qc[i]]=i;
    vi rc(sz(qr)), cc(sz(qc));

    for(auto &[t,target,c]:qs){
        if(t==1){ // draw row
            rc[newr[target]] = c;
            for(int i=0; i<sz(qc); i++)
                s_board[newr[target]][i] = c;
        }
        else{ // draw col
            cc[newc[target]] = c;
            for(int i=0; i<sz(qr); i++)
                s_board[i][newc[target]] = c;
        }
    }

    rep(r,0,sz(qr))rep(c,0,sz(qc)){
        ans[s_board[r][c]]++;
    }
    rep(i,0,sz(rc)){
        ans[rc[i]]+=(W-sz(qc));
    }
    rep(i,0,sz(cc)){
        ans[cc[i]]+=(H-sz(qr));
    }
    for(ll x:ans) cout << x << " ";

    return 0;
}
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
    int n, q; cin >> n;
    ll cnt=0;
    vi R(n), C(n); cin >>R>>C;
    vector<pii> RY(n), CX(n);
    for(int i=0; i<n; i++){
        RY[i] = {R[i], i};
        CX[i] = {C[i], i};
    }    
    sort(RY.rbegin(), RY.rend());
    sort(CX.rbegin(), CX.rend());
    vi RR(n), CC(n);
    for(int i=0; i<n; i++){
        RR[RY[i].second] = i;
        CC[CX[i].second] = i;
    }

    cin>>q;
    int qr, qc;
    rep(i,0,q){
        cin >> qr>>qc;
        cout << ((RR[qr-1]+CC[qc-1]<n)? '#':'.');
    }
    

    return 0;
}
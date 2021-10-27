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
int mod = 998244353;
// END LIB
ll pow2[2000001];
ll dfs(int N, int D){
    if(D>2*(N-1))   return 0;
    int l=max(D-(N-1),0), r=D-l;
    // LR=(0,2) => 2_2 + 2_0*2_0 + 2_2
    // LR=(0,3) => 2_3 + 2_0*2_1 + 2_1*2_0 + 2_3
    // LR=(1,3) => 2_0*2_2 + 2_1*2_1 + 2_2*2_0
    // [2^(a-1+b-1)]*(b-a-1) + 2^(b+1)

    ll wr; // path with root
    if(l>0) wr=(r-l+1)*(pow2[l-1]*pow2[r-1]%mod)%mod;
    else{
        wr=(r-l-1)*pow2[l+r-2]%mod; // l+r=D <= 2*N-1
        wr = (wr+2*pow2[r-1])%mod;
    }
    wr = wr*2%mod;
    ll wor = dfs(N-1,D)*2%mod; // path without root
    return (wor+wr)%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N,D; cin>>N>>D;
    pow2[0]=1;
    for(int i=1; i<2*N; i++) pow2[i] = (pow2[i-1]*2)%mod;
    
    cout << dfs(N,D);

    return 0;
}
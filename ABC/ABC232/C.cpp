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

    int N,M,s,e; cin >>N>>M;
    vector<vector<bool>> G1(N, vector<bool>(N, false)), G2(N, vector<bool>(N, false));
    vector<array<int, 2>> E(M);
    rep(i,0,M){
        cin >> s>>e;
        s--;e--;
        E[i][0] = s;
        E[i][1] = e;
    }
    rep(i,0,M){
        cin >> s>>e;
        s--;e--;
        G2[s][e] = G2[e][s] = true;
    }
    vi P = {};
    for(int i=0; i<N; i++)  P.emplace_back(i);
    do{
        bool same = true;
        rep(m,0,M)if(same){
            auto [s, e] = E[m];
            same = G2[P[s]][P[e]];
        }
        if(same) {
            cout << "Yes";
            return 0;
        }
    }while(next_permutation(all(P)));
    cout << "No";

    return 0;
}
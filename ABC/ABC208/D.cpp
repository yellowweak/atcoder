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
// END LIB

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N,M,A,B,C;cin>>N>>M;
    ll ans=0, sum=0, INF=LLONG_MAX/2;
    vector<vector<pii>> G(400);
    grid f(N, vll(N,INF));
    rep(i,0,N)  f[i][i]=0;
    rep(i,0,M){
        cin>>A>>B>>C;
        G[A-1].emplace_back(B-1,C);
        f[A-1][B-1]=C;
    }
    rep(k,0,N){
        for(int s=0; s<N; s++){
            for(int t=0; t<N; t++){
                if(f[s][t]>f[s][k]+f[k][t]){
                    f[s][t] = f[s][k]+f[k][t];
                }
            }
        }
        for(int s=0; s<N; s++){
            for(int t=0; t<N; t++){
                ans+=f[s][t]==INF? 0:f[s][t];
            }
        }
    }
    cout << ans <<endl;
    return 0;
}
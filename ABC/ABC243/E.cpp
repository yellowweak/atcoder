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

    int N, M; cin>>N>>M;
    grid C(N, vll(N, LLONG_MAX)), dist(N, vll(N, LLONG_MAX));
    vi A(M), B(M);
    rep(i,0,M){
        int a,b; ll cost;
        cin>>a>>b>>cost;a--;b--;
        C[a][b] = cost;
        C[b][a] = cost;
        dist[a][b] = dist[b][a] = cost;
        A[i] = a;
        B[i] = b;
    }

    for(int i=0; i<N; i++)  dist[i][i]=0;
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(dist[i][k]==LLONG_MAX||dist[k][j]==LLONG_MAX)    continue;
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }
    int ans=0;
    rep(i,0,M){
        if(dist[A[i]][B[i]]<C[A[i]][B[i]])  {ans++;continue;}
        for(int k=0; k<N; k++){
            if(k==A[i]||k==B[i])    continue;
            if(dist[A[i]][k]+dist[k][B[i]]==C[A[i]][B[i]]) {ans++;break;}
        }
    }

    cout << ans;

    return 0;
}
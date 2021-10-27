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

void dfs(vvi &G, int parent, int cur, vi &dist, int depth){
    for(auto next:G[cur])if(next!=parent){
        dist[next] = depth+1;
        dfs(G, cur, next, dist, depth+1);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, u, v; cin >> N;
    vvi G(N);
    vi dist(N,0);
    rep(i,0,N-1){
        cin>>u>>v;
        u--;v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs(G, -1, 0, dist, 0);
    auto it = max_element(all(dist));
    int max_i = it-dist.begin();
    dist[max_i] = 0;
    dfs(G, -1, max_i, dist, 0);
    auto ans = max_element(all(dist));
    cout << (*ans+1);
    return 0;
}
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

void dfs(unordered_map<int,vi> &adj, vector<bool> &visited, int root, int h, vi &dis){
    visited[root] = true;
    dis[root] = h;
    for(int next:adj[root]){
        if(visited[next]) continue;
        dfs(adj,visited,next,h+1,dis);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N,Q,a,b,c,d,pos=0,root; cin>>N>>Q;
    vi pa(N), dis(N,0);
    rep(i,0,N)  pa[i]=i;
    unordered_map<int,vi> adj;
    rep(i,0,N-1){
        cin >> a >> b;
        a--;b--;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    vector<bool> v(N, false);
    dfs(adj,v,0,0,dis); // dis: height to the root

    rep(i,0,Q){
        cin>>c>>d;
        c--;d--;
        cout << (abs(dis[c]-dis[d])%2==0? "Town":"Road") <<endl;
    }
    
    return 0;
}
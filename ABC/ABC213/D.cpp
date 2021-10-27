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

void dfs(grid &adj,vector<bool> &visited, int pos, vi &ans){
    ans.emplace_back(pos);
    visited[pos]=true;
    for(auto next:adj[pos]){
        if(!visited[next]){
            dfs(adj, visited, next, ans);
            ans.emplace_back(pos);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N,a,b; cin>>N;
    vi ans;
    vector<bool> visited(N,false);
    grid adj(N);
    rep(i,0,N-1){
        cin>>a>>b;
        adj[a-1].emplace_back(b-1);
        adj[b-1].emplace_back(a-1);
    }
    for(int i=0; i<adj.size(); i++) sort(all(adj[i]));

    dfs(adj,visited,0, ans);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i]+1 << (i==ans.size()-1? '\n':' ');
    }

    return 0;
}
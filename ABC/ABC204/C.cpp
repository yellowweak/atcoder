#include <bits/stdc++.h>
using namespace std;
// BEGIN LIB
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;
typedef pair<ll, ll> pll;
// END LIB
void dfs(unordered_map<int, vi> &adj, vector<bool> &visited, int root, int &reached){
    if(visited[root])   return;
    reached++;
    visited[root]=true;
    for(auto next:adj[root])
        dfs(adj, visited, next, reached);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, u, v, ans=0, INF=1000000;
    cin >> N >> M;
    vector<bool> visited(N);
    unordered_map<int, vi> adj;
    rep(i,0,M){
        cin >> u >> v;
        adj[u-1].push_back(v-1);
    }
    rep(i,0,N){
        int reached=0;
        rep(j,0,N) visited[j]=false; 
        dfs(adj, visited, i, reached);
        ans+=reached;
    }
    cout <<ans<<endl;
    return 0;
}
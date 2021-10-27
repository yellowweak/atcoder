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

void dfs(unordered_map<int, unordered_set<int>> &adj, unordered_map<int, bool> &visited, int pos){
    visited[pos]=true;
    for(auto next:adj[pos]){
        if(!visited[next])  dfs(adj, visited, next);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N; cin>>N;
    vi nums(N);
    unordered_set<int> us;
    unordered_map<int, bool> visited;
    for(auto &v:nums){
        cin>>v;
        us.emplace(v);
        visited[v]=false;
    }
    
    // build graph
    unordered_map<int, unordered_set<int>> adj;
    rep(i,0,N/2){
        if(nums[i]!=nums[N-i-1]){
            adj[nums[i]].emplace(nums[N-i-1]);
            adj[nums[N-i-1]].emplace(nums[i]);
        }
    }

    // count connect components by dfs
    int ans_max=us.size(), cmpnts=0;
    for(auto &start:us){
        if(!visited[start]){
            cmpnts++;
            dfs(adj,visited,start);
        }
    }
    
    cout << ans_max - cmpnts << endl;
    
    return 0;
}
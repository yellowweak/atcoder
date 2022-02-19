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

    int N,M; cin>>N>>M;
    vll H; cin >> H;
    vector<unordered_map<int, ll>> G;
    rep(i,0,M){
        int u, v;
        cin>>u>>v;u--;v--;
        G[u][v] = (H[u]>H[v])? -(H[u]-H[v]):-2*(H[v]-H[u]);
        G[v][u] = (H[v]>H[u])? -(H[v]-H[u]):-2*(H[u]-H[v]);
    }

    vector<bool> visited(N, false);
    visited[0] = true;
    priority_queue<pll> pq;
    vll anss(N, LLONG_MAX/2);
    anss[0] = 0;
    pq.emplace(0,0);
    while(!pq.empty()){
        auto [l, pos] = pq.top();
        pq.pop();
        for(auto [next, cost]:G[pos]){
            if(visited[next])   continue;
            visited[next] = true;
            pq.emplace(l+cost, next);
            // anss
        }
    }


    // cout << ans << endl;

    return 0;
}
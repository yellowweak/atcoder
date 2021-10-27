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
    
    int N,M,A,B; cin>>N>>M;
    unordered_set<int> used={0};
    unordered_map<int, vi> adj;
    // vector<vector<ll>> city(N, {INT_MAX,0});
    vll city(N,0);
    // priority_queue<pll, vector<pll>, greater<pll>> pq;
    unordered_set<int> bfs,tmp;
    rep(i,0,M){
        cin>>A>>B;
        adj[A-1].emplace_back(B-1);
        adj[B-1].emplace_back(A-1);
    }
    city[0] = 1;
    bfs.emplace(0);
    while(!bfs.empty()){
        for(auto &c:bfs){
            for(auto next:adj[c]){
                if(used.count(next)==0){
                    city[next] = (city[c] + city[next])%mod;
                    tmp.emplace(next);
                }
            }
        }
        for(auto &c:tmp)    used.emplace(c);
        swap(bfs,tmp);
        tmp.clear();
    }
    cout << city.back()<<endl;

    return 0;
}
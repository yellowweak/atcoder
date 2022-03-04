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

void dfs(unordered_map<int, vi> &G, vi &X, unordered_map<int, vi> &sorted_nodes, int parent, int root){
    if(G[root].size()==0){
        sorted_nodes[root].emplace_back(X[root]);
        return;
    }
    priority_queue<int, vi, greater<int>> pq;
    pq.emplace(X[root]);
    for(auto next:G[root])if(next!=parent){
        dfs(G,X,sorted_nodes,root,next);
        for(auto n:sorted_nodes[next]){
            pq.emplace(n);
            // due to the constraint of K<=20
            if(pq.size()>20)    pq.pop();
        }
    }
    while(!pq.empty()){
        sorted_nodes[root].emplace_back(pq.top());
        pq.pop();
    }
    reverse(all(sorted_nodes[root]));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, Q; cin>>N>>Q;
    vi X(N); cin>>X;
    unordered_map<int, vi> sorted_nodes, G;
    rep(i,0,N-1){
        int A, B; cin>>A>>B;
        A--; B--;
        G[A].emplace_back(B);
        G[B].emplace_back(A);
    }

    dfs(G, X, sorted_nodes, 0,0);

    rep(i,0,Q){
        int V,K; cin>>V>>K;
        V--;
        cout << sorted_nodes[V][K-1] << endl;
    }
    
    return 0;
}
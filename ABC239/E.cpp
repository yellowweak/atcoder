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
void merge(vi &va, vi &vb){
    int ai=0, bi=0;
    vi tmp;
    while(ai<va.size()||bi<vb.size()){
        if(ai==va.size()){
            tmp.emplace_back(vb[bi++]);
        } else if(bi==vb.size()){
            tmp.emplace_back(va[ai++]);
        } else if(va[ai]<vb[bi]){
            tmp.emplace_back(va[ai++]);
        } else {
            tmp.emplace_back(vb[bi++]);
        }
    }
    swap(va, tmp);
}

void dfs(unordered_map<int, vi> &G, vi &X, unordered_map<int, vi> &sorted_nodes, int parent, int root){
    if(G[root].size()==0){
        sorted_nodes[root].emplace_back(X[root]);
        return;
    }
    sorted_nodes[root].emplace_back(X[root]);
    for(auto next:G[root])if(next!=parent){
        dfs(G,X,sorted_nodes,root,next);
        merge(sorted_nodes[root], sorted_nodes[next]);
    }
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
        int nth = sorted_nodes[V].size()-K;
        cout << sorted_nodes[V][nth] << endl;
    }
    
    return 0;
}
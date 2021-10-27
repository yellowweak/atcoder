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

// 1->0
// |
//\|/ 
// 3<-2

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N,M; cin>>N>>M;
    vi A(M), B(M), indeg(N,0), ans;
    vvi out_edges(N);
    rep(i,0,M){
        cin>>A[i]>>B[i];
        A[i]--;B[i]--;
        out_edges[A[i]].emplace_back(B[i]);
        indeg[B[i]]++;
    }
    priority_queue<int, vi, greater<int>> pq;
    rep(i,0,N)  if(indeg[i]==0) pq.emplace(i);
    while(!pq.empty()){
        int v = pq.top(); pq.pop();
        ans.emplace_back(v);
        for(auto n:out_edges[v]){
            if(indeg[n]==0) continue; // already in pq
            indeg[n]--;
            if(indeg[n]==0) pq.emplace(n);
        }
    }
    if(ans.size()<N){
        cout << -1;
        return 0;
    }
    for(auto a:ans) cout << a+1 << " ";

    return 0;
}
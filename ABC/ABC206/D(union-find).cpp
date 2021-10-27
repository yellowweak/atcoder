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

int find_root(unordered_map<int,int> &uf, int root){
    if(uf[root]!=root){
        uf[root] = find_root(uf, uf[root]);
    }
    return uf[root];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N; cin>>N;
    vi nums(N);
    unordered_map<int,int> uf;
    for(auto &v:nums){
        cin>>v;
        uf[v]=v;
    }
    
    rep(i,0,N/2){
        if(nums[i]!=nums[N-i-1]){
            int u=nums[i], v=nums[N-i-1];
            if(u>v) swap(u,v);
            int x=find_root(uf,u), y=find_root(uf,v);
            uf[y]=x;
        }
    }

    // count connect components by dfs
    int ans_max=uf.size(), cmpnts=0;
    for(auto [u,root]:uf){
        if(find_root(uf, u)==u)  cmpnts++;
    }
    
    cout << ans_max - cmpnts << endl;
    
    return 0;
}
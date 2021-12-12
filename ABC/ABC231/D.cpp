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

int find_root(vi &who, int x){
    if(who[x]!=x){
        who[x] = find_root(who, who[x]);
    }
    return who[x];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N,M,a,b; cin>>N>>M;
    unordered_map<int, vi> adj;
    vi who(N);
    rep(i,0,N)  who[i]=i;
    rep(i,0,M){
        cin >> a>>b;
        a--;b--;
        if(sz(adj[a])==2||sz(adj[b])==2){
            cout << "No";
            return 0;
        } else {
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
            int ra = find_root(who, a);
            int rb = find_root(who, b);
            if(ra==rb){
                cout << "No";
                return 0;
            } else {
                who[rb] = ra;
            }
        }
    }
    cout <<"Yes";

    return 0;
}
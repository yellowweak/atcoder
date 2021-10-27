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

unordered_map<string,int> um;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int M,u,v,hole=36; cin>>M;
    vvi G(9);
    vi p(8);
    string permu = "_________";
    queue<string> q;
    rep(i,0,M){
        cin >> u >> v;
        u--;v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    rep(i,0,8){
        cin >> p[i];
        p[i]--;
        hole-=p[i];
        permu[p[i]]='0'+i;
    }
    permu += ('0'+hole);
    um.emplace(permu,0);
    q.emplace(permu);
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int hole = cur.back()-'0';
        for(auto next_hole:G[hole]){
            string new_permu = cur;
            new_permu.back() = '0'+next_hole;
            swap(new_permu[hole], new_permu[next_hole]);
            if(um.count(new_permu)>0)   continue;
            um[new_permu] = um[cur] +1;
            q.emplace(new_permu);
        }
    }
    cout << (um.count("01234567_8")==0? -1:um["01234567_8"]);

    return 0;
}
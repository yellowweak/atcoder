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
    
    int N;cin>>N;
    int ans=0;
    vector<array<int,2>> pts(N);
    unordered_map<int, unordered_set<int>> um;
    rep(i,0,N){
        cin >> pts[i][0] >> pts[i][1];
        um[pts[i][0]].emplace(pts[i][1]);
    }
    sort(all(pts));
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            int ax=pts[i][0], ay=pts[i][1];
            int cx=pts[j][0], cy=pts[j][1];
            if(ax==cx || ay==cy)    continue;
            int bx=ax, by=cy;
            int dx=cx, dy=ay;
            if(um.count(bx)>0 && um[bx].count(by)>0 && um.count(dx)>0 && um[dx].count(dy)>0){
                ans++;
            }
        }
    }
    
    cout << ans/2;
    return 0;
}
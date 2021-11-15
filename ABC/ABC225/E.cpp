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

struct Arctan {
    ll x,y; // angle = y/x
    Arctan(ll x, ll y): x(x), y(y) {}
    // ly/lx <= ry/rx 
    bool operator<=(Arctan &rhs){
        return y*rhs.x <= x*rhs.y;
    }
    // ly/lx <= ry/rx (for sorting)
    bool operator<(const Arctan &rhs) const {
        return y*rhs.x < x*rhs.y;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin>>N;
    vector<pair<Arctan, Arctan>> sevens;
    rep(i,0,N){
        ll x,y; cin >> x>>y;
        sevens.emplace_back(make_pair(Arctan(x-1,y), Arctan(x,y-1))); // {endTime, startTime}
    }
    sort(all(sevens));
    Arctan cur(1,0); // start at angle zero 
    int ans=0;
    rep(i,0,N){
        if(cur <= sevens[i].second) {
            ans++;
            cur = sevens[i].first;
        }
    }
    cout << ans;

    return 0;
}
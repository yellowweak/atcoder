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
    int N,M,ans=INT_MAX; cin>>N>>M;
    vi A(N), B(M); cin >> A >> B;
    vector<pii> C;
    for(auto a:A)   C.emplace_back(make_pair(a,0));
    for(auto b:B)   C.emplace_back(make_pair(b,1));
    sort(all(C));
    for(int i=1; i<C.size(); i++){
        bool ab = (C[i].second+C[i-1].second==1);
        int d = abs(C[i].first-C[i-1].first);
        if(d<ans && ab) ans=d;
    }
    cout << ans << endl;

    return 0;
}
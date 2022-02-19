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

    int N; cin>>N;
    ll W,L; cin>>L>>W;
    vll A(N); cin>>A;

    vector<pll> ranges;
    ranges.emplace_back(A[0],A[0]+W);
    ll tail = A[0]+W;
    bool new_range = true;
    for(int i=1; i<N; i++){
        if(A[i]>ranges.back().second){
            ranges.emplace_back(A[i], A[i]+W);
        } else {
            ll l = min(ranges.back().first, A[i]);
            ll r = max(ranges.back().second, A[i]+W);
            ranges[sz(ranges)-1] = make_pair(l,r);
        }
    }
    ranges.emplace_back(L,L);
    ll ans = 0;
    tail = 0;
    for(int i=0; i<sz(ranges); i++){
        auto [l, r] = ranges[i];
        ans+=(l-tail+W-1)/W;
        tail = r;
    }

    cout << ans << endl;


    return 0;
}
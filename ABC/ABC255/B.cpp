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

    int K,N; cin>>N>>K;
    vi A(K); cin>>A;
    for(int i=0; i<K; i++)  A[i]--;
    vll X(N), Y(N);
    unordered_set<int> us;
    for(auto a:A)   us.emplace(a);
    rep(i,0,N){
        cin>>X[i]>>Y[i];
    }
    ll ans = 0;
    for(int i=0; i<N; i++){
        if(us.count(i)==0){
            ll ans_ = LLONG_MAX/2;
            for(auto a:A){
                ans_ = min(ans_, (X[i]-X[a])*(X[i]-X[a])+(Y[i]-Y[a])*(Y[i]-Y[a]));
            }
            ans = max(ans, ans_);
        }
    }
    cout.precision(17);
    cout << sqrt(ans);

    return 0;
}
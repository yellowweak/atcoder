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

    int N,Q; cin>>N;
    vi sum1(N+1,0), sum2(N+1,0);
    rep(i,0,N){
        int c, p;
        cin>>c>>p;
        sum1[i+1] = sum1[i] + (c==1? p:0);
        sum2[i+1] = sum2[i] + (c==2? p:0);
    }
    cin>>Q;
    rep(i,0,Q){
        int L,R; cin>>L>>R;
        int ans1 = sum1[R]-sum1[L-1];
        int ans2 = sum2[R]-sum2[L-1];
        cout << ans1 << " " << ans2 << endl;
    }

    return 0;
}
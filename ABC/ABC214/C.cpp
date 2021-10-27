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
    vi S(N), T(N); cin >> S >> T;
    vi ans(N);
    ans=T;
    rep(i,0,N){
        int pos=i;
        int timer=T[pos]+S[pos];
        pos = (pos+1)%N;
        rep(j,0,N-1){
            if(timer>=ans[pos])  break;
            else{
                ans[pos] = min(ans[pos], timer);
                timer += S[pos];
                pos = (pos+1)%N;
            }
        }
    }
    
    for(auto a:ans) cout << a << endl;
    return 0;
}
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
    
    ll N,A,B,P,Q,R,S;cin>>N>>A>>B>>P>>Q>>R>>S;
    // vector<string> ans(Q-P+1, string(S-R+1, '.'));

    // for(auto &s:ans) cout << s << endl;
    for(ll i=P; i<=Q; i++){
        for(ll j=R; j<=S; j++){
            if(i-A==j-B || i-A==B-j)cout <<'#';
            else cout << '.';
        }
        cout << endl;
    }

    return 0;
}
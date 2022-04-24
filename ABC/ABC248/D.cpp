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
    vi A(N); cin >>A;
    map<int, vi> st;
    for(int i=0; i<N; i++){
        st[A[i]].emplace_back(i);
    }
    int Q; cin>>Q;
    rep(i,0,Q){
        int L, R, X; cin >> L >> R>>X;
        if(st.count(X)==0){
            cout << 0 << endl;
            continue;
        }
        auto itr = upper_bound(all(st[X]), R-1);
        auto itl = lower_bound(all(st[X]), L-1);
        int r= *itr, l = *itl;
        int ans = itr-itl;
        cout << ans << endl;
    }

    return 0;
}
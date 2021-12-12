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
    ll ans=0;
    vi A(N), B(N); cin >> A>>B;
    vector<pii> AB(N), BX(N);
    rep(i,0,N)  AB[i] = make_pair(A[i], B[i]);
    sort(all(AB), [](pii &pa, pii &pb){
        if(pa.first==pb.first)  return pa.second < pb.first;
        return pa.first<pb.first;
    });
    rep(i,0,N)  BX[i] = make_pair(AB[i].second, i);
    sort(all(BX));
    vi BB(N);
    rep(i,0,N)  BB[i] = BX[i].first;
    rep(i,0,N){
        auto [a,b] = AB[i];
        int bu = upper_bound(all(BB), b)-BB.begin();
        for(int j=0; j<=bu; j++){
            if(BX[j].second<=i)    ans++;
        }
    }
    cout << ans;
    return 0;
}
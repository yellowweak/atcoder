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

    ll N, X, a; cin>>N>>X;
    vector<unordered_map<ll,ll>> L(N);
    rep(i,0,N){
        int l; cin >> l;
        rep(j,0,l){
            cin >> a;
            L[i][a]++;
        }
        vll discard;
        for(auto [aa,c]:L[i]){
            if(X%aa>0)   discard.emplace_back(aa);
        }
        for(auto x:discard) L[i].erase(x);
    }
    unordered_map<ll, ll> dp, dp2;
    dp[X] = 1;
    for(int i=0; i<N; i++){
        dp2.clear();
        if(dp.count(1)>0 && L[i].count(1)==0){
            dp.erase(1);
        }
        for(auto [x,xc]:dp){
            for(auto [aa, ac]:L[i]){
                if(x%aa==0){
                    dp2[x/aa]+=xc*ac;
                }
            }
        }
        swap(dp,dp2);
    }
    cout << dp[1];


    return 0;
}
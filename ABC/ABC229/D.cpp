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
bool ok(string &S, vi &SY, int m, int K){
    for(int i=0; i<=sz(S)-m; i++){
        if(SY[m+i]-SY[i] <=K)   return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string S; cin >>S;
    int K; cin >>K;
    vi SY={0};
    for(int i=0; i<sz(S); i++){
        SY.emplace_back(SY.back()+(S[i]=='.'? 1:0));
    }
    
    int l=0, r=sz(S)+1;
    while(r-l>1){
        int m = (l+r)/2;
        if(ok(S, SY, m, K))   l=m;
        else r=m;
    }
    cout << l;
    
    return 0;
}
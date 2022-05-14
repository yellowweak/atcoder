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
    vi T(N);
    vector<string> S(N);
    rep(i,0,N){
        cin>>S[i]>>T[i];
    }
    unordered_set<string> us;
    pii ans = make_pair(-1, 1);
    for(int i=0; i<N; i++){
        if(us.count(S[i])==0){
            us.emplace(S[i]);
            pii tmp = make_pair(T[i], -i);
            if(ans<tmp) ans = tmp;
        }
    }
    cout <<(-(ans.second))+1;

    return 0;
}
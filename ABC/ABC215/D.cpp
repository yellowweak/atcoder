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

void merge_primes(unordered_set<int> &ps, int a){
    for(int i=2; i*i<=a; i++){
        if(a%i==0){
            ps.emplace(i);
            while(a%i==0)   a/=i;
        }
    }
    if(a>1)     ps.emplace(a);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N,M; cin >> N >> M;
    vi A(N), ans; cin >> A;

    vector<bool> flags(M+1, true);
    unordered_set<int> ps;
    flags[0] = false;
    for(auto a:A)   merge_primes(ps, a);
    for(auto p:ps){
        for(int i=p; i<=M; i+=p)    flags[i]=false;
    }
    for(int i=1; i<=M; i++) if(flags[i]) ans.emplace_back(i);
    cout << ans.size() << endl;
    for(auto a:ans) cout << a << endl;
    
    return 0;
}
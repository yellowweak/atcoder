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
    vector<vector<string>> names(N, vector<string>(2));
    rep(i,0,N)  cin>>names[i];
    unordered_map<string, int> fn, ln;
    for(int i=0; i<N; i++){
        fn[names[i][0]]++;
        ln[names[i][1]]++;
    }
    bool go=true;
    for(int i=0; i<N&&go; i++){
        if(fn[names[i][0]]==1 && (ln.count(names[i][0])==0 || ln.count(names[i][0])==1 && names[i][0]==names[i][1]))  continue;
        if(ln[names[i][1]]==1 && (fn.count(names[i][1])==0 || fn.count(names[i][1])==1 && names[i][0]==names[i][1]))  continue;
        go = false;
    }
    cout << (go? "Yes":"No");

    return 0;
}
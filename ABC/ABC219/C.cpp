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

    string X;cin>>X;
    int order[26],N;cin>>N;
    vector<string> S(N); cin >> S;
    rep(i,0,26)     order[X[i]-'a']=i;
    sort(all(S), [&order](string &a, string &b){
        rep(i,0,min(sz(a),sz(b))){
            if(a[i]==b[i])  continue;
            return order[a[i]-'a']<order[b[i]-'a'];
        }
        return sz(a)<sz(b);
    });
    for(auto &s:S)  cout << s << endl;
    
    return 0;
}
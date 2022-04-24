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
    
    int N,K; cin>>N>>K;
    if(K==1){
        cout << "Infinity";
        return 0;
    }
    vi X(N), Y(N); cin>>X>>Y;
    unordered_map<string, int> cnt;
    for(int i=0; i<N; i++){
        cnt.clear();
        for(int j=0; j<N; j++){
            if(i==j)    continue;
            int dx = X[i]-X[j];
            int dy = Y[i]-Y[j];
            int gcd = __gcd(abs(dx), abs(dy));
            dx/=gcd; dy/=gcd;
            // if(dx<)
            string hash = to_string(dx)+'_'+to_string(dy);
        }
    }

    // ans /= K;

    return 0;
}
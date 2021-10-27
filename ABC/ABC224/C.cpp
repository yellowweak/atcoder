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

    int N;cin>>N;
    vector<array<ll,2>> p(N);
    rep(i,0,N){
        cin >> p[i][0] >> p[i][1];
    }
    int all = N*(N-1)*(N-2)/6, failed=0;
    for(int i=0; i<N-2; i++){
        for(int j=i+1; j<N-1; j++){
            for(int k=j+1; k<N; k++){
                ll tmp = p[i][0]*p[j][1] + p[j][0]*p[k][1] + p[k][0]*p[i][1]
                        -p[j][0]*p[i][1] - p[k][0]*p[j][1] - p[i][0]*p[k][1];
                if(tmp==0)  failed++;
            }
        }
    }
    cout << all-failed;

    return 0;
}
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
    vi A(N), B(N);
    rep(i,0,N)  cin >> A[i] >> B[i];
    vector<double> segs(N);
    rep(i,0,N)  segs[i] = ((double)A[i])/B[i];
    double sum=0;
    rep(i,0,N)  sum += segs[i];
    double time = sum/2, ans=0;
    cout.precision(18);
    int pos=0;
    while(time>1e-12){
        if(time>((double)A[pos])/B[pos]){
            ans += A[pos];
            time -= ((double)A[pos])/B[pos];
        } else {
            ans += time*B[pos];
            break;
        }

        pos++;
    }
    cout << ans << endl;
    return 0;
}
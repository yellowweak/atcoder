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

    int dir[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};
    int cur_d = 0;
    int x=0, y=0;
    int N; cin>>N;
    string S; cin>>S;
    rep(i,0,N){
        if(S[i]=='R'){
            cur_d = (cur_d+1)%4;
        } else {
            int dx = dir[cur_d][0];
            int dy = dir[cur_d][1];
            x+=dx; y+=dy;
        }
    }
    cout << x << " " << y;
    
    return 0;
}
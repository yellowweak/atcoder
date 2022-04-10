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

    int Q; cin>>Q;
    deque<pll> dq;
    rep(i,0,Q){
        int k; cin >> k;
        if(k==1){
            ll x,c; cin>>x>>c;
            dq.emplace_back(make_pair(x,c));
        } else {
            ll c, sum=0; cin >> c;
            while(c>0){
                auto [x,r] = dq.front(); dq.pop_front();
                if(r>c){
                    r-=c;
                    sum += x*c;
                    c=0;
                    dq.push_front(make_pair(x,r));
                } else {
                    c-=r;
                    sum += x*r;
                }
            }
            cout << sum << endl;
        }
    }

    return 0;
}
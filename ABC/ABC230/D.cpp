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
    
    int N,D,ans=0; cin>>N>>D;
    // vi L(N),R(N); cin>>L>>R;
    // map<int, int> mp;
    // rep(i,0,N){
    //     int l,r;
    //     mp[l] = r;
    // }
    vector<pii> vp;
    rep(i,0,N){
        int l,r;cin>>l>>r;
        vp.emplace_back(make_pair(l,r));
    }
    sort(all(vp), [](pii &pa, pii &pb){
        // if(pa.first==pb.first)  return pa.second<pb.second;
        // return pa.first<pb.first;
        return pa.second<pb.second;
    });

    
    for(int pos=0;pos<vp.size();){
        int limit = vp[pos].second+D-1;
        while(pos<sz(vp) && vp[pos].first<=limit){
            pos++;
        }
        ans++;
    }
    cout << ans;

    return 0;
}
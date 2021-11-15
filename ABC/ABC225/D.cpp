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
    
    int N,Q; cin>>N>>Q;
    vi prev(N), next(N);
    vvi groups(N);
    rep(i,0,N){
        next[i]=i;
        prev[i]=i;
    }
    rep(i,0,Q){
        int num, x, y;cin >> num;
        if(num==1){
            cin >> x>>y;
            x--;y--;
            prev[y] = x;
            next[x] = y;
        }
        if(num==2){
            cin >> x>> y;x--;y--;
            prev[y] = y;
            next[x] = x;
        }
        if(num==3){
            cin>>x;x--;
            int head = x;
            while(head != prev[head])   head = prev[head];
            vi ans(1,head);
            int cx = head, nx = next[head];
            while(cx!=nx){
                ans.emplace_back(nx);
                cx = nx;
                nx = next[nx];
            }
            cout << sz(ans) << " ";
            for(auto &a:ans)    cout << a+1 << " ";
            cout << endl;
        }
    }

    

    return 0;
}
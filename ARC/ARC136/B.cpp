#include <bits/stdc++.h>
#include <sstream>
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
    vector<vi> AB(2, vi(N));
    cin >> AB[0]>>AB[1];
    vi AA = AB[0], BB = AB[1];
    sort(all(AA));
    sort(all(BB));
    bool diff = false;
    for(int i=0; i<N&&!false; i++)
        if(AA[i]!=BB[i])    diff=true;
    if(diff){
        cout << "No" << endl;
        return 0;
    }

    bool kind[2]; // ~~1-2-3 type or ~~1-3-2 type
    // tricky bubble sort
    for(int k=0; k<2; k++){
        for(int i=N-2; i>=0; i--){
            for(int j=0; j<i; j++){
                if(AB[k][j+1]<=AB[k][j] && AB[k][j+1]<=AB[k][j+2]){
                    rotate(AB[k].begin()+j, AB[k].begin()+j+1, AB[k].begin()+j+3);
                } else if(AB[k][j+2]<=AB[k][j]&&AB[k][j+2]<=AB[k][j+1]){
                    rotate(AB[k].begin()+j, AB[k].begin()+j+2, AB[k].begin()+j+3);
                }
            }
        }
        // handle last bubble
        if(AB[k][N-1]<AB[k][N-2] || AB[k][N-2]<AB[k][N-3]){
            // 1 2 1 -> 1 1 2
            if(AB[k][N-1]==AB[k][N-3])  swap(AB[k][N-1], AB[k][N-2]);
        }
        kind[k] = AB[k][N-1]>=AB[k][N-2];
    }
    cout << (kind[0]==kind[1]? "Yes":"No") << endl;

    return 0;
}
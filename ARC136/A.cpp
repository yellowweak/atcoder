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

    // ABA
    int N; cin>>N;
    string S; cin>>S;
    string ans="";
    
    int ii=0;
    while(ii<N){
        if(ii+1==N){
            ans += S[ii++];
        } else if(S[ii+1]=='C'){
            ans += S[ii];
            ii++;
        } else if(S[ii]=='C'||S[ii]=='A'){
            ans += S[ii++];
        } else if(S[ii]=='B'){
            if(S[ii+1]=='A')    swap(S[ii], S[ii+1]);
            else{
                ans+='A';
                ii+=2;
            }
        }
    }
    cout << ans;

    return 0;
}
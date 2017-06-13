/*
Status : - Solved
Data Structure: - Map
Algorithm : - Implementation
*/
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b, ch) for(int i=a;i<b;i+=ch)
#define REP(i, a, b) for(int i=a, i<b;++i)
//#define ITR(i, a, b) for(it )
#define inp(t) cin>>t;
#define inp2(n, m) cin>>n>>m;
#define out(t)  cout<<t<<endl;
#define db(ds)   cout<<ds<<" ";
#define all(arr)    arr.begin(), arr.end()
typedef  long long ll;
#define  INF 999999
#define MOD 1000000007
#define fast ios::sync_with_stdio(false);

int main() {
    fast;
    int n, m;
    cin>>n>>m;
    while (n && m) {
        int x, ans=0;
        map<int, int > mii;
        for (int i = 0; i <n ; ++i) {
            cin>>x;
            ++mii[x];
        }
        for (int j = 0; j <m ; ++j) {
            cin>>x;
            ++mii[x];
            if(mii[x]==2){
                ++ans;
            }
        }
        cout<<ans<<endl;
        cin>>n>>m;
    }
    return 0;
}

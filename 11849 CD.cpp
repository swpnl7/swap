/*
Status :- Solved
Data Structure :- Set
Algo :- Implementation
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
    inp2(n, m);
    while (n && m) {
        int x, ans=0;
        set<int > si;
        set<int >::iterator itr;
        for (int i = 0; i <n ; ++i) {
            inp(x);
            si.insert(x);
        }
        for (int j = 0; j <m ; ++j) {
            inp(x);
            itr=si.find(x);
            if(itr!=si.end()){
                si.erase(itr);
                ++ans;
            }
        }
        out(ans);
        inp2(n,m);
    }
    return 0;
}

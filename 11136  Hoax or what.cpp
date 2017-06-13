/*
Status :- Solved
Data Structure :- Multiset
Algo :- Impementation
Time Complexity :- Including Input (days*(n*(x)+c))
*/
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b, ch) for(int i=a;i<b;i+=ch)
#define REP(i, a, b) for(int i=a, i<b;++i)
//#define ITR(i, a, b) for(it )
#define inp(t) cin>>t;
#define out(t)  cout<<t<<endl;
#define db(ds)   cout<<ds<<" ";
#define all(arr)    arr.begin(), arr.end()
typedef  long long ll;
#define  INF 999999
#define MOD 1000000007
#define fast ios::sync_with_stdio(false);

int main() {
    fast;
    int days;
    inp(days);
    while (days) {
        int n, x;
        ll ans = 0;
        multiset<int> msi;
        multiset<int>::iterator itrb, itre;
        for (int i = 0; i < days; ++i) {
            inp(n);
            for (int j = 0; j < n; ++j) {
                inp(x);
                msi.insert(x);
            }
            itrb = msi.begin();
            itre = msi.end();
            --itre;
            ans += *itre - *itrb;
            msi.erase(itrb);
            msi.erase(itre);
        }
        out(ans);
        inp(days);
    }
    return 0;
}

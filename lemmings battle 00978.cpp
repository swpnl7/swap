//-->110978 lemmings Battle--- Unsolved//
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b, ch) for(int i=a;i<b;i+=ch)
#define REP(i, a, b) for(int i=a, i<b;++i)
//#define ITR(i, a, b) for(it )
#define inp(t) cin>>t;
#define out(t)  cout<<t<<" ";
#define db(ds)   cout<<ds<<endl;
#define all(arr)    arr.begin(), arr.end()
typedef  long long ll;
#define  INF 999999
#define MOD 1000000007

int main() {
    int t;
    string ds;
    inp(t);
    while (t--) {
        int b, x, error1 = 1;
        unsigned long sg, sb;
        priority_queue<int> psg, psb;
        cin >> b >> sg >> sb;
        for (int i = 0; i < sg; ++i) {
            cin>>x;
            psg.push(x);
        }
        for (int i = 0; i < sb; ++i) {
            cin>>x;
            psb.push(x);
        }
        while (error1) {
            for (int i = 0; i < b; ++i) {
                if (!psg.empty() && !psb.empty()) {
                    if (psg.top() > psb.top()) {
                        psg.push((psg.top() - psb.top()));
                        psg.pop();
                        psb.pop();
                    } else if (psg.top() < psb.top()) {
                        psb.push(psb.top() - psg.top());
                        psg.pop();
                        psb.pop();
                    } else {
                        psg.pop();
                        psb.pop();
                    }
                } else {
                    error1 = 0;
                    break;
                }
            }
        }
        if (psg.empty() && !psb.empty()) {
            cout << "blue wins\n";
            sb=psb.size();
            for (int i = 0; i < sb; ++i) {
                cout << psb.top()<<endl;
                psb.pop();
            }
        } else if (psb.empty() && !psg.empty()) {
            cout << "green wins\n";
            sg=psg.size();
            for (int i = 0; i < sg; ++i) {
                cout << psg.top()<<endl;
                psg.pop();
            }
        } else {
            cout << "green and blue died\n";
        }
        cout<<endl;
    }
    return 0;
}

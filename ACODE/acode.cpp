#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B)	for(int I = (A); I < (B); ++I)
#define REP(I,N)	FOR(I,0,N)
#define ALL(A)		(A).begin(), (A).end()

using namespace std;

string test_case;

int main(){
    string t;
    cin >> t;
    while(t[0] != '0'){

        int n = t.size();
        vector<int> dp(n, 0);
        if(n == 1){
            cout << 1 << endl;
            cin >> t;
            continue;
        }
        dp[0] = 1;

        if(t[0] == '2' && t[1] != '0' && t[1] <= '6'){
            dp[1] = 2;
        } else if(t[0] == '1' && t[1] != '0'){
            dp[1] = 2;
        } else {
            dp[1] = 1;
        }

        FOR(i, 2, n){
            if(t[i-1] == '2' && t[i] != '0' && t[i] <= '6'){
                dp[i] = dp[i-2] + dp[i-1];
            } else if(t[i-1] == '1' && t[i] != '0'){
                dp[i] = dp[i-2] + dp[i-1];
            } else if(t[i] == '0') {
                dp[i] = dp[i-2];
            } else {
                dp[i] = dp[i-1];
            }
        }

        cout << dp[n-1] << endl;
        cin >> t;
    }
}

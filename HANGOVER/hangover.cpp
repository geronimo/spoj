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

int MAX = 290;

int main(){
    float n;
    float mem[MAX];

    mem[0] = 0;
    FOR(i, 1, MAX){
        mem[i] = mem[i-1] + 1.0/(i+1);
    }

    while(cin >> n){
        if(n == 0.0) break;

        FOR(i, 1, MAX)
            if(n >= mem[i-1] && n <= mem[i]){
                cout << i << " card(s)" << endl;
                break;
            }
    }
}

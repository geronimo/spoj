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
    long long a, b, c;
    cin >> a >> b >> c;
    while(true){
        if(a==0 && b==0 && c==0) break;
        if(a - b == b - c){
            cout << "AP " << c + b - a << endl;
        }
        else{
            cout << "GP " << c * (b / a) << endl;
        }
        cin >> a >> b >> c;
    }
}

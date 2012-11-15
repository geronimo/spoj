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
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

#define FOR(I,A,B)	for(int I = (A); I < (B); ++I)
#define REP(I,N)	FOR(I,0,N)
#define ALL(A)		(A).begin(), (A).end()

vector< vector<int> > rec(1001, vector<int>(2, 0));
vector< vector<int> > mem(1001, vector<int>(1001, 0));

int dp_function(int n, int orientation){
    if(mem[n][orientation]) return mem[n][orientation];

    int tmp;
    if(n==0) 
        tmp = rec[n][orientation];
    else
        tmp = _max( dp_function(n-1, 0) + _abs(rec[n-1][1] - rec[n][(orientation+1)%2]) + rec[n][orientation],
                    dp_function(n-1, 1) + _abs(rec[n-1][0] - rec[n][(orientation+1)%2]) + rec[n][orientation]);
    mem[n][orientation] = tmp;
    return tmp;
}

int main(){
    int n;
    cin >> n;
    FOR(i, 0, n){
        int a, b;
        cin >> a >> b;
        rec[i][0] = a;
        rec[i][1] = b;
    }
    cout << _max(dp_function(n-1, 0), dp_function(n-1, 1)) << endl;
}

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

int calculate_envelop(bitset<4> bits, vector< vector<int> > rec){
    int result = 0;
    for(int i=0; i<rec.size()-1; i++){
        if(bits[i]){
            result += rec[i][0];
            if(bits[i+1]){
                result += _abs(rec[i+1][1] - rec[i][1]);
            } else {
                result += _abs(rec[i+1][0] - rec[i][1]);
            } 
        } else {
            result += rec[i][1];
            if(bits[i+1]){
                result += _abs(rec[i+1][1] - rec[i][0]);
            } else {
                result += _abs(rec[i+1][0] - rec[i][0]);
            } 
        }
    }
    if(bits[rec.size()-1]){
        result += rec[rec.size()-1][0];
    } else {
        result += rec[rec.size()-1][1];
    }
    return result;
}

int brute_force(vector< vector<int> > rec){
    int response = 0;
    for(int mask = 0; mask < pow(2, rec.size()); mask++){
        bitset<4> bits(mask);
        int result = calculate_envelop(bits, rec);
        //cout << bits << " " << result << endl;
        if(result > response){
            response = result;
        }
    }
    return response;
}

vector< vector<int> > rec(1001, vector<int>(2, 0));

int dp_function(int n, int orientation){
    if(mem[n][orientation]) return mem[n][orientation];
    if(n==0) return rec[n][orientation];
    return _max( dp_function(n-1, 0) + _abs(rec[n-1][1] - rec[n][(orientation+1)%2]) + rec[n][orientation],
                 dp_function(n-1, 1) + _abs(rec[n-1][0] - rec[n][(orientation+1)%2]) + rec[n][orientation]);
}

int main(){
    int n;
    while(cin >> n){
    FOR(i, 0, n){
        int a, b;
        cin >> a >> b;
        rec[i][0] = a;
        rec[i][1] = b;
    }

    vector<int> dp(n, 0);
    vector<int> direction(n, 0);

    if(rec[0][0] > rec[0][1]){
        dp[0] = rec[0][0];
        direction[0] = 0;
    } else {
        dp[0] = rec[0][1];
        direction[0] = 1;
    }

    FOR(i, 1, n){
        for(int mask = 0; mask < 4; mask++){
            int tmp = 0;
            if(i > 1) tmp += dp[i-2];

            bitset<2> bits(mask);
            int a = bits[0]; int no_a = (a+1)%2;
            int b = bits[1]; int no_b = (b+1)%2;

            tmp += rec[i][a] + rec[i-1][b]
                + _abs(rec[i][no_a] - rec[i-1][no_b]);
            if(i > 1){
                tmp += _abs(rec[i-1][no_b] - rec[i-2][(direction[i-2]+1)%2]);
            }

            if(tmp > dp[i]){
                dp[i] = tmp;
                direction[i] = a;
                direction[i-1] = b;
            }
        }
    }
    cout << _max(dp_function(n-1, 0), dp_function(n-1, 1)) << endl;
    }

    /*
    for(int i=0; i<100; i++){
        cout << 4 << endl;
        for(int i=0; i<4; i++){
            cout << rand() % 100 << " " << rand() % 100 << endl;
        }
    }
    */
}

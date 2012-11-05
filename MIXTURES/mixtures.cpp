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

int colors(int i, int j, vector<int> mixtures){
  int result = mixtures[i];
  FOR(x, i+1, j+1){
    result = (result + mixtures[x]) % 100;
  }
  return result;
}

int main(){
  int n;
  while(cin >> n){
    vector<int> mixtures(n);

    FOR(i,0,n){
      int tmp;
      cin >> tmp;
      mixtures[i] = tmp;
    }

    vector< vector<int> > costs(n, vector<int>(n, 100000000));
    FOR(i, 0, n){ costs[i][i] = 0; }
    vector<int> color(n, -1);

    FOR(l, 2, n + 1){
      FOR(i, 0, n - l + 1){
        int j = i + l - 1;
        FOR(k, i, j){
          int tmp = costs[i][k] + costs[k+1][j] + (colors(i, k, mixtures) * colors(k+1, j, mixtures));
          if(tmp < costs[i][j]){
            costs[i][j] = tmp;
          }
        }
      }
    }

    cout << costs[0][n - 1] << endl;
  }
}

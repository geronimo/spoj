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

int main(){
  int n;
  cin >> n;
  while(n--){

    string tmp;
    cin >> tmp;

    vector<int> numbers;
    vector<char> operators;

    FOR(i, 0, tmp.size()){
	if(i % 2 == 0){
	    numbers.push_back(atoi(&tmp[i]));
	} else {
	    operators.push_back(tmp[i]);
	}
    }

    //FOR(i, 0, numbers.size()){ cout << numbers[i] << endl; }
    //FOR(i, 0, operators.size()){ cout << operators[i] << endl; }

    vector< vector<int> > costs(numbers.size() + 1, vector<int>(numbers.size() + 1, 100000000));
    FOR(i, 0, numbers.size() + 1){ costs[i][i] = numbers[i]; }
/*    FOR(i, 0, numbers.size()){ 
	if(operators[i] == '+'){
            costs[i][i+1] = numbers[i] + numbers[i+1]; 
	}else if(operators[i] == '*'){
            costs[i][i+1] = numbers[i] * numbers[i+1]; 
	}
    } */

    int numbers_total = numbers.size();
    FOR(l, 2, numbers_total + 1){
      FOR(i, 0, numbers_total - l + 1){
        int j = i + l - 1;
        FOR(k, i, j){
	  int tmp = 0;
	  if(operators[k] == '+'){
              tmp = costs[i][k] + costs[k+1][j];
	  }else if(operators[k] == '*'){
              tmp = costs[i][k] * costs[k+1][j];
	  }
          if(tmp < costs[i][j]){
            costs[i][j] = tmp;
          }
        }
      }
    }

    cout << costs[0][numbers_total-1] << endl;
//    FOR(i,0,numbers_total){ FOR(j, 0, numbers_total) {
//    	cout << costs[i][j] << ' ';
//    } cout << endl; }
  }
}

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

int max_function(int i){
    if(i == 0){
        return 1;
    }
    else if(i == 1){
        if(test_case[i-1] == '2' && test_case[i] <= '6' && test_case[i] != '0'){
            return 2;
        }
        else if(test_case[i-1] == '1' && test_case[i] != '0'){
            return 2;
        }
        else{
            return 1;
        }
    }

    int result = 0;
    if(test_case[i-1] == '2' && test_case[i] <= '6' && test_case[i] != '0'){
        return max_function(i-2) + max_function(i-1);
    } else if(test_case[i-1] == '1' && test_case[i] != '0'){
        return max_function(i-2) + max_function(i-1);
    } else if(test_case[i] == '0') {
        return max_function(i-2);
    } else {
        return max_function(i-1);
    }
}

int main(){
    cin >> test_case;
    while(test_case.size() != 1 && test_case[0] != '0'){

        int n = test_case.size();
        cout << max_function(n-1) << endl;

        cin >> test_case;
    }
}

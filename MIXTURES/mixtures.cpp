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
	vector<int> test_case(4);
	test_case.push_back(50);
	test_case.push_back(60);
	test_case.push_back(70);
	test_case.push_back(90);

	for(int i=1; i<test_case.size()-1; i++){
		mix(min_mixture(0, i), min_mixture(i+1, test_case.size()));
	}
}

int min_mixture(i, j){
	long long mimin = 100000000000;

	if(i - j = 1){
		return test_case[i] * test_case[j] % 100;
	}
	else if(i == j){
		return test_case[i];

}



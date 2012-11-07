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
#define FORI(I,A,B)	for(int I = (A); I <= (B); ++I)
#define REP(I,N)	FOR(I,0,N)
#define ALL(A)		(A).begin(), (A).end()

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string test_case;
        cin >> test_case;

        if(test_case.size() == 1){
            if(test_case[0] == '9'){
                cout << 11 << endl;
            }
            else{
                cout << atoi(&test_case[0]) + 1 << endl;
            }
            continue;
        }

        bool changed = false;
        bool carry = false;
        bool tailing_one = false;
        int size = test_case.size() - 1;

        if(test_case.size() % 2 == 1){

            FORI(i, 0, test_case.size()/2){
                if(test_case[i] > test_case[size - i]){
                    test_case[size - i] = test_case[i];
                    changed = true;
                    carry = false;
                }
                else if(test_case[i] < test_case[size - i]){
                    test_case[size - i] = test_case[i];
                    carry = true;
                    changed = true;
                }
            }

            if(!changed || carry){
                if(test_case[test_case.size()/2] != '9'){
                    test_case[test_case.size()/2] += 1;
                }
                else{ 
                    for(int k = test_case.size()/2; k >= 0; k--){
                        if(k != 0 && test_case[k] == '9'){
                            test_case[k] = test_case[size-k] = '0';
                        }else if(k == 0  && test_case[k] == '9'){
                            test_case[k] = '1';
                            test_case[size] = '0';
                            tailing_one = true;
                            break;
                        }else{
                            test_case[k] += 1;
                            test_case[size-k] += 1;
                            break;
                        }
                    }
                }
            }
        }else{

            FORI(i, 0, test_case.size()/2 - 1){
                if(test_case[i] > test_case[size - i]){
                    test_case[size - i] = test_case[i];
                    changed = true;
                    carry = false;
                }
                else if(test_case[i] < test_case[size - i]){
                    test_case[size - i] = test_case[i];
                    carry = true;
                    changed = true;
                }
            }

            if(!changed || carry){
                if(test_case[test_case.size()/2 - 1] != '9'){
                    test_case[test_case.size()/2] += 1;
                    test_case[test_case.size()/2 - 1] += 1;
                }
                else{ 
                    for(int k = test_case.size()/2 - 1; k >= 0; k--){
                        if(k != 0 && test_case[k] == '9'){
                            test_case[k] = test_case[size-k] = '0';
                        }else if(k == 0  && test_case[k] == '9'){
                            test_case[k] = '1';
                            test_case[size] = '0';
                            tailing_one = true;
                            break;
                        }else{
                            test_case[k] += 1;
                            test_case[size-k] += 1;
                            break;
                        }
                    }
                }
            }
        }


        cout << test_case;
        if(tailing_one) cout << '1' << endl;
        else cout << endl;
    }
}

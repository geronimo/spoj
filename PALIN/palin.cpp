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
                continue;
            }
            cout << atoi(&test_case[0]) + 1 << endl;
            continue;
        }

        bool changed = false;
        bool carry = false;
        bool tailing_one = false;
        int size = test_case.size() - 1;

        int last_index;
        if(test_case.size() % 2 == 1){

            cout << "ENTRE" << endl;
            FORI(i, 0, last_index){

                if(test_case[i] == test_case[size - i]){
                    cout << "IGUAL" << endl;

                    if(i == size - i + 1){ // last element
                        if(carry){
                            if(test_case[i] == '9' && carry){
                                for(int k = i; i >= 0; i--){
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
                            else if(test_case[i] != '9'){
                                test_case[i] += 1;
                                test_case[size - 1] += 1;
                                changed = true;
                            }
                        }
                        else{
                            continue;
                        }
                    }
                    else{
                        continue;
                    }

                    if(i == size - i + 1 && carry){
                        if(test_case[i] == '9'){
                            test_case[i] = '0';
                            for(int k = i - 1; i >= 0; i--){
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
                        else{
                            changed = true;
                            test_case[i] += 1;
                            test_case[size - i] += 1;
                        }
                    }
                    else if(i == size - i + 1 && !changed){
                        if(test_case[i] == '9'){
                            test_case[i] = '0';
                            for(int k = i - 1; i >= 0; i--){
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
                        else {
                            changed = true;
                            test_case[i] += 1;
                            test_case[size - i] += 1;
                        }
                    }
                }
                else if(test_case[i] > test_case[size - i]){
                    cout << "MAYOR" << endl;
                    test_case[size - i] = test_case[i];
                    changed = true;
                    carry = false;
                }
                else if(test_case[i] < test_case[size - i]){
                    cout << "MENOR" << endl;
                    test_case[size - i] = test_case[i];
                    carry = true;
                    changed = true;
                }
            }
        }else{

        }


        cout << test_case;
        if(tailing_one) cout << '1' << endl;
        else cout << endl;
    }
}

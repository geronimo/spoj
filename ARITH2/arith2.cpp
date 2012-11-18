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
    string s;
    getline(cin, s);
    while(n--){
        getline(cin, s);
        getline(cin, s);

        string tmp = "";
        long long result = 0;
        char oper = '0';
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                continue;
            } else if(s[i] == '+' || s[i] == '*' ||s[i] == '/' || s[i] == '-' || s[i] == '='){
                if(oper == '0'){
                    result = atoll(tmp.c_str());
                } else if(oper == '+'){
                    result += atoll(tmp.c_str());
                } else if(oper == '-'){
                    result -= atoll(tmp.c_str());
                } else if(oper == '*'){
                    result *= atoll(tmp.c_str());
                } else if(oper == '/'){
                    result /= atoll(tmp.c_str());
                }

                if(s[i] == '='){
                    cout << result << endl;
                    break;
                }
                oper = s[i];
                tmp = "";
            } else {
                tmp += s[i];
            }
        }
    }
}

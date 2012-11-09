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

string strings_sum(string first, string last){
    int n;
    string result = "";
    if(first.size() > last.size()) n = first.size();
    else n = last.size();

    int carry = 0;
    for(int i = 0; i < n; i++){

        int sum = 0;
        if(first.size() <= i){
            int y = last[i] - '0';
            sum = y + carry;
        }
        else if(last.size() <= i){
            int x = first[i] - '0';
            sum = x + carry;
        }
        else{
            int x = first[i] - '0';
            int y = last[i] - '0';
            sum = x + y + carry;
        }
        carry = 0;

        if(sum < 10){
            result += (char) sum + '0';
            carry = 0;
        }
        else{
            result += (char) sum%10 + '0';
            carry += sum / 10;
        }
    }
    if(carry){
        result += (char) carry + '0';
    }
    return result;
}

void print_sum_subs(string first, string last, string result, int n, char oper){
    if(n < result.size())
        n = result.size();
    else if(n <= last.size())
        n++;

    for(int i=n-1; i>=0; i--){
        if(i >= first.size()) cout << " ";
        else cout << first[i];
    }
    cout << endl;
    for(int i=n-1; i>=0; i--){
        if(i > last.size()) cout << " ";
        else if(i == last.size()) cout << oper;
        else cout << last[i];
    }
    cout << endl;
    for(int i=n-1; i>=0; i--){
        cout << '-';
    }
    cout << endl;
    bool zero = true;
    for(int i=n-1; i>=0; i--){
        if(i >= result.size()) cout << " ";
        else{ 
            if(zero && result[i] == '0'){
                cout << " ";
            }else{
                cout << result[i];
                zero = false;
            }
        }
    }
    cout << endl;
}

int main(){
  int n;
  cin >> n;
  while(n--){

    string tmp;
    cin >> tmp;

    string first = "";
    string last = "";
    char oper;

    bool flag = false;
    REP(i, tmp.size()){
        if(!flag){
            if(tmp[i] != '+' && tmp[i] != '*' && tmp[i] != '-'){
                first = tmp[i] + first;
            }else{
                flag = true;
                oper = tmp[i];
            }
        }
        else {
            last = tmp[i] + last;
        }
    }

    string result = "";
    if(oper == '+'){
        int n;
        if(first.size() > last.size()) n = first.size();
        else n = last.size();

        result = strings_sum(first, last);
        print_sum_subs(first, last, result, n, oper);
    }
    else if(oper == '-'){
        int n;
        if(first.size() > last.size()) n = first.size();
        else n = last.size();

        int carry = 0;
        for(int i = 0; i < n; i++){

            int sum = 0;
            if(first.size() <= i){
                int y = last[i] - '0';
                sum = y - carry;
            }
            else if(last.size() <= i){
                int x = first[i] - '0';
                sum = x - carry;
            }
            else{
                int x = first[i] - '0';
                int y = last[i] - '0';
                sum = x - y - carry;
            }

            if(sum < 0){
                sum += 10;
                carry = 1;
            }
            else{
                carry = 0;
            }

            if(i != 0 || sum != 0){
                result += (char) sum + '0';
            }
        }
        print_sum_subs(first, last, result, n, oper);
    }
    else{
    }
    cout << endl;
  }
}

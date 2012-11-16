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

string strings_mult(string first, char c){
    if(c == '0') return "0";

    string result = "";
    int n = first.size();
    int carry = 0;
    for(int i=0; i<n; i++){
        int mult = (c - '0') * (first[i] - '0');
        mult += carry;

        if(mult < 10){
            result += (char) mult + '0';
            carry = 0;
        }
        else{
            result += (char) mult%10 + '0';
            carry = mult / 10;
        }
    }
    if(carry){
        result += (char) carry + '0';
    }
    return result;
}

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
    int zeros = 0;
    for(int x=result.size()-1; x>=0; x--){
        if(result[x] =='0') zeros++;
        else break;
    }
    int dashes = max(last.size()+1, result.size()-zeros);

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
        if(i >= dashes) cout << " ";
        else cout << '-';
    }
    cout << endl;
    for(int i=n-1; i>=0; i--){
        if(i >= result.size()-zeros) cout << " ";
        else{ 
            cout << result[i];
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
            if(i == 0 && sum == 0){
                result += (char) sum + '0';
            }
        }
        print_sum_subs(first, last, result, n, oper);
    }
    else{
        int n = last.size();
        vector< string > partials;
        string total;

        FOR(i, 0, n){
            string tmp = strings_mult(first, last[i]);
            partials.push_back(tmp);
            if(i == 0) total = tmp;
            else {
                string z = "";
                REP(j, i){ z += '0'; }
                total = strings_sum(total, z + tmp);
            }
        }

        int m = max(last.size()+1, partials[0].size());
        int j = last.size()-1 + partials[partials.size() - 1].size();
        int dashes = max((int)total.size(), j);
        n = max(m, j);
        n = max(n, (int)total.size());

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
            if(i >= m) cout << " ";
            else cout << '-';
        }
        cout << endl;

        if(partials.size() > 1){
            for(int x=0; x<partials.size(); x++){
                for(int i=n-1-x; i>=0; i--){
                    if(i >= partials[x].size()) cout << " ";
                    else cout << partials[x][i];
                }
                cout << endl;
            }
            for(int i=n-1; i>=0; i--){
                if(i >= dashes) cout << " ";
                else cout << '-';
            }
            cout << endl;
        }
        for(int i=n-1; i>=0; i--){
            if(i >= total.size()) cout << " ";
            else cout << total[i];
        }
        cout << endl;
    }
    cout << endl;
  }
}

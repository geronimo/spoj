#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define i64 long long
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        i64 a, b;
        cin >> a >> b;
        if(b==0){
            cout << 1 << endl;
            continue;
        }
        vector<int> ld;
        b %= 4;
        if(b == 0) b = 4;
        int tmp = 1;
        while(b--)
            tmp *= a;
        cout << tmp%10 << endl;
    }
}

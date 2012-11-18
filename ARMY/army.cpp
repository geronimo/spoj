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

        int ng, nm;
        cin >> ng >> nm;
        vector<int> ngs(ng), nms(nm);
        REP(i, ng) cin >> ngs[i];
        REP(i, nm) cin >> nms[i];

        sort(ngs.begin(), ngs.end());
        sort(nms.begin(), nms.end());

        int ig = 0, im = 0;
        while(true){
            if(ngs[ig] < nms[im]){
                ig++;
            } else if(ngs[ig] >= nms[im]){
                im++;
            }

            if(ig >= ngs.size()){
                cout << "MechaGodzilla" << endl;
                break;
            } else if(im >= nms.size()){
                cout << "Godzilla" << endl;
                break;
            }
        }
    }
}

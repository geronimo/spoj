#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <map>
#include <stdio.h>

using namespace std;

int main(){

    long long size = 32000;
    int criba[size];
    for(int i = 0; i < size; i++)
        criba[i] = 1;

    int count = 0;
    for(int i = 2; i < size; i++){
        if(criba[i]){
            count++;
            for(int k = i+i; k<size; k += i){
                criba[k] = 0;
            }
        }
    }

    int primes[count];
    int x = 0;
    for(int i = 2; i < size; i++){
        if(criba[i]){
            primes[x] = i;
            x++;
        }
    }

    bool empty_line = false;
    int c;
    cin >> c;
    while(c--){
        int n, m;
        cin >> n >> m;

        if(empty_line)
            fprintf(stdout, "\n");
        else empty_line = true;

        for(int i = n; i <= m; i++){
            if(i == 1) continue;
            bool prime = true;

            for(int k=0; k < count; k++){
                if(primes[k] > sqrt(i)) break;
                if(i%primes[k] == 0){
                    prime = false;
                    break;
                }
            }
            if(prime){
                fprintf(stdout, "%d\n", i);
            }
        }
    }
}


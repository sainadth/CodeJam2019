#include<iostream>
#include <bits/stdc++.h>
#include<set>
#include<algorithm>
using namespace std;
pair<int, int> primeFactors(int n){
    pair<int, int> temp;
    if(n%2 == 0){
        temp.first = 2;
        temp.second = n/2;
        return temp;
    }
    for(int i = 3; i <= sqrt(n); i++){
        if(n%i == 0){
            temp.first = i;
            temp.second = n/i;
            return temp;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int te;
    cin>>te;
    for(int i = 1; i <= te; i++){
        int limit; cin>>limit;
        int length; cin>>length;

        int primes[2*length];
        int products[length];
        for(int j = 0; j<length; j++){
            cin>>products[j];
        }
        for(int j = 0; j<length; j++){
            pair<int, int> temp = primeFactors(products[j]);
            if(temp.first == primes[2*j -1] || j == 0){
                primes[2*j] = temp.first;
                primes[2*j + 1] = temp.second;
            }
            else{
                primes[2*j] = temp.second;
                primes[2*j + 1] = temp.first;
            }
        }
        int dup[length+1];
        dup[0] = primes[0];
        dup[length] = primes[2*length -1];
        int k = 1;
        for(int j = 1; j < 2*length - 1; j+=2){
            dup[k++] = primes[j];
        }
        int dup1[length+1];
        copy(dup, dup+length+1, dup1);
        sort(dup1, dup1+ length+1);
        set<int> s(dup1, dup1+length+1);
        int alpha[s.size()];
        copy(s.begin(), s.end(), alpha);
        string decode = "";
        for(int j =0; j<=length; j++){
            decode += char(65+distance(alpha,find(alpha, alpha+s.size(), dup[j])));
        }
        cout<<"Case #"<<i<<": "<<decode<<endl;
    }
}

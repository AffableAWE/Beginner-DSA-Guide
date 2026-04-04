#include<iostream>
#include<string>
using namespace std;

int main() {
   string s;
   cin>> s;

   int charHash[256] = {0};
   for(int i = 0; i<s.size(); i++) {
       charHash[s[i]]++;
   }

   int q;
   cin>>q;
   while(q--) {
       char x;
       cin>> x;

       cout<< charHash[x] <<endl;
   }
   return 0;
}

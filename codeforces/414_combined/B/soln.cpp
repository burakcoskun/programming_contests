#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

double n,h;

void read_input(){
    cin >> n >> h;

    cout.precision(17);
    double p = 1; 

   double delta = (double)1/n;
   double res = sqrt(delta)/(1/h);
   cout << res << " ";

   p = res/h;
   double z = res;

//   cout << p <<" " << z << endl;


   for(int i = 0 ; i < n - 2; ++i){
       double a = (double)1 / (2*h);
       double b = (p*h+z) / (2*h);
       double c = -1*h/((double)(2*n));
       
       delta = b*b-4*a*c;
       
 //      cout << a << " " << b << " " << c <<" " << endl;
       res = (-1*b+sqrt(delta))/(2*a);
       cout << z + res << " ";
       z+=res;
       p = z / h;
    }
   cout << endl;
}

int main(){
    read_input();
    return 0;
}

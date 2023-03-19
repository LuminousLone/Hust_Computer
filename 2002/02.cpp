#include <iostream>

#include<cmath>

using namespace std;


// 得到x的位数
int getLen(int x){

int len = 1;

while(   x / (int)pow(10,len)  != 0  ) len ++;

return len;


}

int main()
{

  int num;


  while( cin >> num){

    if( num <1 || num > 10000) cout <<"Input err!\n";

    else{

    int n = pow(num,2);  // 平方

    if( n % (int)pow(10, getLen(num)) == num) cout << "YES!\n";

    else cout << "No!\n";


    }



  }



    return 0;
}

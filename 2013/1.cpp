#include <iostream>

#include<math.h>

using namespace std;



// 判断是否为素数
bool isS(int n){

 bool flag = true;

 for( int i=2; i<= n/2 ; i++ ){

    if( n % i == 0){

        flag = false;

        break;
    }

 }

 return flag;


}

int main()
{

   int m = 0;

   do{

    cout << "请输入整数m( 5<=m<=1000): ";

    cin >> m;

   }while( m <5 || m > 1000);



   for( int  k = m ; k >= 2 ; k --){

    if( isS(k)  && isS( k-2)){

        cout << k << " " << k-2<<endl;

        break;

    }




   }


    return 0;
}

#include <iostream>

#include<vector>

#include<iomanip>

using namespace std;



int main()
{

    int n;

    do{

        cout << "请输入阶数n(n>0): ";

        cin >> n;

    }while( n <= 0 );

    if( n == 1) cout << 1 << endl;

    else{


         int num[n][n];

    bool isRight = true; // 是否向左

    bool isDown = true ;  // 是否向下

    int  k =1 ; // 填入的值

    int  s = 1 ;  // 当前的圈数

   while(  k <= n * n){


    //右行
    for( int j = s-1 ; j <= n -s ;j ++){

      num[ s-1][j] = k;

      k++ ;

    }

    if( k >= n*n ) break;

    k -- ;

    // 下行
    for( int  i = s-1 ; i <= n-s ; i++) {

        num[i][ n-s] = k ;

        k ++ ;
    }

    k -- ;

    // 左行
    for( int j = n-s ; j >= s-1; j--){

        num[ n-s][j] = k;

        k++;
    }

    k--;

    // 上行
    for( int i = n-s ; i >= s ;  i -- ){

        num[i][s-1] = k;

        k++ ;

    }

    s ++;



   }


   for( int i = 0;i < n ;i++){

    for( int j =0 ;j<n ;j++)  cout<< setw(4) << num[i][j] ;

    cout << endl << endl;

   }





    }



    return 0;
}

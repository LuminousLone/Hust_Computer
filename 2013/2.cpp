#include <iostream>

#include<vector>

#include<iomanip>

using namespace std;



int main()
{

    int n;

    do{

        cout << "���������n(n>0): ";

        cin >> n;

    }while( n <= 0 );

    if( n == 1) cout << 1 << endl;

    else{


         int num[n][n];

    bool isRight = true; // �Ƿ�����

    bool isDown = true ;  // �Ƿ�����

    int  k =1 ; // �����ֵ

    int  s = 1 ;  // ��ǰ��Ȧ��

   while(  k <= n * n){


    //����
    for( int j = s-1 ; j <= n -s ;j ++){

      num[ s-1][j] = k;

      k++ ;

    }

    if( k >= n*n ) break;

    k -- ;

    // ����
    for( int  i = s-1 ; i <= n-s ; i++) {

        num[i][ n-s] = k ;

        k ++ ;
    }

    k -- ;

    // ����
    for( int j = n-s ; j >= s-1; j--){

        num[ n-s][j] = k;

        k++;
    }

    k--;

    // ����
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

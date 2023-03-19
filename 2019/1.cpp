#include <iostream>

#include<cmath>

#include<vector>

using namespace std;

bool isS(long n){

if( n <=2 ) return true;

bool flag = true;

for( int i = 2 ; i<= n/2 ; i++){

    if( n % i == 0) return !flag;

}

return flag;

}

int main()
{

    long int num ;

    cout << "Input(num >=3): ";

    do{


        cin >> num;

    }while(  num < 3 );


   vector<long> res;

    long i = 2;

    while( pow(2,i) - 1  < num ){

        if(  isS(pow(2,i)-1) ) res.push_back(i);

        i ++ ;

    }

    if( res.size() == 0) cout << "NULL!"<<endl;

    else{

        for( int  j = 0 ; j< res.size() ; j ++){


            cout << "M(" << res[j] << ")=" << pow(2,res[j]) - 1 << endl;

        }


    }


    return 0;
}

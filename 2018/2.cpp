#include <iostream>

#include<string>

#include<vector>

#include<cmath>

using namespace std;

const char TW[12] = { '0','1','2','3','4','5','6','7','8','9','a','b'};

int getIndex(char ch){

  for( int  i= 0 ; i< 12 ; i++){

    if( TW[i] == ch ) return  i ;
  }

}

int main()
{

    cout << "Input: ";

    string str ;

    cin >> str;

    vector<int> nums;

    // 输出每位对应十进制

    for( int i = 0 ; i< str.size() ; i++){

        int x = getIndex(str[i]);

        cout << x << " ";

        nums.push_back(x);
    }

    cout << endl;

    long long sum = 0 ;

    int px = 0 ;

    for( int i = nums.size() -1; i >= 0 ; i--){

        sum += nums[i] * pow(12,px);

        px ++ ;


    }

    cout << sum << endl;

    // 十进制转二进制

    vector<int> Th;

    int y = -1 ; // 余数

    while( sum !=0 ){

        y = sum % 2 ;

        Th.push_back(y);

        sum /= 2 ;
    }


    while(  Th.size() < 32) Th.push_back(0);


    int n = 0;

    for( int  i=Th.size()-1 ; i>=0 ;i-- ){

        cout << Th[i];

        n ++ ;

        if( n == 8){

            cout << " ";

            n = 0;
        }

    }


    return 0;
}

#include <iostream>

#include<vector>

using namespace std;



const int NUM = 6 ;



bool isS(int num){


bool flag = true;

if( num == 1 || num ==2) return flag;



for( int i = 2 ; i <= num/2 ; i++){

    if( num % i == 0) return !flag;

}

return flag;


}

int main()
{

    vector<int> nums ;

 for( int  i =1000 ; i<10000 ; i++){


        int s3 = i /10 ;

        int s2 = i / 100 ;

        int s1 = i / 1000 ;

        if(  isS(i) && isS(s3) && isS(s2) && isS(s1) ) nums.push_back(i);


    }


    int len = 0 ;

    for( int i = 0 ;i < nums.size() ; i ++){


        cout << nums[i] << "  ";

        len ++ ;

        if( len == 6 ){

            cout << endl;

            len = 0;
        }

    }




    return 0;
}

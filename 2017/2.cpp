#include <iostream>

#include<string>


#include<vector>

using namespace std;

const char num[] = { '0','1','2','3','4','5','6','7','8','9'}; // Êý×Ö×ª×Ö·û

int fromNumToStr(string s){

int sum  = 0;

for( int i = 0 ;i < s.size() ; i++) sum = sum*10 + s[i] - '0';

return sum;

}

int main()
{

  string nums;

  cout << "Input: ";

  cin >> nums;

  if( nums.size()%2 != 0 ) nums += '0'; //ÆæÊýÄ©Î²²¹0

  vector<int> v;

  string temp ="";

  int index = 0;

  while(  index < nums.size() ){   // ·Ö¸î×Ö·û´®¾¡Á¿ÓÃwhileÑ­»·

    temp += nums[index];

    if( (index +1) % 2== 0 ){

        v.push_back( fromNumToStr(temp) );

        temp = "";
    }

    index ++;

  }


 nums = "";

 temp = "";

  for( int  i =0 ;i < v.size() ; i++){


    v[i] += 32;

    nums += (char)v[i];


   /* for( int  j= 0; j < 2 ; j++){

        int x = v[i] % 10;

        temp.insert(temp.begin() , num[x] );

        v[i] /= 10 ;
    }


    nums += temp ;

    temp = "";
    */

  }

  cout << nums ;


    return 0;
}

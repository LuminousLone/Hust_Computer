#include <iostream>

#include<string>

#include<math.h>

using namespace std;

// 传入字符串,返回十进制
short changeStrToNum(string s){

  short sum = 0;

  int start = 0;

  if( s.size() > 16 ) start = s.size() - 16;


  int n = 0; //次方

  for( int i = s.size() - 1 ; i >= start ; i-- ){

    if( s[i] == '1') sum +=  pow(2,n);

    n ++ ;

  }

  return sum;


}
// 传入10进制，转成2进制字符串

string changeNumToStr(short num){


int start = 0 ;

while( pow(2,start) <= num ) start ++ ;

start -- ;

string res ;

while(  start >= 0 ){

    short temp = pow(2,start);

    if( num - temp >= 0 ){

        res +='1';

        num -= temp;

    }
    else{

        res += '0';
    }

    start -- ;


}

return res;


}

int main()
{



   string s1 , s2  ;

   char sign ;

   cin >> s1 >> s2 >> sign ;

   short x = changeStrToNum(s1);

   short y = changeStrToNum(s2);

   short res = 0;

   if( sign == '+') res = x + y;

   else if( sign == '-') res = x- y;

   else if( sign == '*') res = x * y;

   else if( sign =='/')  res = x/y;

   else cout << "输入的运算符不合法！";


   cout << changeNumToStr(res) << endl;








    return 0;
}

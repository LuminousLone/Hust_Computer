#include <iostream>

#include<string>

using namespace std;

bool isU(char ch){


if(  ch == 'u'  || ch == 'U') return true;

else return false;

}

bool isL(char ch){

if( ch == 'l' || ch == 'L') return true;

else return false;


}

bool isTen(string s){


if( s.size() <=0) return false;

if(  s[0]  <= '0'  || s[0] >'9')  return false;

bool flag = true ;

for( int i = 1; i < s.size() -2 ; i++){

    if(  s[i]  < '0' || s[i] > '9') return !flag ;

}

char ch1 = s[ s.size() - 1];

char ch2 =  s[ s.size() -2] ;

if( (isU(ch2) || (  ch2 >= '0' && ch2 <= '9')) && (  isL(ch1) || ( ch1 >= '0' && ch1 <= '9') )  ) return flag;

else return !flag;


}

// 8?
bool isE(string s){

if( s.size() <= 1 ) return false;

if( s[0] != '0') return false;

bool flag = true ;

for( int  i = 1 ; i < s.size() - 2  ; i++)

    if(  s[i]  < '0' || s[i] >= '8') return !flag ;



char ch1 = s[ s.size() - 1];

char ch2 =  s[ s.size() -2] ;


if((isU(ch2) || (  ch2 >= '0' && ch2 < '8')) && (  isL(ch1) || ( ch1 >= '0' && ch1 < '8') )  ) return flag;

else return !flag ;

}


bool is( char ch){


  return  (ch > '0' && ch < '9')  ||  (ch >= 'a' && ch <= 'f') || ( ch >= 'A' && ch <= 'F');

}

//16?
bool isS(string s){

if(  s.size() <= 3 ) return false;

if(  s[0] != '0'  || (  s[1] != 'x' &&  s[1] != 'X')  ) return false;

for( int  i = 2 ; i < s.size() - 2  ; i++){

     if( is(s[i]) ) continue;

    else return  false;
}



char ch1 = s[ s.size() - 1];

char ch2 =  s[ s.size() -2] ;

if( ( isU(ch2) || is(ch2) )  && (  isL(ch1)  || is(ch1) ) ) return true;

else return  false;



}




int main()
{


 string str ;

 while(  getline(cin,str)){


    if(  isTen(str) || isE(str) || isS(str)) cout << "YES"<<endl;

    else cout << "No\n";


 }




    return 0;
}

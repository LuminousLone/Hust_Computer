#include <iostream>

#include<string>

#include<algorithm>



using namespace std;

int main()
{

   string s1,s2;

   cout << "Input s1:";

   getline(cin,s1);

   cout << "Input s2:";

   getline(cin,s2);

   string s;

   s = s1 + s2;

   cout << "(1):\n"  << s << endl;

   string str1 ; //Ææ´®

   string str2 ; //Å¼´®

   for( int i = 0; i< s.size() ; i++){

      if( (i+1) % 2 == 0 ) str2 += s[i];

      else str1 += s[i];

   }

   cout<< "(2):\n" <<  str1  << endl << str2 << endl;


   sort( str1.begin() , str1.end() ) ;

   sort(  str2.begin() ,str2.end())  ;

   cout << "(3):\n" << str1  << endl << str2 ;



    return 0;
}

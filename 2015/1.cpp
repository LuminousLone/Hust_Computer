#include <iostream>

#include<string>

using namespace std;

bool isTwo(char ch){


 return ch == '3' || ch == '5' || ch == '6' || ch == '8';

}

bool isElse( char ch){

  return ch >= '0' && ch <= '9' ;

}

int main()
{

    cout << "Input: ";

    string str;

    getline(cin,str);


    if(  str.size() != 11) cout << "No"<<endl;

    else{

        char s1 = str[0];

        char s2 = str[1];

        bool flag = true;

        for( int  i =2 ; i<str.size() ; i++){

            if( ! isElse(str[i]) ){

                flag = false;

                break;

            }
        }


        if(  s1 == '1' &&  isTwo(s2)  && flag ) cout << "YES\n";

        else cout << "No\n";



    }


    return 0;
}

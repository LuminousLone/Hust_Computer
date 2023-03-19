#include <iostream>

#include<vector>

#include<cctype>

using namespace std;

const char UPPER[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q' ,'R','S','T','U',
                         'V','W','X','Y','Z' };

const char LOWER[]= { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

const int LEN = 26 ;

void printS( vector<char> &strs){


while(  strs.size() != 0 ){

    // 正向输出
    for( int  i =0 ; i< strs.size(); i++) cout << strs[i] << " ";

    //反向输出
    for( int i = strs.size()-2; i >=0 ; i--) cout << strs[i] << " ";


    cout << endl;

    strs.pop_back(); // 弹出最后


}


}

int main()
{

    vector<char> strs;

    char ch ;

    do{

        cout << "Input char: ";

        cin >> ch;

    }while( ! isalpha(ch) );



    if( islower(ch)){


        int i = 0;

        while( i < LEN  && ch != LOWER[i]){

            strs.push_back(LOWER[i]);

            i++ ;

        }

        strs.push_back(ch);

        printS(strs);


    }
    else if(  isupper(ch) ){

         int i = 0;

        while( i < LEN  && ch != UPPER[i]){

            strs.push_back(UPPER[i]);

            i++ ;

        }

        strs.push_back(ch);

        printS(strs);

    }
    else  cout << "err input!\n";



    return 0;
}

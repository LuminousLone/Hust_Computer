#include <iostream>

#include<string>

#include<map>

using namespace std;


int main()
{


string line;

cout<<"Input: ";

getline(cin,line);


int cut=0 ; // ���ʸ���

int len = 0; // ��ǰ���ʳ���

for( int i = 0 ; i < line.size() ; i++){

    if( line.at(i) != ' ' && line.at(i) != '.'){

        len ++ ;
    }
    else{

        if( len  != 0){

          cout << len << " ";

          cut ++;

          len = 0;

        }


    }


}






    return 0;
}

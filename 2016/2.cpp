#include <iostream>

#include<string>

#include<cctype>

#include<vector>

using namespace std;

// �Ƿ�����ĸ
bool isCh(char ch){


return (ch >='a' && ch <= 'z') || ( ch >= 'A' && ch <= 'Z');

}

bool isNum( char ch){

return ch >= '0' && ch <= '9';

}

int main()
{

  string str;

  cout << "Input string: ";

  getline(cin,str);

  // ȥ��ǰ��Ŀո�
  int  i = 0;

  while( str.at(i) == ' ') str.erase( str.begin());

  cout << str << endl;

  // �м����ո�ֻ����һ��
  for( int i = 0 ; i < str.size() ; i ++){

    if(  str.at(i) == ' ' && str.at(i-1) == ' ' ){

      str.erase( str.begin() + i);

      i -- ;

    }


  }

  cout << str << endl ;


  // ��������ĸ֮�����_

  for( int i =0 ; i< str.size() -1 ;i ++){

    if(  isCh( str.at(i)) && isNum( str.at(i+1)) ) str.insert( str.begin() + i +1 , '_');

    else if( isNum( str.at(i)) && isCh( str.at(i +1)) ) str.insert( str.begin() + i + 1 , '_');

    else continue;


  }




  cout << str << endl;


    return 0;
}

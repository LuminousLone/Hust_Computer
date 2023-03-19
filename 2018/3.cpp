#include <iostream>

#include<string>

#include<vector>

using namespace std;

// 字符串转10进制
unsigned int change(string s){

   unsigned int sum = 0;

   for( int i =0 ; i< s.size() ; i++){

     sum = sum * 10 + s[i] - '0';

   }

   return sum;

}

class ND{


unsigned int N;  // 被除数

unsigned int D;  // 除数

int s; // 商的整数部分

vector<int> *vectorY ;  // 商的小数部分

bool isW;  // 是否为循环小数

int start ; // 循环开始处

public:

    ND(string s){

      start = -1;

      isW = false;

      vectorY = new vector<int>;

      string temp = "";

      for( int  i = 0 ;i < s.size() ; i++){

          if( s[i] != '/') temp +=s[i];

          else{

            N = change(temp);

            temp = "";
          }


      }

      D = change(temp);


    }


    void countND(){

    if( D ==0 ) return ;

     s = N/D;

     int temp  = 0;

     int y = N % D;  // 余数



     // 小数部分  当某次出现的余数出现过，进入循环
    vector<int> yu;

    yu.push_back(y);

      while( y != 0 ){

        y = y *10;

        temp = y / D;

        y = y % D;

       vectorY->push_back(temp);

        for( int i=0 ; i< yu.size() ; i ++){

            if( yu[i] == y){

                isW = true;

                start = i;

                return ;

            }

        }

        yu.push_back(y);

      }
    }



    void printResult(){


    cout << N << '/' << D  << '=';

    if( D ==0 ){

      cout << "除数为0！\n";

      return ;
    }

    if( s != 0 ) cout << s;

    if( vectorY->size() == 0 ) return ;

    cout <<'.';

    if( isW  ){

        for(int i =0 ; i< vectorY->size() ; i++){

            if( i == start ) cout << '(';

            cout << vectorY->at(i);



        }

        cout << ')' ;
    }
    else{

           for(int  i= 0 ; i< vectorY->size() ; i++) cout << vectorY->at(i) ;
    }


    cout << endl;


    }

};

int main()
{



    string s1,s2,s3;

    cout << "Input: ";

    cin >> s1 >> s2 >> s3;


   ND n1(s1);

   n1.countND();

   n1.printResult();

   ND n2(s2);

   n2.countND();

   n2.printResult();

   ND n3(s3);

   n3.countND();

   n3.printResult();



    return 0;
}

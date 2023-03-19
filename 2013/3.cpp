#include <iostream>

#include<string>

using namespace std;

class MyStr{


string str;

int s; // 开始

int e ;  // 结束

bool isFind ; // 是否找到

public:

    MyStr(string str =" "){

      this->str = str;

      this->s = 0;

      this->e = 0;

      this->isFind = false;

    }

    // 找到回文开始、结束
    void findStr();

    // 判断两个字符是否广义相等
    bool isEqual(char a,char b);

    // 判断是否为大小写字母
    bool isCh(char ch);


    // 大写转小写，小写转大写
    char changeChar(char a);


    void printS(){

    if( isFind) {


        for( int i = this->s ; i <= this->e ; i++) cout << str[i];

        cout << endl;

    }
    else{

        cout << "并未找到长度大于二的回文串！\n";
    }

    }



};

char MyStr::changeChar(char a){

char res ;

int ch = 'a' - 'A';

if( a >= 'a' && a <= 'z') res = a - ch;

else  res = a + ch;


return res;




}

bool MyStr::isEqual(char a, char b){
     return  a == b  || changeChar(a) == b  ;
}


bool MyStr::isCh(char ch){

 return (ch >= 'a' && ch <= 'z') || (  ch >= 'A' && ch <= 'Z' );

}



void MyStr::findStr(){

int len = this->str.size();//长度

int left = 0;




while( left <= len - 2){



    char ch = this->str[left];

       //跳过开始端非字母
    while( !this->isCh(ch)){

        left ++ ;

        ch = this->str[left];
    }

    bool flag = false; //是否回文

    int right = len -1 ;


    while( right > left){

        char t = this->str[right];


        // 如果当前字符不是字母，跳过
        if( ! this->isCh(t) ){

            right -- ;

            continue;

        }

        // 如果不在回文中且不相等跳过

        if( !flag && !this->isEqual( ch , t)){

            right -- ;

            continue;

        }

        // 如果不在回文中，相等，进入回文
        if( !flag && this->isEqual( ch , t) ){

            flag = true;

            this->s = left ;

            this->e = right;

            while( left < right ){

                left ++ ;

                while( !isCh(str[left])) left ++;

                right -- ;

                while(! isCh(str[right])  ) right--;

                flag = this->isEqual( str[left],str[right]);

                if( !flag ) break;


            }

            //找到
            if( flag ){

                this->isFind = true;

                return  ;
            }
            // 没找到
            else{

                left = this->s;

                right = this->e;

                right -- ;

            }


        }





    }


    left ++ ;

}






}







int main()
{
    /*cout << 'a' - 'A' << endl; // 小写  > 大写


    MyStr my;

    cout << my.changeChar('a') << "  "<< my.changeChar( 'Z');*/



    string s ;

   do{

    cout << "请输入合法的字符串（1<=len<=5000）: \n";

    getline(cin,s);


   }while( s.size() < 1  || s.size() > 5000  );

   MyStr str(s);

   str.findStr();

   str.printS();

    return 0;
}

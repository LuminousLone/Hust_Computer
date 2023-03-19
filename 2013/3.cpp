#include <iostream>

#include<string>

using namespace std;

class MyStr{


string str;

int s; // ��ʼ

int e ;  // ����

bool isFind ; // �Ƿ��ҵ�

public:

    MyStr(string str =" "){

      this->str = str;

      this->s = 0;

      this->e = 0;

      this->isFind = false;

    }

    // �ҵ����Ŀ�ʼ������
    void findStr();

    // �ж������ַ��Ƿ�������
    bool isEqual(char a,char b);

    // �ж��Ƿ�Ϊ��Сд��ĸ
    bool isCh(char ch);


    // ��дתСд��Сдת��д
    char changeChar(char a);


    void printS(){

    if( isFind) {


        for( int i = this->s ; i <= this->e ; i++) cout << str[i];

        cout << endl;

    }
    else{

        cout << "��δ�ҵ����ȴ��ڶ��Ļ��Ĵ���\n";
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

int len = this->str.size();//����

int left = 0;




while( left <= len - 2){



    char ch = this->str[left];

       //������ʼ�˷���ĸ
    while( !this->isCh(ch)){

        left ++ ;

        ch = this->str[left];
    }

    bool flag = false; //�Ƿ����

    int right = len -1 ;


    while( right > left){

        char t = this->str[right];


        // �����ǰ�ַ�������ĸ������
        if( ! this->isCh(t) ){

            right -- ;

            continue;

        }

        // ������ڻ������Ҳ��������

        if( !flag && !this->isEqual( ch , t)){

            right -- ;

            continue;

        }

        // ������ڻ����У���ȣ��������
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

            //�ҵ�
            if( flag ){

                this->isFind = true;

                return  ;
            }
            // û�ҵ�
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
    /*cout << 'a' - 'A' << endl; // Сд  > ��д


    MyStr my;

    cout << my.changeChar('a') << "  "<< my.changeChar( 'Z');*/



    string s ;

   do{

    cout << "������Ϸ����ַ�����1<=len<=5000��: \n";

    getline(cin,s);


   }while( s.size() < 1  || s.size() > 5000  );

   MyStr str(s);

   str.findStr();

   str.printS();

    return 0;
}

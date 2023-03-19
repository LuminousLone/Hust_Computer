#include <iostream>

#include<string>

#include<vector>

using namespace std;

class Str{

vector<string> *arr;


public:

    Str(){

     this->arr = new vector<string>;

    }

    // ����n���ַ���
    void getArr(){

     string temp;

     cout << "������Ϸ��ַ�����ctrl+Z������"<<endl;

     while( getline(cin,temp)) this->arr->push_back(temp);


    }

     // �������
    void fPrint();



    void sortStr();



    bool isStr(string s){

    if( s.at(0) >= '0' && s.at(0) <= '9') return false;

    else return true;

    }


    long strToNum( string s){


      long sum = 0;

      int len = s.size();

      for( int i = 0; i< len ;i++)  sum += sum * 10 + s[i] - '0';


      return sum;

    }





    ~Str(){

      delete this->arr;
    }


};

void Str::fPrint(){

    if( this->arr->size() == 0) cout << "��δ�кϷ��ַ�����"<<endl;

    else{


        int n = this->arr->size();

        cout << "����"<<n << "���ַ�����\n";


        for( int i = 0; i < n ; i++){

            int len = this->arr->at(i).size();

            for( int  j= len-1;j>=0;j--)  cout << this->arr->at(i).at(j);

            cout << endl;

        }


    }



}


void Str::sortStr(){

    vector<string> myStr;  // ���ַ���

    vector<string>  myNum;  // ������

    vector<long> nums;


    int n = this->arr->size();

    for( int i=0 ; i< n ;i++){

        string s = this->arr->at(i);
        // ����Ǵ���ĸ
        if(  isStr(s)){

            int len1 = myStr.size();

            if( len1 == 0)  myStr.push_back(s);

            else{

               int k = 0;

               while( k < len1 && s >= myStr[k]) k++;

               myStr.insert( myStr.begin()+k,s);
               

            }

        }
        // ������
        else{

            long num = strToNum(s);

            int len = myNum.size();

            if( len == 0){

                myNum.push_back(s);

                nums.push_back(num);
            }
            else{

                int k = 0;

                while( k < len  && num >= nums[k]) k++;

                myNum.insert( myNum.begin() + k , s );

                nums.insert( nums.begin() + k , num );


            }



        }
    }

    cout << "�����Ĵ��ַ���...\n";

    for( int i = 0 ; i< myStr.size();i++)  cout << myStr[i] << endl;

    cout << "�����Ĵ�����...\n";

    for( int i = 0 ; i< myNum.size();i++)  cout << myNum[i] << endl;

}

int main()
{
    Str str;


    // ����n���ַ���
    str.getArr();

    cout << "�ַ�����������ϣ�"<<endl;

    // ����������ַ���
    cout << "��ʼ����������ַ�����\n";
    str.fPrint();

    //
    cout << "��ʼ����!\n";

    str.sortStr();
    

    return 0;
}

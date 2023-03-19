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

    // 输入n个字符串
    void getArr(){

     string temp;

     cout << "请输入合法字符串（ctrl+Z结束）"<<endl;

     while( getline(cin,temp)) this->arr->push_back(temp);


    }

     // 倒序输出
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

    if( this->arr->size() == 0) cout << "并未有合法字符串！"<<endl;

    else{


        int n = this->arr->size();

        cout << "共有"<<n << "个字符串！\n";


        for( int i = 0; i < n ; i++){

            int len = this->arr->at(i).size();

            for( int  j= len-1;j>=0;j--)  cout << this->arr->at(i).at(j);

            cout << endl;

        }


    }



}


void Str::sortStr(){

    vector<string> myStr;  // 纯字符串

    vector<string>  myNum;  // 纯数字

    vector<long> nums;


    int n = this->arr->size();

    for( int i=0 ; i< n ;i++){

        string s = this->arr->at(i);
        // 如果是纯字母
        if(  isStr(s)){

            int len1 = myStr.size();

            if( len1 == 0)  myStr.push_back(s);

            else{

               int k = 0;

               while( k < len1 && s >= myStr[k]) k++;

               myStr.insert( myStr.begin()+k,s);
               

            }

        }
        // 纯数字
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

    cout << "排序后的纯字符串...\n";

    for( int i = 0 ; i< myStr.size();i++)  cout << myStr[i] << endl;

    cout << "排序后的纯数字...\n";

    for( int i = 0 ; i< myNum.size();i++)  cout << myNum[i] << endl;

}

int main()
{
    Str str;


    // 接收n个字符串
    str.getArr();

    cout << "字符串已输入完毕！"<<endl;

    // 倒叙输出各字符串
    cout << "开始倒叙输出各字符串！\n";
    str.fPrint();

    //
    cout << "开始排序!\n";

    str.sortStr();
    

    return 0;
}

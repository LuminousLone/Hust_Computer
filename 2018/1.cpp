#include <iostream>

#include<string>

#include<cctype>

#include<vector>


using namespace std;


 int nums[26] = { 0 };

const char chn[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


int countWords(const string line){

int words = 1;

for( int i = 0 ; i< line.size() ; i++){


    if(  line.at(i) == ' ') words ++;


}

return words;

}


int main()
{



  string line;

  getline(cin,line);

  int alpha = 0 ; // 英文字母的个数

  int words = 1;  // 单词个数

  vector<char> ch; // 存放出现最多次数的字母

  vector<int> num ;  // 对应的次数




  for( int  i =0 ; i< line.size() ; i++)
  {

      char ch = line.at(i) ;


      if( isalpha( ch) )alpha++;

      else{

          if( line.at(i-1) == ' '){

            line.erase(line.begin() + i );

            i -- ;

          }

      }

   }



   cout<< "字母个数: " << alpha << endl;

   cout << "单词个数: " << countWords(line) << endl;


   for( int i = 0; i< line.size() ;i++){

        char c = line.at(i);


        if( c == ' ') continue;

        else{

          if( isupper(c)) c = tolower(c);

          nums[ (int)c - 'a'] ++ ;
        }





   }




   vector<int> index ; // 存放结果下标

   int maxA = nums[0] , maxi = 0;

   index.push_back(maxi);

   for( int  i = 1; i< 26 ;i ++){

      if(  nums[i] > maxA  ){

        index.clear();

        maxA = nums[i];

        maxi = i ;

        index.push_back(maxi);


      }
      else if( nums[i] == maxA){

        index.push_back(i);
      }


   }

   cout << "出现次数最多的字母: ";

   for( int  i = 0 ;i < index.size() ; i++){

      cout << chn[ index.at(i)] << " ";

   }

   cout << endl;

   cout << "出现次数: "  << nums[ index.at(0)];



    return 0;

}




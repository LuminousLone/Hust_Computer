#include <iostream>

#include<vector>

#include<string>

using namespace std;

void printNum(const vector<int>& v){

for( int i = v.size() -1; i >= 0; i--) cout << v[i];

cout << endl;

}


void solution( string num1str, string num2str){


   vector<int> num1;

    vector<int> num2;  // 左低右高

    for( int  i= 0; i< num1str.size() ; i++){

        num1.insert( num1.begin(), num1str[i] - '0');

    }


    for( int j = 0; j< num2str.size() ; j ++){

        num2.insert(num2.begin(), num2str[j] - '0');


    }


    vector<int> result;


    int x = 0 , y=0 ;  // x->num1,y->num2

    int z = 0 ; // 进位



    while( x < num1.size()  || y < num2.size()){

        // num1 已加完
        if( x >= num1.size()) result.push_back(num2[y]) ;  // 左低右高

        // num2 已加完
        else if( y >= num2.size( )) result.push_back( num1[x]);

        else{


            int temp = num1[x] + num2[y] + z;



            if( temp >= 10){

                z = 1;

                result.push_back( temp - 10); // 当前位结果

            }
            else{

                z = 0;

                result.push_back(temp);
            }

        }

        x ++ ;

        y ++;



    }


    printNum(result);

}

int main()
{
    string num1str;

    string num2str;

    cout << "Input :\n";


    while(      cin >> num1str  &&     cin >> num2str){

    solution(num1str,num2str);

    }






    return 0;
}

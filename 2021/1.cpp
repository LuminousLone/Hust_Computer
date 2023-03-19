#include <iostream>

#include<vector>

#include<algorithm>

using namespace std;

int main()
{

 int len;

 cin >> len;

 int n;

 vector<int> res;

 do{

    cin >> n;

    res.push_back(n);

 }while( cin.get() != '\n' );


 sort(res.begin(),res.end());

 for( int x : res) cout << x << " ";

 int i = 0 ,j = 1;

 while( j < res.size()){

    if( res.at(j) != res.at(i)){

        i ++ ;

        res.at(i) = res.at(j);
    }

    j++;

 }


 while( i < len-1){

    res.pop_back();

    i++;

 }

 cout << endl;

  for( int x : res) cout << x << " ";





    return 0;
}

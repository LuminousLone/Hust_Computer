#include <iostream>

#include<iomanip>

#include<vector>

#include<algorithm>

using namespace std;

const int N = 7 ;


int main()
{
    double sorce ;

    vector<double> nums;


    for( int  i =0 ;i < N ; i++){

        cout <<"Input " << i+1 << ": ";

        cin >>sorce;

        nums.push_back(sorce);


    }

    sort(nums.begin(),nums.end());

    nums.pop_back(); // 去掉最高

    nums.erase(nums.begin());  // 去掉最低


    double sum = 0.0;

    for( double x : nums) sum += x;

    cout<< fixed << setprecision(1) << sum / (N-2) << endl;




    return 0;
}

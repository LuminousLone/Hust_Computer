/*
梅森数，是指形如 2^p－1 的一类数，其中指数p是大于等于2的正整数，常记为M(p) 。
如果梅森数是素数，就称为梅森素数。
输入一个长整型数，然后输出比该数字小的梅森素数。
*/

//1. /* /* */ 这种嵌套调用情况，即多个左注释只需要找到第一个 */ 即可
//2. /*// 这种调用情况
//3.  或者 //*/ 或者 ///*这种情况，直接检索到行末即可
/* /* 
第1种情况
*/ 

/*//
第2种情况
*/

//第3种情况// 或者 //*/ 或者 ///* 
#include<stdio.h>
#include<math.h>
//判断素数
bool check(long n)
{
	long num = n;
	for(long i = 2; i < n/2; i++)
		if(n%i == 0)					//能够整除
			return false;				
	return true;
}
int main()
{
	long N, n, p = 2;
	scanf("%ld", &N);
	n = (long)(pow(2, p) - 1);
	while(n <= N)
	{
		if(check(n))
			printf("M(%ld) = %ld\n", p, n);		//打印结果
		p++;
		n = (long)pow(2, p) - 1;
	}
	return 0;
}




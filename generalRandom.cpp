// 产生1000以内的随机数
//#include <iostream>
#include <fstream>
#include <stdlib.h>

#define NUM 50 

std::ofstream fout("data.in");

int main()
{
	srand((unsigned)time(NULL)); // 用时间做种,每次产生随机数不一样
	for(int i=0; i<NUM; ++i)
	{
		fout << rand() % (1000-1)+1 << " ";
	}
	return 0;
}





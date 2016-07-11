// 选择排序:固定位置找元素
#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <unistd.h> // sleep(3);

std::ifstream fin("data.in");
std::ofstream fout("data.out");

#define MAX 1024*1024
// 升序,不稳定,时间复杂度O(n^2)
void chooseSort(int array[], int num)
{
	for(int i=0; i<num; ++i)
	{
		int value = array[i];
		int idx = i;
		for(int j=i; j<num; ++j)
		{
			if(array[j] < value)
			{
				value = array[j];
				idx = j;
			}
		}
		array[idx] = array[i];
		array[i] = value;
	}
}

long getCurrentTime()    
{    
   struct timeval tv;    
   gettimeofday(&tv,NULL);    
   return tv.tv_sec * 1000 + tv.tv_usec / 1000;    
} 

int main()
{
	int array[MAX];
	int num = 0;
	while(fin >> array[num])
		++num;

	long start = getCurrentTime();
	std::cout << "before sort(ms): " << start << std::endl;
	chooseSort(array, num);
	long end = getCurrentTime();
	std::cout << "after sort(ms): " << end << std::endl << "cost time(ms): " << (end-start) << std::endl;

	fin.close();
	for(int j=0; j<num; ++j)
	{
		//std::cout << array[j] << ", ";
		fout << array[j] << ", ";
	}
	std::cout << std::endl << "total num = " << num << std::endl;
	return 0;
}


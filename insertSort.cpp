// 插入排序:固定元素找位置
// 插入排序在元素基本有序的情况下（接近最好情况），有很高的效率
#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <unistd.h> // sleep(3);

std::ifstream fin("data.in");
std::ofstream fout("data.out");

#define MAX 1024*1024
// 升序,稳定,时间复杂度O(n^2)
void insertSort(int array[], int num)
{
	for(int i=1; i<num; ++i)
	{
		int j;
		int value = array[i];
		for(j=i-1; j>=0; --j)
		{
			if(value < array[j])
			{
				array[j+1] = array[j]; // 元素后移
			}
			else
				break;
		}
		array[j+1] = value;
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
	insertSort(array, num);
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


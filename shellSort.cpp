// 希尔排序
// 思想:将数据按某个"增量"划分为若干个子序列,分别执行插入排序,最后再对整体执行插入排序
// 插入排序在元素基本有序的情况下具有很高的效率
#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <unistd.h> // sleep(3);

std::ifstream fin("data.in");
std::ofstream fout("data.out");

#define MAX 1024*1024
// 升序,不稳定,时间复杂度O(nlgn)
void shellSort(int array[], int num)
{
	int i, j, gap;
	for(gap = num/2; gap > 0; gap /= 2) // 步长(不断缩短步长)
	{
		for(i=0; i<gap; ++i) // 步数(组数)
		{
			// 对组内的数据,进行插入排序
			for(j=i+gap; j<num; j += gap)
			{
				if(array[j] < array[j-gap])
				{
					int temp = array[j];
					int k = j - gap;
					while(k>0 && array[k] > temp)
					{
						array[k+gap] = array[k];
						k -= gap;
					}
					array[k+gap] = temp;
				}
			}
		}
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
	shellSort(array, num);
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


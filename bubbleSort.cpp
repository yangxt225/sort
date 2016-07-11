// 冒泡排序
#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <unistd.h> // sleep(3);

std::ifstream fin("data.in");
std::ofstream fout("data.out");

#define MAX 1024*1024
// 升序,稳定,时间复杂度O(n^2)
void bubbleSort(int array[], int num)
{
	for(int i=0; i<num; ++i)// 比较趟数
	{
		bool flag = false;
		for(int j=0; j<num-i-1; ++j)
		{
			if(array[j] > array[j+1])
			{
				int tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
				flag = true;
			}
		}
		// 优化效率
		if(!flag)
			break;
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
	bubbleSort(array, num);
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


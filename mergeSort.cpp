// 合并排序
#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <unistd.h> // sleep(3);

std::ifstream fin("data.in");
std::ofstream fout("data.out");

#define MAX 1024*1024
int array[MAX], aux[MAX];

// 合并两个有序序列
void merge(int array[], int low, int mid, int high)
{
	int i = low, j = mid+1;
	for(int k=low; k<=high; ++k)
	{
		// 辅助数组
		aux[k] = array[k];
	}
	
	for(int k=low; k<=high; ++k)
	{
		if(i > mid)// 左边元素没了
		{
			array[k] = aux[j++];
		}
		else if(j > high)// 右边元素没了
		{
			array[k] = aux[i++];
		}
		else if(aux[i] <= aux[j])// 升序排序
		{
			array[k] = aux[i++];
		}
		else
		{
			array[k] = aux[j++];
		}
	}
}

// 升序,稳定,时间复杂度O(nlgn):分治思想
void mergeSort(int array[], int low, int high)
{
	if(low >= high) return;
	int mid = low + (high-low)/2;
	mergeSort(array, low, mid);
	mergeSort(array, mid+1, high);
	merge(array, low, mid, high);
}

long getCurrentTime()    
{    
   struct timeval tv;    
   gettimeofday(&tv,NULL);    
   return tv.tv_sec * 1000 + tv.tv_usec / 1000;    
} 

int main()
{
	//int array[MAX], aux[MAX];
	int num = 0;
	while(fin >> array[num])
		++num;
	
	long start = getCurrentTime();
	std::cout << "before sort(ms): " << start << std::endl;
	mergeSort(array, 0, num-1);
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


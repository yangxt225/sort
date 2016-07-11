// 基数排序
// 0~9作为10个桶,首先对个位进行排序,在对十位,百位...依此
#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <unistd.h> // sleep(3);

std::ifstream fin("data.in");
std::ofstream fout("data.out");

#define MAX 1024*1024
// 升序,稳定,时间复杂度
// r为基数，d为位数。则基数排序的时间复杂度为O(d(n+r))

int base[] = {1, 1, 10, 100, 1000, 10000};
int radix = 10; // 基数
int digit = 5;
int count[10];
int bucket[MAX];

int getDigit(int value, int d)
{
	return (value / base[d]) % 10;
}

void radixSort(int array[], int num)
{
	for(int d=1; d<=digit; ++d)
	{
		// 置空各个桶的统计数据
		for(int i=0; i<radix; ++i)
			count[i] = 0;

		// 统计各个桶将要装入的数据个数
		for(int i=0; i<num; ++i)
		{
			int idx = getDigit(array[i], d);
			count[idx]++;
		}

		// count[i]表示第i个桶数据的右边界索引
		for(int i=1; i<radix; ++i)
			count[i] = count[i] + count[i-1];

		// 将数据装入桶中
		for(int i=num-1; i>=0; --i)
		{
			int idx = getDigit(array[i], d);
			bucket[count[idx]-1] = array[i];
			--count[idx];
		}

		// 将分配到桶里的数据 "倒出来"
		for(int i=0; i<num; ++i)
			array[i] = bucket[i];
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
	radixSort(array, num);
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


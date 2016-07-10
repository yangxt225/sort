// 选择排序:固定位置找元素
#include <iostream>
#include <fstream>

std::ifstream fin("data.in");
std::ofstream fout("data.out");

#define MAX 1024
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

int main()
{
	int array[MAX];
	int num = 0;
	while(fin >> array[num])
		++num;

	chooseSort(array, num);

	fin.close();
	for(int j=0; j<num; ++j)
	{
		std::cout << array[j] << ", ";
		fout << array[j] << ", ";
	}
	std::cout << std::endl << "total num = " << num << std::endl;
	return 0;
}


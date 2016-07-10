// 插入排序:固定元素找位置
#include <iostream>
#include <fstream>

std::ifstream fin("data.in");
std::ofstream fout("data.out");

#define MAX 1024
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

int main()
{
	int array[MAX];
	int num = 0;
	while(fin >> array[num])
		++num;

	insertSort(array, num);

	fin.close();
	for(int j=0; j<num; ++j)
	{
		std::cout << array[j] << ", ";
		fout << array[j] << ", ";
	}
	std::cout << std::endl << "total num = " << num << std::endl;
	return 0;
}


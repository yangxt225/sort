// 堆排序:O(n*lgn)
#include <iostream>
#include <fstream>
#include <vector>
#include <sys/time.h>
#include <unistd.h> // sleep(3);

std::ifstream fin("data.in");
std::ofstream fout("data.out");

// 构建大根堆
void makeHeap(std::vector<int> & vec, int value)
{
	vec.push_back(value);	
	int currIdx = vec.size();
	int parentIdx = currIdx / 2;
	while(parentIdx>0 && vec[parentIdx-1])
	{
		if(vec[currIdx-1] > vec[parentIdx-1])
		{
			vec[currIdx-1] = vec[parentIdx-1];
			vec[parentIdx-1] = value;
			currIdx = parentIdx;
			parentIdx = currIdx / 2;
		}
		else
			break;
	}
}

void popHeap(std::vector<int>& vec, int size)
{
	int value = vec[size-1];
	vec[size-1] = vec[0];
	vec[0] = value;
	for(int j=0; j<size;)
	{
		int leftChildIdx = 2*(j+1);
		int rightChildIdx = 2*(j+1)+1;
		int tmp = -1, currIdx = -1;
		if(leftChildIdx < size)
		{
			tmp = vec[leftChildIdx-1];
			currIdx = leftChildIdx;
		}

		if(rightChildIdx < size && tmp < vec[rightChildIdx-1])
		{
			tmp = vec[rightChildIdx-1];
			currIdx = rightChildIdx;
		}
		if(vec[j] < tmp)
		{
			vec[currIdx-1] = vec[j];
			vec[j] = tmp;
			j = currIdx-1;
		}
		else
			break;
	}
}

// 升序,时间复杂度O(nlgn)
void sortHeap(std::vector<int>& vec)
{
	for(int i=0; i<vec.size(); ++i)
		popHeap(vec, vec.size()-i);
	std::cout << std::endl;
}

long getCurrentTime()    
{    
   struct timeval tv;    
   gettimeofday(&tv,NULL);    
   return tv.tv_sec * 1000 + tv.tv_usec / 1000;    
} 

int main()
{	
	std::vector<int> m_vec;
	int value = 0;
	while(fin >> value)
		makeHeap(m_vec, value);
	std::cout << "Make Heap: \n";	
	for(std::vector<int>::iterator it=m_vec.begin(); it!=m_vec.end(); ++it)
	{
		//std::cout << *it << ", ";
	}

	long start = getCurrentTime();
	std::cout << "before sort(ms): " << start << std::endl;
	sortHeap(m_vec);
	long end = getCurrentTime();
	std::cout << "after sort(ms): " << end << std::endl << "cost time(ms): " << (end-start) << std::endl;

	fin.close();
	std::cout << "Sort Heap: \n";
	for(std::vector<int>::iterator it=m_vec.begin(); it!=m_vec.end(); ++it)
	{
		//std::cout << *it << ", ";
		fout << *it << ", ";
	}
	
	std::cout << std::endl << "m_vec size = " << m_vec.size() << std::endl;
	return 0;
}


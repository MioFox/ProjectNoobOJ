#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long pickGifts(vector<int> gifts, int k)
{
	make_heap(gifts.begin(), gifts.end());      //heap函数，make_heap()用于把一个可迭代容器变成一个堆，第三个参数为less<>()或greater<>(),默认为less<>()大顶堆
	while (k--)
	{
		//pop_heap()用于将堆的第零个元素与最后一个元素交换位置，然后针对前n - 1个元素调用make_heap()函数
		pop_heap(gifts.begin(), gifts.end());   

		gifts.back() = sqrt(gifts.back());        //对最后一个元素（数量最多的堆）开根号
		   
		//push_heap的功能是往堆中插入一个数据。但是，它的默认前提是区间[first, last - 1)已经满足堆结构，并且要插入的数据已经插入到区间的最后一个位置
		push_heap(gifts.begin(), gifts.end());
	}

	long long res=0; 
	for (int x : gifts) 
	{
		res += x;
	} 
	return (long long)res;


}

int main()
{
	vector<int> gifts;
	int k,i;
	cout << "Enter the gifts:";
	while (cin >> i)        //vector不定长数组输入
	{
		gifts.push_back(i);
		if (cin.get() == '\n') break;
	}
	cout << "Enter the seconds number:";
	cin >> k;
	cout << "The number of the rest gifts is :" << pickGifts(gifts, k);
	return 0;
}

#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long pickGifts(vector<int> gifts, int k)
{
	make_heap(gifts.begin(), gifts.end());      //heap������make_heap()���ڰ�һ���ɵ����������һ���ѣ�����������Ϊless<>()��greater<>(),Ĭ��Ϊless<>()�󶥶�
	while (k--)
	{
		//pop_heap()���ڽ��ѵĵ����Ԫ�������һ��Ԫ�ؽ���λ�ã�Ȼ�����ǰn - 1��Ԫ�ص���make_heap()����
		pop_heap(gifts.begin(), gifts.end());   

		gifts.back() = sqrt(gifts.back());        //�����һ��Ԫ�أ��������Ķѣ�������
		   
		//push_heap�Ĺ����������в���һ�����ݡ����ǣ�����Ĭ��ǰ��������[first, last - 1)�Ѿ�����ѽṹ������Ҫ����������Ѿ����뵽��������һ��λ��
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
	while (cin >> i)        //vector��������������
	{
		gifts.push_back(i);
		if (cin.get() == '\n') break;
	}
	cout << "Enter the seconds number:";
	cin >> k;
	cout << "The number of the rest gifts is :" << pickGifts(gifts, k);
	return 0;
}

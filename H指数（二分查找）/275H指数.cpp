#include<iostream>
#include<vector>

using namespace std;

int hIndex(vector<int>& nums);       //二分查找（答案）
bool check(vector<int>& nums, int x);   //线性check


int main()
{
	vector<int> nums;
	int i;
	cout << "Enter the nums:";
	while (cin >> i)
	{
		nums.push_back(i);
		if (cin.get() == '\n') break;
	}
	cout << "The HIndex is :" << hIndex(nums);

	return 0;
}


int hIndex(vector<int>& nums)
{
	int n = nums.size();
	int l = 0, r = n;    //论文数量n，最大的h指数只能为n本身，在[0,n]范围二分	
	while (l < r)
	{
		int mid = l+(r-l)/2;
		//对于二分值mid线性扫描是否合法
		if (check(nums, mid)) l = mid;    //mid成立，则继续寻找最大成立的h
		else r = mid-1;                   //mid不成立，则寻找成立的h
	}
	return r;
}

bool check(vector<int>& nums, int x)
{
	int cnt = 0;
	for (int i : nums)
	{
		if (i >= x) cnt++;  //计算大于h的论文数量
	}
	return cnt >= x;     //返回大于h的论文数量是否>=hIndex
}


#include<iostream>
#include<vector>

using namespace std;

int hIndex(vector<int>& nums);       //���ֲ��ң��𰸣�
bool check(vector<int>& nums, int x);   //����check


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
	int l = 0, r = n;    //��������n������hָ��ֻ��Ϊn������[0,n]��Χ����	
	while (l < r)
	{
		int mid = l+(r-l)/2;
		//���ڶ���ֵmid����ɨ���Ƿ�Ϸ�
		if (check(nums, mid)) l = mid;    //mid�����������Ѱ����������h
		else r = mid-1;                   //mid����������Ѱ�ҳ�����h
	}
	return r;
}

bool check(vector<int>& nums, int x)
{
	int cnt = 0;
	for (int i : nums)
	{
		if (i >= x) cnt++;  //�������h����������
	}
	return cnt >= x;     //���ش���h�����������Ƿ�>=hIndex
}


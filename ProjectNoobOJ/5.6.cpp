#include<iostream>
using namespace std;

int main()
{
	int n,i,j,k;
	cout << "enter the number of num";
	cin >> n;
	int* num = new int[n];
	int* cnt = new int[n];
	int* count = new int[n];
	for (i = 0; i < n; i++)
	{
		count[i] = 1;
		cnt[i] = 0;
	}
	cout << "enter the num";
	for (i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (num[i] == num[j]&&i!=j)
			{
				cnt[i] = num[i];
				count[i]++;
			}
			else
			{
				for (k = 0; k < i; k++)
				{
					if (num[i] == cnt[k])
						break;
					if (k = i - 1)
					{
						cnt[i] = num[i];
					}
				}
			}
		}
	}
	i = 0;
	while (cnt[i]!=0)
	{
		cout << cnt[i] << " " << count[i] << endl;
		i++;
	}
	return 0;
}
#include<iostream>

using namespace std;

void found(int* a,int* max,int* cmax, int left, int right)
{
	//当数组中只有一个元素时，最大值和次大值都是该元素
	if (left == right)
	{
		*max = left;
		*cmax = left;
	}
	//当数组中只有两个元素时，比较该两个元素即可得出最大值和次大值
	else if (left == right - 1)
	{
		if (a[left] > a[right])
		{
			*max = left;
			*cmax = right;
		}
		else
		{
			*max = right;
			*cmax = left;
		}
	}
	//当数组大于两个元素时
	else
	{
		int m = (right + 1 - left) / 2; //要比较元素之间索引值的距离
		for (int i = left; i < left + m; i++)
		{
			if (a[i] > a[i + m]) //分组进行两两比较，最大的值放在右边
			{
				int temp = a[i];
				a[i] = a[i + m];
				a[i + m] = temp;
			}
			found(a, max, cmax, left + m, right); //对右边的值再次进行两两比较
			if (a[*max - m] > a[*cmax]) //从与最大值比较过的元素中找到次大值，否则不可能为次大值
			{
				*cmax = *max - m;
			}
		}
	}
}

int main()
{
	int n;
	cout << "Please input the numbers of the array:" << endl;
	cin >> n;
	int* a = new int[n];
	cout << "input the keys of the array:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int* max = new int;
	int* cmax = new int;
	found(a, max, cmax, 0, n-1);
	cout << "max:" << a[*max] << "  cmax:" << a[*cmax] << endl;
}

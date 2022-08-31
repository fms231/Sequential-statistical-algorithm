#include<iostream>

using namespace std;

void found(int* a,int* max,int* cmax, int left, int right)
{
	//��������ֻ��һ��Ԫ��ʱ�����ֵ�ʹδ�ֵ���Ǹ�Ԫ��
	if (left == right)
	{
		*max = left;
		*cmax = left;
	}
	//��������ֻ������Ԫ��ʱ���Ƚϸ�����Ԫ�ؼ��ɵó����ֵ�ʹδ�ֵ
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
	//�������������Ԫ��ʱ
	else
	{
		int m = (right + 1 - left) / 2; //Ҫ�Ƚ�Ԫ��֮������ֵ�ľ���
		for (int i = left; i < left + m; i++)
		{
			if (a[i] > a[i + m]) //������������Ƚϣ�����ֵ�����ұ�
			{
				int temp = a[i];
				a[i] = a[i + m];
				a[i + m] = temp;
			}
			found(a, max, cmax, left + m, right); //���ұߵ�ֵ�ٴν��������Ƚ�
			if (a[*max - m] > a[*cmax]) //�������ֵ�ȽϹ���Ԫ�����ҵ��δ�ֵ�����򲻿���Ϊ�δ�ֵ
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

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void numberAdd(string& s1, string& s2, string& res)
{
	int len1 = s1.size();
	int len2 = s2.size();
	int len3 = max(len1, len2) + 1;
	string temp(len3, '0');

	int index1 = len1 - 1, index2 = len2 - 1, index3 = len3 - 1;
	int carry = 0;
	while (index1 >= 0 && index2 >= 0)
	{
		int num = (s1[index1--] - '0') + (s2[index2--] - '0') + carry;
		if (num >= 10)
		{
			carry = 1;
			num -= 10;
		}
		else
			carry = 0;

		temp[index3--] = num + '0';
	}
	while (index1 >= 0)
	{
		int num = s1[index1--] - '0' + carry;
		if (num >= 10)
		{
			carry = 1;
			num -= 10;
		}
		else
			carry = 0;

		temp[index3--] = num + '0';
	}

	while (index2 >= 0)
	{
		int num = s2[index2--] - '0' + carry;
		if (num >= 10)
		{
			carry = 1;
			num -= 10;
		}
		else
			carry = 0;

		temp[index3--] = num + '0';
	}
	temp[index3] = carry ? '1' : '0';
	res = temp;
	if (res[0] == '0')
	{
		copy(res.begin() + 1, res.end(), res.begin());
		res.resize(res.size() - 1);
	}
}

int main(void)
{
	string s1, s2;
	cin >> s1 >> s2;
	string res;
	numberAdd(s1, s2, res);
	cout << res << endl;
}

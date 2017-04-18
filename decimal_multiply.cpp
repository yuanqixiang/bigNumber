#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string decimal_multiply(string s1, string s2)
{
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	int len1 = s1.length(), len2 = s2.length();
	string result(len1 + len2 + 2, '0');

	int pos = 0;
	string str1(len1 - 1, '0');
	string str2(len2 - 1, '0');
	unsigned int pos1 = s1.find('.');
	copy(s1.begin(), s1.begin() + pos1, str1.begin());
	copy(s1.begin() + pos1 + 1, s1.end(), str1.begin() + pos1);

	unsigned int pos2 = s2.find('.');
	copy(s2.begin(), s2.begin() + pos2, str2.begin());
	copy(s2.begin() + pos2 + 1, s2.end(), str2.begin() + pos2);
	pos = pos1 + pos2;

	int carry = 0;
	for (size_t i = 0; i < str1.length(); ++i)
	{
		size_t j = 0;
		for (; j < str2.length(); ++j)
		{
			carry += (result[i + j] - '0') + (str1[i] - '0') * (str2[j] - '0');
			result[i + j] = carry % 10 + '0';
			carry /= 10;
		}
		while (carry)
		{
			result[i + j++] += carry % 10;
			carry = carry / 10;
		}
	}
	result.insert(result.begin() + pos, '.');

	pos1 = result.find_first_not_of('0');
	result.erase(0, pos1);

	reverse(result.begin(), result.end());
	pos1 = result.find_first_not_of('0');
	result.erase(0, pos1);

	return result;
}

int main(void)
{
	string s1, s2;
	cin >> s1 >> s2;
	cout << decimal_multiply(s1, s2) << endl;
}

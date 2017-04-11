#include <iostream>
#include <vector>
#include <string>

using namespace std;

void multiply2(string& s1, string& s2, string& res)
{
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	string temp(s1.size() + s2.size(), '0');

	int c = 0;
	for (unsigned int i = 0; i < s1.size(); ++i)
	{
		unsigned int j = 0;
		for (; j < s2.size(); ++j)
		{
			c += (temp[i + j] - '0') + (s1[i] - '0') * (s2[j] - '0');
			temp[i + j] = (c % 10) + '0';
			c /= 10;
		}
		while (c)
		{
			temp[i + j++] += c % 10;
			c = c / 10;
		}
	}
	for (int i = temp.size() - 1; i >= 0; i--)
	{
		if (temp[i] != '0')
			break;
		else
			temp.pop_back();
	}
	reverse(temp.begin(), temp.end());
	res = temp;
}

int main(void)
{
	string a, b;
	cin >> a >> b;
	string res;
	multiply2(a, b, res);
	cout << a << " " << b << endl;
	cout << res << endl;
	return 0;
}

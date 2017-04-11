#include <iostream>
#include <vector>
#include <string>

using namespace std;
void str2num_reverse(const string& s1, const string& s2, 
							vector<int>& vec1, vector<int>& vec2)
{
	for (int i = s1.size() - 1; i >= 0; --i)
	{
		vec1.push_back(s1[i] - '0');
	}
	for (int i = s2.size() - 1; i >= 0; --i)
	{
		vec2.push_back(s2[i] - '0');
	}
}
void vec_multiply(const vector<int>& vec1, const vector<int>& vec2,
								vector<int>& result)
{
	for (unsigned int i = 0; i < vec1.size(); ++i)
	{
		for (unsigned int j = 0; j < vec2.size(); ++j)
			result[i + j] += vec1[i] * vec2[j];
	}
	for (int i = result.size() - 1; i >= 0; --i)
	{
		if (result[i] != 0)
			break;
		else
			result.pop_back();
	}

	int carry = 0;
	for (unsigned int i = 0; i < result.size(); ++i)
	{
		result[i] += carry;
		carry = result[i] / 10;
		result[i] = result[i] % 10;
	}
	if (carry != 0)
		result.push_back(carry);
}

void num2char(string & res, vector<int>& result)
{
	int len = result.size();
	for (unsigned int i = 0; i < result.size(); ++i)
	{
		res.push_back(result[len - 1 - i] + '0');
	}
}

int main(void)
{
	string s1, s2;
	cin >> s1;
	cin >> s2;
	vector<int> vec1, vec2;
	str2num_reverse(s1, s2, vec1, vec2);
	vector<int> result_vec(vec1.size() + vec2.size(), 0);
	vec_multiply(vec1, vec2, result_vec);
	string result_str;
	num2char(result_str, result_vec);
	cout << result_str << endl;
	return 0;
}

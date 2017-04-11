#include<iostream>
using namespace std;
void factorial(int value);
void main()
{
	factorial(100);
}
void factorial(int value)
{

	int result[10000] = { 0 };
	int result_size = 1;    //实时更新result的实际位数
	int carryBit = 0;       //进位的值

	result[0] = 1;         //初始结果为1

	for (int out = 2; out <= value; out++) 
	{
		for (int in = 0; in < result_size; in++) 
		{
			int temp = result[in] * out + carryBit;
			result[in] = temp % 10;
			carryBit = temp / 10;
		}
		while (carryBit != 0) 
		{
			result[result_size] = carryBit % 10;
			result_size++;
			carryBit = carryBit / 10;
		}
	}

	cout << value << "! = " << endl;
	for (int i = result_size - 1; i >= 0; --i)
	{
		cout << result[i];
	}

}

#include <iostream>
#include <cmath>

using namespace std;

double pow(double x, int n) {
	double ans = 1;
	int bit = 1;
	int terminate = (int) floor(log2(abs(n)));
	if(!n)
		return 1;
	if(n > 0)
	{
		double temp = x;
		for(int i = 1; i <= terminate + 1; ++i)
		{
			if(n & bit)
			{
				ans = ans * temp;
			}
			temp = temp * temp;
			bit = 2 * bit;
		}
	}
	else
	{
		double temp = 1.0 / x;
		int a = abs(n);
		for(int i = 1; i <= terminate + 1; ++i)
		{
			if(a & bit)
			{
				ans = ans * temp;
			}
			temp = temp * temp;
			bit = 2 * bit;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	double x;
	int n;
	while(true)
	{
		cin >> x;
		cin >> n;
		if(cin.fail())
			break;
		cout << x << " to the power of " << n << ": ";
		cout << pow(x, n) << endl;
	}
	return 0;
}
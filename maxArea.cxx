#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> &height) 
{
	int left = 0;
	int right = height.size() - 1;
	int ret = 0;
	while(left < right)
	{
		if(height[left] < height[right])
		{
			int temp = height[left] * (right - left);
			if(temp > ret)
				ret = temp;
			left++;
		}
		else
		{
			int temp = height[right] * (right - left);
			if(temp > ret)
				ret = temp;
			right--;
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	vector<int> height;
	while(true)
	{
		int a;
		cin >> a;
		if(cin.fail())
			break;
		height.push_back(a);
	}
	cout << maxArea(height) << endl;
	return 0;
}
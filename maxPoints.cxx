#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
// #include <utility>

using namespace std;


struct Point
{
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

int maxPoints(vector<Point> &points)
{
	if(points.empty())
		return 0;
	int result = 1;
	int vectorSize = points.size();
	for(int i = 0; i < vectorSize; ++i)
	{
		unordered_map<double, int> myHashTable;
		int samePointsNum = 1;
		for(int j = i + 1; j < vectorSize; ++j)
		{
			if((points[i].x == points[j].x) && (points[i].y == points[j].y))
				samePointsNum ++;
			else
			{
				double slope;
				if(points[i].x == points[j].x)
					slope = 1.0 / 0.0;
				else
					slope = (points[i].y - points[j].y) / (double)(points[i].x - points[j].x);
				auto it = myHashTable.find(slope);
				if(it == myHashTable.end())
				{
					myHashTable.insert(pair<double, int>(slope, 1));
				}
				else
					it->second ++;
			}
		}
		if(myHashTable.empty())
		{
			if(samePointsNum > result)
				result = samePointsNum;
		}
		else
		{
			for(auto it = myHashTable.begin(); it != myHashTable.end(); ++it)
			{
				if(it->second + samePointsNum > result)
					result = it->second + samePointsNum;
			}
		}
	}
	return result;
}

int main(int argc, char const *argv[])
{
	vector<Point> points;
	while(true)
	{
		int x, y;
		cin >> x;
		cin >> y;
		if(cin.fail())
			break;
		points.push_back(Point(x, y));
	}
	cout << maxPoints(points) << endl;
	return 0;
}
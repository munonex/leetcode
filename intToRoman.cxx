#include <iostream>
#include <string>
using namespace std;

// I used to think ROMAN NUMERIAL is complex which needs recursion...
// string intToRomanHelper(int &remain, int kind)
// {
// 	string ret;
// 	if(kind < 0)
// 	{
// 		return ret;
// 	}
// 	string sym;
// 	int comp;
// 	int low = 0;
// 	switch(kind)
// 	{
// 		case 0:
// 		sym = "I";
// 		comp = 1;
// 		break;
// 		case 1:
// 		sym = "V";
// 		comp = 5;
// 		low = 1;
// 		break;
// 		case 2:
// 		sym = "X";
// 		comp = 10;
// 		low = 5;
// 		break;
// 		case 3:
// 		sym = "L";
// 		comp = 50;
// 		low = 10;
// 		break;
// 		case 4:
// 		sym = "C";
// 		comp = 100;
// 		low = 50;
// 		break;
// 		case 5:
// 		sym = "D";
// 		comp = 500;
// 		low = 100;
// 		break;
// 		case 6:
// 		sym = "M";
// 		comp = 1000;
// 		low = 500;
// 		break;
// 	}
// 	while(remain >= comp)
// 	{
// 		ret += sym;
// 		remain -= comp;
// 	}
// 	if(remain > low)
// 	{
// 		remain = comp - remain;
// 		ret = ret + intToRomanHelper(remain, kind - 1) + sym;
// 	}
// 	else
// 	{
// 		ret = ret + intToRomanHelper(remain, kind - 1);
// 	}
// 	return ret;
// }

string intToRoman(int num) {
	string ret;
	int arr[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
	string sym[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
	for(int i = 12; i >= 0; i--)
	{
		while(num >= arr[i])
		{
			num -= arr[i];
			ret += sym[i];
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	int a;
	while(true)
	{
		cin >> a;
		if(cin.fail())
			break;
		cout << "convert " << a << " to roman is: ";
		cout << intToRoman(a) << endl;
	}
	return 0;
}
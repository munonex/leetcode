#include <iostream>
#include <sstream>
#include <deque>

using namespace std;

void reverseWords(string &s)
{
	stringstream ss(s);
	deque<string> myDeque;
	string temp;

	while(!ss.eof())
	{
		ss >> temp;
		if(ss.fail())
			break;
		myDeque.push_back(temp);
	}

	ostringstream oss;

	while(!myDeque.empty())
	{
		oss << myDeque.back() << " ";
		myDeque.pop_back();
	}
	s.clear();
	s = oss.str();
	if(!s.empty())
		s.pop_back();
}

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	cout << s << endl;
	reverseWords(s);
	cout << s << endl;
	return 0;
}

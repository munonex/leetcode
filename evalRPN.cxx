#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int eval(int &operand1, int &operand2, int &op)
{
	switch(op)
	{
		case 1:
		return operand2 + operand1;
		case 2:
		return operand2 - operand1;
		case 3:
		return operand2 * operand1;
		case 4:
		return operand2 / operand1;
		default:
		cout << "wrong format!" << endl;
		exit(3);
	}
}

int evalRPN(vector<string> &tokens)
{
	if(tokens.empty())
	{
		cout << "wrong format!" << endl;
		exit(1);
	}

	// only number
	int result;
	result = atoi(tokens.back().c_str());
	if((!result && (tokens.back() == "0")) || result)
	{
		tokens.pop_back();
		return result;
	}

	// get operator
	// op takes value
	// 0: unrecognized
	// 1: +
	// 2: -
	// 3: *
	// 4: /
	int operand1, operand2, op;
	if(tokens.back() == "+")
		op = 1;
	else if(tokens.back() == "-")
		op = 2;
	else if(tokens.back() == "*")
		op = 3;
	else if(tokens.back() == "/")
		op = 4;
	else
	{
		cout << "wrong format!" << endl;
		exit(2);
	}
	tokens.pop_back();
	operand1 = evalRPN(tokens);
	operand2 = evalRPN(tokens);
	result = eval(operand1, operand2, op);
	return result;
}

int main(int argc, char const *argv[])
{
	vector<string> tokens;
	string temp;
	while(true)
	{
		cin >> temp;
		if(temp == "Q")
			break;
		tokens.push_back(temp);
	}
	cout << evalRPN(tokens) << endl;
	return 0;
}

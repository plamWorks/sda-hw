#include <cmath>
#include <cstdio>
#include <vector>
#include<stack>
#include<string>
#include <iostream>
#include <algorithm>
using namespace std;

void print(stack<int> s)
{
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
}
void print(stack<char> s)
{
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
}
int main() {
	int n = 0;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		stack<int> operands;
		stack<char> operators;
		string input;
		getline(cin, input);
		for (int i = input.length() - 1; i >= 0; i--)
		{

			if (input[i] != ' ')
			{
				//cout << "TOVA CHETA:" << input[i] << "!!" << endl;
				// operators + - * / x y z
				if (input[i] == '+'
					|| input[i] == '-'
					|| input[i] == '*'
					|| input[i] == '/'
					|| input[i] == 'x'
					|| input[i] == 'y'
					|| input[i] == 'z')
				{
					operators.push(input[i]);
				}
				else
				{
					int j = i;
					string nextNum = "";
					while (j<input.length() && j >= 0 && input[j] != ' ')
					{
						nextNum = input[j] + nextNum;
						j--;
						i--;
					}
				//	cout << "NEXTNUM" << nextNum << endl;
					operands.push(stoi(nextNum));
				}
			}
		}
		bool operandsOk = true;
		while (!operators.empty() && !operands.empty())
		{
			char currOperator = operators.top();
			operators.pop();
			switch (currOperator)
			{
			case '+': {
				int leftOperand = operands.top();
				operands.pop();
				if (!operands.empty())
				{
					int rightOperand = operands.top();
					operands.pop();
					operands.push(leftOperand + rightOperand);
				}
				else
				{
					operandsOk = false;
				}
				break;
			}
			case '-': {
				int leftOperand = operands.top();
				operands.pop();
				if (!operands.empty())
				{
					int rightOperand = operands.top();
					operands.pop();
					operands.push(leftOperand - rightOperand);
				}
				else
				{
					operandsOk = false;
				}
				break; }
			case '*': {
				int leftOperand = operands.top();
				operands.pop();
				if (!operands.empty())
				{
					int rightOperand = operands.top();
					operands.pop();
					operands.push(leftOperand * rightOperand);
				}
				else
				{
					operandsOk = false;
				}
				break; }
			case '/': {
				int leftOperand = operands.top();
				operands.pop();
				if (!operands.empty())
				{
					int rightOperand = operands.top();
					operands.pop();
					operands.push(leftOperand / rightOperand);
				}
				else
				{
					operandsOk = false;
				}
				break; }
			case 'x': {
				int leftOperand = operands.top();
				operands.pop();
				if (!operands.empty())
				{
					int rightOperand = operands.top();
					operands.pop();
					operands.push(leftOperand*leftOperand + rightOperand);
				}
				else
				{
					operandsOk = false;
				}
				break; }
			case 'y': {
				int operand = operands.top();
				operands.pop();
				operands.push(2 * operand + 1);
				break; }
			case 'z': {
				int firstOperand = operands.top();
				operands.pop();
				if (!operands.empty())
				{
					int secondOperand = operands.top();
					operands.pop();
					if (!operands.empty())
					{
						int thirdOperand = operands.top();
						operands.pop();
						operands.push(firstOperand + 2 * secondOperand + 3 * thirdOperand);
					}
					else
					{
						operandsOk = false;
					}
				}
				else
				{
					operandsOk = false;
				}			
				break; }
			}
		}
		if (!operands.empty() && operandsOk)
		{
			int result = operands.top();
			operands.pop();
			if ( operands.empty())
			{
				cout <<"CHETI "<< result << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
		else
		{
			cout << "NO" << endl;
		}
		
	}
	system("pause");
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}

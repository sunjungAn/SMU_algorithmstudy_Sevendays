#include<iostream>
#include<string>
#include<cstdio>
#include<stack>
#include<cstdlib>
using namespace std;
stack <int> v;
string str;

int main(void)
{
	string s;
	cin >> str;
	int i = 0;
	int op = 0;
	while (i < str.size())
	{
		char c = str[i];
		if (c == '-') //빼기면
		{
			if (op != 0) {
				v.push(op+atoi(s.c_str()));
				op = 0;
				s = "";
			}
			else {
				v.push(atoi(s.c_str()));
				s = "";
			}
		}
		else if (c == '+') //더하기면
		{
			op += atoi(s.c_str());
			s = "";
		}
		else { 
			s += c;
		}
		i++;
	}
	if (op != 0) {
		v.push(op+atoi(s.c_str()));
	}
	else {
		v.push(atoi(s.c_str()));
	}
	int ans = 0;
	while (v.size()!=1)
	{
		ans += v.top();
		v.pop();
	}

	cout << v.top() - ans;

}

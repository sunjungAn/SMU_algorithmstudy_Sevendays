#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector <string> v;
//string s1 = "";
//string s2 = "";
void input(void)
{
	int c;
	cin >> c;
	string str;
	for (int i = 0; i < c; i++)
	{
		cin >> str;
		v.push_back(str);
	}
}
bool compare(string v1, string v2)
{
	if (v1 == v2)
		return false;
	if (v1[0] - '0' < v2[0] - '0')
		return false;
	else if (v1[0] == v2[0])
	{
			v1 += v1[0];
			v2 += v2[0];
		return compare(v1.substr(1), v2.substr(1));

	}
	else return true;
}
void print(void)
{
	string s = "";
	int count = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == "0")
			count++;
		s += v[i];
	}
	if (count == v.size()) cout << "0\n";
	else cout << s << '\n';

}
int main(void)
{
	input();
	sort(v.begin(), v.end(), compare);
	print();
}
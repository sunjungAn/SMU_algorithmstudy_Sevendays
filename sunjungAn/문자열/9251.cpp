#include<iostream>
#include<string>
using namespace std;
short map[10001][10001];

int main(void)
{
	string s1, s2;
	cin >> s1 >> s2;
	int i, j;
	for (i = 1; i <= s2.size(); i++)
	{
		for (j = 1; j <= s1.size(); j++)
		{
			if (s2[i - 1] != s1[j - 1])
				(map[i - 1][j] > map[i][j - 1]) ? map[i][j] = map[i - 1][j] : map[i][j] = map[i][j - 1];
			else map[i][j] = map[i - 1][j - 1] + 1;
		}
	}
	cout << map[s2.size()][s1.size() ];


}

/*for (int i = 1; i <= s1.size(); i++)
{
	for (int j = 1; j <= s2.size(); j++)
	{
		cout << map[i][j] << " ";
	}
	cout << "\n";
}*/

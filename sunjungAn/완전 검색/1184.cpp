#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
//vector<int> c;
int c;
vector <int> sub;
int n, s;

void put(int k)
{
	//static int count = 0;
	int sum = 0;

	if (sub.size() < 0 || k == v.size()) //탈출 
		return;
	sub.push_back(v[k]);
	put(k+1); //1, 12 123, 1234
	for (int i = 0; i < sub.size(); i++) {
		sum += sub[i];
	}
	if (sum == s && sub.size() != 0) {
		c += 1;
		sum = 0;
	}
	sub.pop_back();
	put(k+1);

}
int main(void)
{
	int num;
	cin >> n >> s;
	for (int i = 0; i < n; i++) { //input
		cin >> num;
		v.push_back(num);
	}
	put(0); //첫번째 원소를 넣었음
	cout << c << '\n';

}

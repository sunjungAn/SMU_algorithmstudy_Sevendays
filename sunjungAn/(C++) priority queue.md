#include <queue>

std::priority_queue<int> q;//1
std::priority_queue<int,std::vector<int>,std::less<int> >q;//2
std::priority_queue<int,std::vector<int>, greater<int> >q;//3

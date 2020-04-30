#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> x{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//int x[10]{1,2,3,4,5,6,7,8,9,10};
	int y[10];
	int v1 = 10;

	transform(begin(x), end(x), begin(y), [&](int ele) { return v1 + ele; });

	for (auto n : y)
		cout << n << endl;
}

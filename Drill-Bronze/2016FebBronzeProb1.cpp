/*
ID: eric.ch2
PROG: PROGRAM_NAME
LANG: C++11
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
#include <algorithm>
using namespace std;

class Solution
{
private:
	int x, y, m;
public:
	Solution()
	{
		ifstream fin("pails.in");
		fin >> x;
		fin >> y;
		fin >> m;
	}

	void outputClosest()
	{
		int closest = 0;
		for (int i = 0; i * y <= m; i++)
		{
			int yProduct = i*y;
			int leftover = m - yProduct;
			int xs = leftover / x;
			int xProduct = x*xs;
			int sum = yProduct + xProduct;
			if (m - sum < m - closest)
			{
				closest = sum;
			}
		}
		ofstream fout("pails.out");
		fout << closest << endl;
	}
};

int main()
{
	Solution solution;
	solution.outputClosest();
	return 0;
}
/*
ID: echen
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
	int a, b, c, d;
public:
	Solution()
	{
		ifstream fin("paint.in");
		fin >> a;
		fin >> b;
		fin >> c;
		fin >> d;

	}

	void outputTotal()
	{
		int total;
		if ((a <= c) && (b >= d))
		{
			total = b - a;
		}
		else if ((c <= a) && (d >= b))
		{
			total = d - c;
		}
		else if ((c >= a) && (c <= b))
		{
			total = d - a;
		}
		else if ((d >= a) && (d <= b))
		{
			total = b - c;
		}
		else if ((a >= c) && (a <= d))
		{
			total = b - c;
		}
		else if ((b >= c) && (b <= d))
		{
			total = d - a;
		}
		else
		{
			total = (b - a) + (d - c);
		}
		ofstream fout("paint.out");
		fout << total << endl;
	}
};

int main()
{
	Solution solution;
	solution.outputTotal();
	return 0;
}
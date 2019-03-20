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
	int N;
	vector<int> A;
public:
	Solution()
	{
		ifstream fin;
		fin.open("lemonade.in");

		fin >> N;
		for (int i = 0; i < N; i++)
		{
			int tempA;
			fin >> tempA;
			A.push_back(tempA);
		}

		sort(A.rbegin(), A.rend());
	}

	void print()
	{
		ofstream fout;
		fout.open("lemonade.out");

		int number = 0;
		
		for (int i = 0; i < N; i++)
		{
			if (A[i] >= number) number++;
		}

		fout << number;
	}
};

int main()
{
	Solution solution;
	solution.print();
	return 0;
}
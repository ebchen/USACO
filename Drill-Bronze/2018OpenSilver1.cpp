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
		fin.open("sort.in");
		fin >> N;
		for (int i = 0; i < N; i++)
		{
			int tempA;
			fin >> tempA;
			A.push_back(tempA);
		}
		fin.close();
	}
	
	void count()
	{
		int maxAway = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = i + maxAway; j < N; j++)
			{
				if (A[j] < A[i])
				{
					int distance = j - i;
					if (distance > maxAway)
					{
						maxAway = distance;
					}
				}
			}
		}

		ofstream fout;
		fout.open("sort.out");
		fout << maxAway + 1 << endl;
	}
	void sortAndCount()
	{
		int mooCount = 0;
		bool sorted = false;
		
		
		for (int i = 0; i < N - 1; i++)
		{
			if (sorted) break;
			sorted = true;
			mooCount++;
			for (int j = 0; j < N - i - 1; j++)
				if (A[j] > A[j + 1])
				{
					swap(A[j], A[j + 1]);
					sorted = false;
				}
		}

		ofstream fout;
		fout.open("sort.out");
		fout << mooCount << endl;
		
	}

};

int main()
{
	Solution solution;
	solution.sortAndCount();
	return 0;
}
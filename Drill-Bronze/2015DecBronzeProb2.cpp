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
	int limits[100];
	int speeds[100];
public:
	Solution()
	{
		ifstream fin("speeding.in");
		int n; 
		int m;
		fin >> n;
		fin >> m;
		int currentL = 0;
		for (int i = 0; i < n; i++)
		{
			int range;
			int limit;
			fin >> range;
			fin >> limit;
			for (int j = currentL; j < currentL + range; j++)
			{
				limits[j] = limit;
				
			}
			currentL = currentL + range;
		}

		
		int currentS = 0;
		for (int i = 0; i < m; i++)
		{
			int range;
			int speed;
			fin >> range;
			fin >> speed;
			for (int j = currentS; j < currentS + range; j++)
			{
				speeds[j] = speed;

			}
			currentS = currentS + range;
		}

		
	}

	
	void outputWorst()
	{
		int max = 0;
		for (int i = 0; i < 100; i++)
		{
			if (speeds[i] > limits[i])
			{
				int diff = speeds[i] - limits[i];
				if (diff > max) max = diff;
			}
		}

		ofstream fout("speeding.out");
		fout << max << endl;
	}
};

int main()
{
	Solution solution;
	solution.outputWorst();
	return 0;
}
/*
ID: echen
PROG: 
LANG: C++11
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
private:
	int numberOfProblems;
	vector<int> scores;

public:
	Solution()
	{
		ifstream fin("homework.in");
		fin >> numberOfProblems;
		for (int i = 0; i < numberOfProblems; i++)
		{
			int n;
			fin >> n;
			scores.push_back(n);
		}
	}

	void outputK()
	{
		
		double bestAverage = -1000000;
		
		vector <int> kValues;
		for (int k = 1; k <= numberOfProblems - 2; k++)
		{
			
			int min = *min_element(scores.begin()+k, scores.end());
			
			int sum = accumulate(scores.begin() + k, scores.end(), 0) - min;
			

			double average = sum / (double)(numberOfProblems - k - 1);
			if (average > bestAverage)
			{
				bestAverage = average;
				
				kValues.clear();
				kValues.push_back(k);
			}
			else if (average == bestAverage)
			{
				kValues.push_back(k);
			}
		}

		ofstream fout("homework.out");
		for (int m = 0; m < kValues.size(); m++)
		{
			fout << kValues[m] << endl;
		}
	}
};

int main()
{
	Solution solution;
	solution.outputK();
	return 0;
}
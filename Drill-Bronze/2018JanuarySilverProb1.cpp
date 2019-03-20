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
	long long numberOfGuards;
	vector <pair<long long, long long>> schedule;

public:
	Solution()
	{
		ifstream fin("lifeguards.in");
		fin >> numberOfGuards;
		long long start;
		long long stop;
		for (long long i = 0; i < numberOfGuards; i++)
		{
			fin >> start;
			fin >> stop;
			pair<long long, long long> cow(start, stop);
			schedule.push_back(cow);
		}
		sort(schedule.begin(), schedule.end());
	}
		
	long long timeCovered(vector<pair<long long, long long>> s)
	{
		long long total = 0;
		vector <pair <long long, bool> > limits;
		for (long long i = 0; i < s.size(); i++)
		{
			pair <long long, bool> start(s[i].first, false);
			pair <long long, bool> end(s[i].second, true);
			limits.push_back(start);
			limits.push_back(end);
		}
		sort(limits.begin(), limits.end());
		long long n = 0;
		for (long long i = 0; i < limits.size(); i++)
		{
			if (n != 0)
			{
				total += (limits[i].first - limits[i - 1].first);
			}

			if (limits[i].second)
			{
				n--;
			}
			else
				n++;
			
		}
		return total;
	}

	void output()
	{
		long long maxTime = 0;
		for (long long i = 0; i < numberOfGuards; i++)
		{
			vector<pair<long long, long long>> test = schedule;
			test.erase(test.begin() + i);
			long long time = timeCovered(test);
			if (time > maxTime)
				maxTime = time;
		}

		ofstream fout("lifeguards.out");
		fout << maxTime;
	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}
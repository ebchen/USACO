
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
	long long numberOfPiles;
	vector < pair <double, double>> locations;
	double minimum = 0;
	long long counter = 0;
	double average;

public:
	Solution()
	{
		ifstream fin("teleport.in");
		fin >> numberOfPiles;
		double sum = 0;
		double minimum = INT_MAX;
		double maximum = INT_MIN;
		for (int i = 0; i < numberOfPiles; i++)
		{
			double x;
			double y;
			fin >> x;
			fin >> y;
			sum += y;
			counter++;

			pair <double, double> ends = { x,y };
			locations.push_back(ends;)
		}

		average = sum / counter;
	}

	void output()
	{
		for (int i = 0; i < numberOfPiles; i++)
		{
			double physicalDiff = abs(locations[i].first - locations[i].second);
			double teleportDiff = abs(locations[i].first) + abs(average - locations[i].second);
			if (physicalDiff <= teleportDiff)
			{
				minimum += physicalDiff;
				average = ((average * counter) - locations[0].second) / (counter - 1);
				counter--;
			}
			else
			{
				minimum += teleportDiff;
			}
		}

		ofstream fout("teleport.out");
		fout << minimum;
	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}
	
/*

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
long long numberOfPiles;
vector < pair <double, double>> locations;
double minimumD;
double min = 10000000000;
double max = -10000000000;
long long counter = 0;

public:
Solution()
{
	ifstream fin("teleport.in");
	fin >> numberOfPiles;
	for (int i = 0; i < numberOfPiles; i++)
	{
		double x;
		double y;
		fin >> x;
		fin >> y;
		if (x < min) min = x;
		if (x > max) max = x;
		if (y < min) min = y;
		if (y > max) max = y;

		pair <double, double> ends = { x,y };
		locations.push_back(ends);
	}

}

void output()
{
	for (int i = (int)min; i <= (int)max; i++)
	{
		double currDistance = 0;
		for (int j = 0; j < numberOfPiles; j++)
		{
			double x = locations[j].first;
			double y = locations[j].second;
			double physicalDiff = abs(x-y);
			double teleportDiff1 = abs(x) + abs(i-y);
			double teleportDiff2 = abs(y) + abs(i-x);
			double teleportDiff;

			if (teleportDiff1 < teleportDiff2) teleportDiff = teleportDiff1;
			else teleportDiff = teleportDiff2;

			if (teleportDiff < physicalDiff) currDistance += teleportDiff;
			else currDistance += physicalDiff;
		}
		if (i == min) minimumD = currDistance;
		else if (currDistance < minimumD) minimumD = currDistance;	
	}
	ofstream fout("teleport.out");
	fout << minimumD;
}
};

int main()
{
Solution solution;
solution.output();
return 0;
}

*/


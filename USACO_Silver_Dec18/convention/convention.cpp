#include <vector>
#include <fstream>
#include <math.h>
#include <climits>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <deque>
#include <string>
#include <cmath>
#include <map>
#include <unordered_map>
#include <utility>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <stack>
#include <bitset>
#include <random>
#include <cstring>
#include <complex>
#include <cassert>

using namespace std;

// finds the index of max difference
int findMax(int start, int end, vector<int> differences, int exclude)
{
	int maxDiff = 0;
	int maxDiffInd = start;
	for (int i = start; i < end; i++)
	{
		if (differences[i] > maxDiff && i != exclude)
		{
			maxDiff = differences[i];
			maxDiffInd = i;
		}
	}
	return maxDiffInd;
}
// if there are n buses, I need to make n-1 divisions
// overall strategy is to find all the differences between arrival times. Then take the n-1 highest differences make the divisions there.
int main()
{
	//reads in data
	ifstream fin("convention.in");
	ofstream fout("convention.out");
	vector <int> times;
	int numCows, numBuses, busCap;
	fin >> numCows >> numBuses >> busCap;
	if (numBuses > numCows)
	{
		fout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < numCows; i++)
	{
		int x;
		fin >> x;
		times.push_back(x);
	}
	sort(times.begin(), times.end());

	vector<int> differences;
	for (int i = 0; i < times.size()-1; i++)
	{
		differences.push_back(times[i + 1] - times[i]);
	}
	vector<pair<int,int>> sets;
	sets.push_back({ 0, times.size() - 1 });

	for (int i = 0; i < numBuses -1; i++) {
		bool cut = false;
		for (int j = 0; j < sets.size(); j++)
		{
			if (sets[j].second - sets[j].first + 1 > busCap)
			{
				int diffInd = findMax(sets[j].first, sets[j].second, differences, -1);
				pair<int, int> first = { sets[j].first, diffInd };
				pair<int, int> second = { diffInd + 1, sets[j].second };
				int firstSize = first.second - first.first + 1;
				int secondSize = second.second - second.first + 1;
				int numFirst = ceil((double)firstSize / busCap);
				int numSecond = ceil((double)secondSize / busCap);
				int h = numBuses - ceil((double)(numCows - firstSize - secondSize) / busCap);
				int g = numFirst + numSecond;
				while (g < h)
				{
					diffInd = findMax(sets[j].first, sets[j].second, differences, diffInd);
					first = { sets[j].first, diffInd };
					second = { diffInd + 1, sets[j].second };
					firstSize = first.second - first.first + 1;
					secondSize = second.second - second.first + 1;
					numFirst = ceil((double)firstSize / busCap);
					numSecond = ceil((double)secondSize / busCap);
				}
				vector<pair<int,int>>::iterator it;
				it = sets.begin() + j;
				sets.erase(it);
				sets.push_back(first);
				sets.push_back(second);
				differences[diffInd] = -1; //possible error
				cut = true;
				break;
			}
		}
		if (!cut)
		{
			int diffInd = findMax(0, times.size()-1, differences, -1);
			for (int j = 0; j < sets.size(); j++)
			{
				if (diffInd >= sets[j].first && diffInd <= sets[j].second)
				{
					pair<int, int> first = { sets[j].first, diffInd };
					pair<int, int> second = { diffInd + 1, sets[j].second };
					int firstSize = first.second - first.first + 1;
					int secondSize = second.second - second.first + 1;
					int numFirst = ceil((double)firstSize / busCap);
					int numSecond = ceil((double)secondSize / busCap);
					while (numFirst + numSecond < numBuses - ceil((double)(numCows - firstSize - secondSize) / busCap))
					{
						diffInd = findMax(sets[j].first, sets[j].second, differences, diffInd);
						first = { sets[j].first, diffInd };
						second = { diffInd + 1, sets[j].second };
						firstSize = first.second - first.first + 1;
						secondSize = second.second - second.first + 1;
						numFirst = ceil((double)firstSize / busCap);
						numSecond = ceil((double)secondSize / busCap);
					}
					vector<pair<int, int>>::iterator it;
					it = sets.begin() + j;
					sets.erase(it);
					sets.push_back(first);
					sets.push_back(second);
				}
			}
			differences[diffInd] = -1; //possible error
		}
	}

	int maxWait = 0;
	for (int i = 0; i < sets.size(); i++)
	{
		maxWait = max(times[sets[i].second] - times[ sets[i].first], maxWait);
	}
	fout << maxWait << endl;
	return 0;
}
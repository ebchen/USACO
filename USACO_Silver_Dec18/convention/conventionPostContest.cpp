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
int numberOfCows, numberOfBuses, capacity;
vector<int> cows;

bool check(int time)
{
	
	int currInd = 0;
	for (int i = 0; i < numberOfBuses; i++)
	{
		if (currInd == numberOfCows) break;
		int firstCowTime = cows[currInd];
		for (int j = 0; j < capacity; j++)
		{
			if (currInd == numberOfCows) break;
			if (cows[currInd] - firstCowTime > time) break;
			currInd++;
		}
	}
	if (currInd == numberOfCows) return true;
	else return false;
}
int binarySearch(int start, int end)
{
	if (start == end) return start;
	if (start + 1 == end)
	{
		if (check(start)) return start;
		else return end;
	}
	int minMaxT = (start + end) / 2;
	if (check(minMaxT))
		return binarySearch(start, minMaxT);
	else
		return binarySearch(minMaxT+1, end);
}



int main()
{
	ifstream fin("convention.in");
	fin >> numberOfCows >> numberOfBuses >> capacity;
	for (int i = 0; i < numberOfCows; i++)
	{
		int x;
		fin >> x;
		cows.push_back(x);
	}
	sort(cows.begin(), cows.end());
	ofstream fout("convention.out");
	fout << binarySearch(0, 1000000000) << endl;
	return 0;
}
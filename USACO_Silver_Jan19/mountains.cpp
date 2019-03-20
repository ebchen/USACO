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
int N;
vector<pair<int, int>> mountainsByY;
vector<pair<int, int>> mountainsByX;
vector<bool> covered;


bool contains(pair<int, int> peakShort, pair<int, int> peakTall)
{
	int distance = abs(peakShort.second - peakTall.second);
	if (peakTall.first - peakShort.first < distance) return false;
	else return true;
}

int main()
{
	ifstream fin("mountains.in");
	fin >> N;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		int x; int y;
		fin >> x >> y;
		//pair<int, int> mountX = { x,y };
		pair<int, int> mountY = { y,x };
		//mountainsByX.push_back(mountX);
		mountainsByY.push_back(mountY);
	}
	sort(mountainsByY.begin(), mountainsByY.end());


	for (int i = 0; i < N; i++)
	{
		pair<int, int> peak = mountainsByY[i];
		bool covered = false;
		if (i != N - 1)
		{
			for (int j = i + 1; j < N; j++)
			{
				pair<int, int> peakTall = mountainsByY[j];
				if (abs(peakTall.second - peak.second) > peakTall.first) continue;
				if (contains(peak, peakTall))
				{
					covered = true;
					break;
				}
			}
		}
		if (covered == false) count++;
	}
	ofstream fout("mountains.out");
	fout << count << endl;
	return 0;
}
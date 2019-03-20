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

class CowArrival
{
public:
	int seniority;
	int arrivalTime;
	int duration;

	CowArrival(int s, int a, int d)
	{
		seniority = s;
		arrivalTime = a;
		duration = d;
	}

	bool operator< (const CowArrival& otherCow) const
	{
		if (arrivalTime <= otherCow.arrivalTime) return true;
		else return false;
	}
};
class Cow
{
public:
	int seniority;
	int arrivalTime;
	int duration;
	int waitTime;
	int inTime;

	Cow(int s, int a, int d)
	{
		seniority = s;
		arrivalTime = a;
		duration = d;
		waitTime = 0;
	}
	
	bool operator< (const Cow& otherCow) const
	{
		if (seniority < otherCow.seniority) return true;
		else return false;
	}
};
/*
void merge(vector<Cow> cows, int left, int middle, int right)
{
	int lSize = middle - left + 1;
	int rSize = right - middle;

	vector<Cow> leftSide;
	leftSide.resize(lSize);
	vector<Cow> rightSide;
	rightSide.resize(rSize);

	for (int i = 0; i < lSize; i++)
		leftSide[i] = cows[left + i];
	for (int j = 0; j < rSize; j++)
		rightSide[j] = cows[middle + 1 + j];

	int a = 0;
	int b = 0;
	int c = left;
	while (a < lSize && b < rSize)
	{
		if (leftSide[a].arrivalTime <= rightSide[b].arrivalTime)
		{
			cows[c] = leftSide[a];
			a++;
		}
		else
		{
			cows[c] = rightSide[b];
			b++;
		}
		c++;
	}

	while (a < lSize)
	{
		cows[c] = leftSide[a];
		a++;
		c++;
	}

	while (b < rSize)
	{
		cows[c] = rightSide[b];
		b++;
		c++;
	}
}

void mergeSort(vector<Cow> cows, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		mergeSort(cows, left, mid);
		mergeSort(cows, mid + 1, right);

		merge(cows, left, mid, right);
	}
}*/

int main()
{
	ifstream fin("convention2.in");
	ofstream fout("convention2.out");
	int N;
	int senCount = 200000;
	fin >> N;
	vector <CowArrival> cowsArrival;
	for (int i = 0; i < N; i++)
	{
		int arriv, dur;
		fin >> arriv >> dur;
		CowArrival cA(senCount, arriv, dur);
		senCount--;
		cowsArrival.push_back(cA);
	}
	sort(cowsArrival.begin(), cowsArrival.end());
	vector<Cow> cows;
	for (int i = 0; i < N; i++)
	{
		Cow c(cowsArrival[i].seniority, cowsArrival[i].arrivalTime, cowsArrival[i].duration);
		cows.push_back(c);
	}

	priority_queue<Cow> line;
	int maxWait = 0;
	bool cont = true;
	int i = 0;
	int time = cows[i].arrivalTime;
	line.push(cows[i]);
	while (cont)
	{
		if (line.empty() && i == cows.size()-1) break;
		else if (line.empty())
		{
			i++;
			time = cows[i].arrivalTime;
			line.push(cows[i]);
		}
		Cow next = line.top();
		line.pop();
		int waitTime = time  - next.arrivalTime;
		maxWait = max(waitTime, maxWait);
		time = time + next.duration;
		while (cont)
		{
			i++;
			if (i == cows.size()) break;
			if (cows[i].arrivalTime <= time) line.push(cows[i]);
			else break;
		}
		i--;
	}
	fout << maxWait << endl;
	return 0;
}
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
	int firstX1, firstY1, firstX2, firstY2, secondX1, secondY1, secondX2, secondY2;

public:
	Solution()
	{
		ifstream fin;
		fin.open("square.in");
		int temp;

		fin >> temp;		//x1
		firstX1 = temp;		
			
		fin >> temp;		//y1
		firstY1 = temp;

		fin >> temp;		//x2
		firstX2 = temp;

		fin >> temp;		//y2
		firstY2 = temp;

		fin >> temp;
		secondX1 = temp;

		fin >> temp;
		secondY1 = temp;

		fin >> temp;
		secondX2 = temp;

		fin >> temp;
		secondY2 = temp;
		

		fin.close();
	}

	int calculateWidth(int firstX1, int firstX2, int secondX1, int secondX2)
	{
		int xs[4] = { firstX1, firstX2, secondX1, secondX2 };
		int min = xs[0];
		int max = xs[0];

		for (int i = 0; i < 4; i++)
		{
			if (xs[i] > max)
			{
				max = xs[i];
			}
			if (xs[i] < min)
			{
				min = xs[i];
			}
		}

		return max - min;
	}

	int calculateHeight(int firstY1, int firstY2, int secondY1, int secondY2)
	{
		int ys[4] = { firstY1, firstY2, secondY1, secondY2 };
		int min = ys[0];
		int max = ys[0];

		for (int i = 0; i < 4; i++)
		{
			if (ys[i] > max)
			{
				max = ys[i];
			}
			if (ys[i] < min)
			{
				min = ys[i];
			}
		}

		return max - min;
	}

	int calculateArea()
	{
		int width = calculateWidth(firstX1, firstX2, secondX1, secondX2);
		int height = calculateHeight(firstY1, firstY2, secondY1, secondY2);

		return pow(max(width, height),2);
		
	}

	void output()
	{
		ofstream fout;
		fout.open("square.out");
		fout << calculateArea();
		fout << endl;
		fout.close();
	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}
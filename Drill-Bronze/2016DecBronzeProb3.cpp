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
	int k;
	int m;
	int n;
	vector<string> shape;
	vector<string> enlargedShape;

public:
	Solution()
	{
		ifstream fin;
		fin.open("cowsignal.in");
		fin >> m;
		fin >> n;
		fin >> k;

		string temp;
		for (int i = 0; i < m; i++)
		{
			fin >> temp;
			shape.push_back(temp);
		}

		fin.close();
	}
	
	void enlarge()
	{
		for (int i = 0; i < m; i++)
		{
			string line = shape[i];
			string newLine = "";
			for (int j = 0; j < line.size(); j++)
			{
				for (int c = 0; c < k; c++)
				{
					newLine = newLine + line[j];
				}
			}
			for (int x = 0; x < k; x++)
			{
				enlargedShape.push_back(newLine);
			}
		}
	}

	void output()
	{
		ofstream fout;
		fout.open("cowsignal.out");
		for (int i = 0; i < enlargedShape.size(); i++)
		{
			fout << enlargedShape[i] << endl;
		}
	}
};

int main()
{
	Solution solution;
	solution.enlarge();
	solution.output();
	return 0;
}
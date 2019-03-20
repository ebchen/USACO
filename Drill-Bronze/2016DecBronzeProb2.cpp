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
	int n;
	int alphabet[26] = { 0 };
	vector<string>boards;

public:
	Solution()
	{
		ifstream fin;
		fin.open("blocks.in");

		fin >> n;

		string side1;
		string side2;
		
		for (int z = 0; z < n; z++)
		{
			int counted[26] = { 0 };
			int counted2[26] = { 0 };
			fin >> side1;
			fin >> side2;
			for (int i = 0; i < side1.size(); i++)
			{
				switch (side1[i])
				{
				case 'a':
					alphabet[0]++;
					counted[0]++;
					break;
				case 'b':
					alphabet[1]++;
					counted[1]++;
					break;
				case 'c':
					alphabet[2]++;
					counted[2]++;
					break;
				case 'd':
					alphabet[3]++;
					counted[3]++;
					break;
				case 'e':
					alphabet[4]++;
					counted[4]++;
					break;
				case 'f':
					alphabet[5]++;
					counted[5]++;
					break;
				case 'g':
					alphabet[6]++;
					counted[6]++;
					break;
				case 'h':
					alphabet[7]++;
					counted[7]++;
					break;
				case 'i':
					alphabet[8]++;
					counted[8]++;
					break;
				case 'j':
					alphabet[9]++;
					counted[9]++;
					break;
				case 'k':
					alphabet[10]++;
					counted[10]++;
					break;
				case 'l':
					alphabet[11]++;
					counted[11]++;
					break;
				case 'm':
					alphabet[12]++;
					counted[12]++;
					break;
				case 'n':
					alphabet[13]++;
					counted[13]++;
					break;
				case 'o':
					alphabet[14]++;
					counted[14]++;
					break;
				case 'p':
					alphabet[15]++;
					counted[15]++;
					break;
				case 'q':
					alphabet[16]++;
					counted[16]++;
					break;
				case 'r':
					alphabet[17]++;
					counted[17]++;
					break;
				case 's':
					alphabet[18]++;
					counted[18]++;
					break;
				case 't':
					alphabet[19]++;
					counted[19]++;
					break;
				case 'u':
					alphabet[20]++;
					counted[20]++;
					break;
				case 'v':
					alphabet[21]++;
					counted[21]++;
					break;
				case 'w':
					alphabet[22]++;
					counted[22]++;
					break;
				case 'x':
					alphabet[23]++;
					counted[23]++;
					break;
				case 'y':
					alphabet[24]++;
					counted[24]++;
					break;
				case 'z':
					alphabet[25]++;
					counted[25]++;
					break;
				}
			}

			
			
			for (int i = 0; i < side2.size(); i++)
			{
				switch (side2[i])
				{
				case 'a':
					alphabet[0]++;
					counted2[0]++;
					break;
				case 'b':
					alphabet[1]++;
					counted2[1]++;
					break;
				case 'c':
					alphabet[2]++;
					counted2[2]++;
					break;
				case 'd':
					alphabet[3]++;
					counted2[3]++;
					break;
				case 'e':
					alphabet[4]++;
					counted2[4]++;
					break;
				case 'f':
					alphabet[5]++;
					counted2[5]++;
					break;
				case 'g':
					alphabet[6]++;
					counted2[6]++;
					break;
				case 'h':
					alphabet[7]++;
					counted2[7]++;
					break;
				case 'i':
					alphabet[8]++;
					counted2[8]++;
					break;
				case 'j':
					alphabet[9]++;
					counted2[9]++;
					break;
				case 'k':
					alphabet[10]++;
					counted2[10]++;
					break;
				case 'l':
					alphabet[11]++;
					counted2[11]++;
					break;
				case 'm':
					alphabet[12]++;
					counted2[12]++;
					break;
				case 'n':
					alphabet[13]++;
					counted2[13]++;
					break;
				case 'o':
					alphabet[14]++;
					counted2[14]++;
					break;
				case 'p':
					alphabet[15]++;
					counted2[15]++;
					break;
				case 'q':
					alphabet[16]++;
					counted2[16]++;
					break;
				case 'r':
					alphabet[17]++;
					counted2[17]++;
					break;
				case 's':
					alphabet[18]++;
					counted2[18]++;
					break;
				case 't':
					alphabet[19]++;
					counted2[19]++;
					break;
				case 'u':
					alphabet[20]++;
					counted2[20]++;
					break;
				case 'v':
					alphabet[21]++;
					counted2[21]++;
					break;
				case 'w':
					alphabet[22]++;
					counted2[22]++;
					break;
				case 'x':
					alphabet[23]++;
					counted2[23]++;
					break;
				case 'y':
					alphabet[24]++;
					counted2[24]++;
					break;
				case 'z':
					alphabet[25]++;
					counted2[25]++;
					break;

				}
			}

			for (int i = 0; i < 26; i++)
			{
				int dup = min(counted[i], counted2[i]);
				alphabet[i] = alphabet[i] - dup;
			}
		}

		fin.close();
		
	}

	void output()
	{
		ofstream fout;
		fout.open("blocks.out");
		for (int i = 0; i < 26; i++)
		{
			fout << alphabet[i] << endl;
		}
	}

};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}
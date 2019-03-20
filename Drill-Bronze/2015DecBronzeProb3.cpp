/*
ID: echen
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

public:
	int numberOfFriends;
	int numberOfMilks;
	
	vector <vector<int>> sickFriends;
	vector <vector<int>> log;
	vector <int> badMilks;

	Solution()
	{
		ifstream fin("badmilk.in");
		fin >> numberOfFriends;
		fin >> numberOfMilks;
		int rows;
		int sicks;
		fin >> rows;
		fin >> sicks;
		for (int i = 0; i < rows; i++)
		{
			int person;
			fin >> person;
			int milk;
			fin >> milk;
			int time;
			fin >> time;

			vector<int> entry = { person, milk , time };
			log.push_back(entry);
		}
		for (int i = 0; i < sicks; i++)
		{
			int person;
			fin >> person;
			int time;
			fin >> time;
			vector<int> entry = { person, time };
			sickFriends.push_back(entry);
		}

		
	}

	void indentifyBadMilks()
	{
		
		for (int i = 1; i <= numberOfMilks; i++)
		{
			vector<bool> singleMilk;
			vector <int> counted;
			for (int j = 0; j < sickFriends.size(); j++)
			{
				int illFriend = sickFriends[j][0];
				int timeIll = sickFriends[j][1];

				for (int k = 0; k < log.size(); k++)
				{
					if ((log[k][0] == illFriend) && (log[k][1] == i) && (log[k][2] < timeIll))
					{
						bool count = false;
						for (int x = 0; x < counted.size(); x++)
						{
							if (counted[x] == illFriend)
							{
								count = true;
							}
						}
						if (count == false)
						{
							singleMilk.push_back(true);
							counted.push_back(illFriend);
						}
						
					}
				}
			}

			if (singleMilk.size() == sickFriends.size())
			{
				badMilks.push_back(i);
			}
			
		}

		
		
	}

	void outputMinimumNeeded()
	{
		int max = 0;
		for (int i = 0; i < badMilks.size(); i++)
		{
			int needed = 0;
			vector<int>counted;
			int theMilk = badMilks[i];
			for (int i = 0; i < log.size(); i++)
			{
				if (log[i][1] == theMilk)
				{
					bool c = false;
					for (int x = 0; x < counted.size(); x++)
					{
						if (log[i][0] == counted[x])
						{
							c = true;
						}
					}
					if (c == false)
					{
						needed++;
						counted.push_back(log[i][0]);
					}
				}
			}
			if (needed > max)
			{
				max = needed;
			}
		}

		ofstream fout("badmilk.out");
		fout << max << endl;
	}

};

int main()
{
	Solution solution;
	solution.indentifyBadMilks();
	solution.outputMinimumNeeded();
	return 0;
}
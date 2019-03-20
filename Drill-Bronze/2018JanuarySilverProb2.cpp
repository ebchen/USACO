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
	int cows;
	int stores;
	int neighbors;
	vector <int> production;
	vector <pair<int,int>> prices;
	vector <int> rents;
	int profit;
public:
	Solution()
	{
		profit = 0;
		ifstream fin("rental.in");
		fin >> cows;
		fin >> stores;
		fin >> neighbors;
		
		for (int i = 0; i < cows; i++)
		{
			int amount;
			fin >> amount;
			production.push_back(amount);
			sort(production.begin(), production.end());
		}
		for (int i = 0; i < stores; i++)
		{
			int amount;
			int price;
			fin >> amount;
			fin >> price;
			pair<int, int> p(price, amount);
			prices.push_back(p);
			sort(prices.begin(), prices.end());
		}
		for (int i = 0; i < neighbors; i++)
		{
			int rent;
			fin >> rent;
			rents.push_back(rent);
			sort(rents.begin(), rents.end());
		}
	}

	
	void outputProfit()
	{

		if (rents.size() == 0)
		{
			for (int i = production.size() - 1; i >= 0; i--)
			{
				int possibleFromMilk = 0;
				int gallons = production[i];

				int gallonsLeft = -1;
				while ((gallonsLeft != 0)&& (prices.size() != 0))
				{
					possibleFromMilk += (gallons*prices[prices.size()-1].first);

					if (prices[prices.size() - 1].second - gallons <= 0)
					{
						gallonsLeft = abs(prices[prices.size() - 1].second - gallons);
						prices.pop_back();
					}
					else
					{
						prices[prices.size() - 1].second -= gallons;
						gallonsLeft = 0;
					}
				}
				profit += possibleFromMilk;
			}
		}

		else if (production.size() == 0)
		{
			for (int i = 0; i < cows; i++)
			{
				if (rents.size() != 0)
				{
					int rent = rents.back();
					profit += rents.back();
					rents.pop_back();
				}
			}
		}
		
		else
		{
			vector <int> milkingProfits;
			int i = 0;
			bool minDone = false;
			while ((!minDone)&&(production.size() != 0))
			{
				vector <pair<int, int>> copy = prices;
				int possibleFromMilk = 0;
				int gallons = production[i];
				int gallonsLeft = -1;
				while ((gallonsLeft != 0) && (copy.size() != 0))
				{
					possibleFromMilk += (gallons*copy[copy.size() - 1].first);

					if (copy[copy.size() - 1].second - gallons <= 0)
					{
						gallonsLeft = abs(copy[copy.size() - 1].second - gallons);
						copy.pop_back();
					}
					else
					{
						copy[copy.size()-1].second -= gallons;
						gallonsLeft = 0;
					}
				}

				if ((possibleFromMilk > rents.back()) || (rents.size() == 0))
				{
					minDone = true;
				}
				else
				{
					profit += rents.back();
					rents.pop_back();
					production.erase(production.begin());
				}
			}

			bool maxDone = false;
			
			while ((!maxDone) && (production.size() != 0))
			{
				int j = production.size() - 1;
				vector <pair<int, int>> copy = prices;
				int possibleFromMilk = 0;
				int gallons = production[j];
				int gallonsLeft = gallons;
				while ((gallonsLeft != 0) && (copy.size() != 0))
				{
					possibleFromMilk += (gallonsLeft*copy[copy.size() - 1].first);

					if (copy[copy.size() - 1].second - gallonsLeft <= 0)
					{
						gallonsLeft = abs(copy[copy.size() - 1].second - gallonsLeft);
						possibleFromMilk -= gallonsLeft*copy[copy.size() - 1].first;
						copy.pop_back();
					}
					else
					{
						copy[copy.size() - 1].second -= gallons;
						gallonsLeft = 0;
					}
				}

				if ((possibleFromMilk > rents.back()) || (rents.size() == 0))
				{
					profit += possibleFromMilk;
					prices = copy;
					production.pop_back();
				}
				else
				{
					maxDone = true;
				}
			}

			for (int k = 0; k < production.size(); k++)
			{
				vector <pair<int, int>> copy = prices;
				int possibleFromMilk = 0;
				int gallons = production[k];
				int gallonsLeft = -1;
				while ((gallonsLeft != 0) && (copy.size() != 0))
				{
					possibleFromMilk += (gallons*copy[copy.size() - 1].first);

					if (copy[copy.size() - 1].second - gallons <= 0)
					{
						gallonsLeft = abs(copy[copy.size() - 1].second - gallons);
						copy.pop_back();
					}
					else
					{
						copy[copy.size() - 1].second -= gallons;
						gallonsLeft = 0;
					}
				}

				if ((possibleFromMilk > rents.back()) || (rents.size() == 0))
				{
					profit += possibleFromMilk;
					prices = copy;
					production.pop_back();
				}
				else
				{
					profit += rents.back();
					rents.pop_back();
					production.erase(production.begin());
				}
			}
		}

		ofstream fout("rental.out");
		fout << profit;
		cout << profit;
	}
};

int main()
{
	Solution solution;
	solution.outputProfit();
	return 0;
}
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
bool myfunction(string &i, string &j) { return (strcmp(i.c_str(),j.c_str()) <= 0) ? true : false; }
void p22()
{
	ifstream fp;

	fp.open("p022_names.txt", ifstream::in);

	if (!fp.is_open())
		return;


	string line;
	getline(fp, line);
	
	fp.close();
	
	vector<string> names;
	int i = 0, j = 0;
	for (; (i<line.length())&&((j = line.find(',', i)) != string::npos);i = j+1)
	{
		names.push_back(line.substr(i+1, j-i-2));
	}

	if (j == string::npos)
		names.push_back(line.substr(i + 1, line.length()-i-2));

	sort(names.begin(), names.end(), myfunction);
	unsigned long long score = 0;
	for (int i = 0; i < names.size(); i++)
	{
		unsigned long long ascore = 0;
		for (int j = 0; j < names[i].length(); j++)
		{
			//if (names[i][j] == '"')
			//	continue;
			ascore += names[i][j] - 'A' + 1;
		}
		score += ascore*(i + 1);
	}

	printf("%llu", score);
	while (1);

}
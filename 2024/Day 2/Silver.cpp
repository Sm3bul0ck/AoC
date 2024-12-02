#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;

int main()
{
    int safePaths = 0;
    vector<int> Line;

    ifstream inputFile("bigboy.txt");
    string line;

    while (getline(inputFile, line))
    {
        Line.clear();
        stringstream ss(line);

        int intline;
        while (ss >> intline)
        {
            Line.push_back(intline);
        }

        bool increasing = true;
        bool decreasing = true;
        bool safeDomain = true;

        for (int i = 0; i < Line.size() - 1; i++)
        {
            if (Line[i] >= Line[i + 1])
            {
                increasing = false;
            }
            if (Line[i] <= Line[i + 1])
            {
                decreasing = false;
            }

            if (abs(Line[i] - Line[i + 1]) < 1 || abs(Line[i] - Line[i + 1]) > 3)
            {
                safeDomain = false;
            }
        }

        if ((increasing || decreasing) && safeDomain)
        {
            safePaths++;
        }
    }

    cout << "There are " << safePaths << " safe paths.";
    return 0;
}

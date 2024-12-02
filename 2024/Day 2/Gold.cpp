#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;

bool isSafe(vector<int> &currentLine)
{
    bool con1 = true;
    bool increasing = true;
    bool decreasing = true;
    bool safeDomain = true;

    for (int i = 0; i < currentLine.size() - 1; i++)
    {
        if (currentLine[i] >= currentLine[i + 1])
        {
            increasing = false;
        }
        if (currentLine[i] <= currentLine[i + 1])
        {
            decreasing = false;
        }

        con1 = increasing || decreasing;

        if (abs(currentLine[i] - currentLine[i + 1]) < 1 || abs(currentLine[i] - currentLine[i + 1]) > 3)
        {
            safeDomain = false;
        }
    }
    return (increasing || decreasing) && safeDomain;
}

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

        if (isSafe(Line))
        {
            safePaths++;
        }
        else
        {

            for (int i = 0; i < Line.size(); i++)
            {
                vector<int> modifiedLine = Line;
                modifiedLine.erase(modifiedLine.begin() + i);

                if (isSafe(modifiedLine))
                {
                    safePaths++;
                    break;
                }
            }
        }
    }
    cout << "There are " << safePaths << " safe paths.";
}
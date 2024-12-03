#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    ifstream input_file("bigboy.txt");
    regex mul_regex("mul\\((\\d{1,3}),(\\d{1,3})\\)");
    int total_sum = 0;
    string line;

    while (getline(input_file, line))
    {
        sregex_iterator iter(line.begin(), line.end(), mul_regex);
        sregex_iterator end;

        while (iter != end)
        {
            smatch match = *iter;

            int x = stoi(match[1].str());
            int y = stoi(match[2].str());

            total_sum += x * y;

            ++iter;
        }
    }
    cout << "Total sum of multiplications: " << total_sum << endl;
}
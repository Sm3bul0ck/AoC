#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    vector<char> input;
    ifstream file("bigboy.txt");
    string line;
    bool mul_enabled = true;
    int sum = 0;
    getline(file, line);

    for (char ch : line)
    {
        input.push_back(ch);
    }

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == 'd')
        {
            if (input[i + 1] == 'o')
            {
                if (input[i + 2] == '(')
                {
                    if (input[i + 3] == ')')
                    {
                        mul_enabled = true;
                        i += 3;
                        continue;
                    }
                }
                else if (input[i + 1] == 'o')
                {
                    if (input[i + 2] == 'n')
                    {
                        if (input[i + 3] == '\'')
                        {
                            if (input[i + 4] == 't')
                            {
                                if (input[i + 5] == '(')
                                {
                                    if (input[i + 6] == ')')
                                    {
                                        mul_enabled = false;
                                        i += 6;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        if (input[i] == 'm' && mul_enabled)
        {
            if (input[i + 1] == 'u')
            {
                if (input[i + 2] == 'l')
                {
                    if (input[i + 3] == '(')
                    {
                        int k = i + 4;
                        string num1 = "";
                        string num2 = "";

                        while (isdigit(input[k]) && num1.length() < 3)
                        {
                            num1 += input[k];
                            k++;
                        }

                        if (input[k] == ',')
                        {
                            k++;
                            string num2 = "";
                            while (isdigit(input[k]) && num2.length() < 3)
                            {
                                num2 += input[k];
                                k++;
                            }

                            if (input[k] == ')')
                            {
                                int x = stoi(num1);
                                int y = stoi(num2);
                                sum += x * y;
                                i = k;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "Sum of enabled multiplications: " << sum << endl;

    return 0;
}
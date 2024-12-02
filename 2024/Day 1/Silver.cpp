#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
int main()
{
    vector<int> l1, l2;
    int a, b;
    ifstream in("bigboy.txt");
    while (in >> a >> b)
    {
        l1.push_back(a);
        l2.push_back(b);
    }
    sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());
    long long sum = 0;
    for (int i = 0; i < l1.size(); i++)
    {
        sum += abs(l1[i] - l2[i]);
    }
    cout << sum;
}

#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int source;
    int dest;
};

int main()
{
    vector<int> v = {1, 2, 3};
    for (auto item : v)
    {
        cout << item << endl;
    }

    return 0;
}
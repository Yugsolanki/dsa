#include <vector>
#include <iostream>
using namespace std;

bool lemonadeChange(vector<int> bills)
{
    int fives = 0, tens = 0, twenties = 0;

    for (int i = 0; i < bills.size(); i++)
    {
        if (bills[i] == 5)
        {
            fives++;
        }
        else if (bills[i] == 10)
        {
            if (fives)
            {
                fives--;
                tens++;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (tens && fives)
            {
                fives--;
                tens--;
                twenties++;
            }
            else if (fives >= 3)
            {
                fives -= 3;
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    vector<int> bills = {5, 5, 10, 10, 20};
    cout << lemonadeChange(bills) << endl;
    return 0;
}
#include "utilities.h"

void print2DVector(const vector<vector<int>> &vec)
{
    cout << "Printing 2D Vector:" << endl;
    if (vec.empty())
    {
        cout << "  (Vector is empty)" << endl;
        return;
    }

    // Iterate through each inner vector (row)
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << "  Row " << i << ": [";
        // Iterate through each element in the current inner vector
        for (size_t j = 0; j < vec[i].size(); ++j)
        {
            cout << vec[i][j];
            // Add a comma and space if it's not the last element in the row
            if (j < vec[i].size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
}
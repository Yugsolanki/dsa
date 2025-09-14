#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job
{
    int id;
    int deadline;
    int profit;
};

bool compareJobs(const Job &a, const Job &b)
{
    return a.profit > b.profit;
}

int jobSequencingProblem(vector<Job> &jobs)
{
    int maxDeadline = 0;
    for (auto job : jobs)
    {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // array of size maxDeadline + 1 to avoid an out-of-bounds access
    vector<int> slots(maxDeadline + 1, -1);
    int profit = 0;

    for (int i = 0; i < jobs.size(); i++)
    {
        Job job = jobs[i];

        // There is no "day 0" in this context; the first possible day to complete a job is day 1.
        for (int j = job.deadline; j >= 1; j--)
        {
            if (slots[j] == -1)
            {
                slots[j] = job.id;
                profit += job.profit;
                break;
            }
        }
    }

    return profit;
}

int main()
{
    vector<Job> jobs = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}};

    sort(jobs.begin(), jobs.end(), compareJobs);
    cout << jobSequencingProblem(jobs) << endl; // Output: 60

    vector<Job> jobs2 = {
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 3, 15},
        {6, 2, 30}};
    sort(jobs2.begin(), jobs2.end(), compareJobs);
    cout << jobSequencingProblem(jobs2) << endl; // Output: 145

    return 0;
}
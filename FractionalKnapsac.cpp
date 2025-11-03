#include <bits/stdc++.h>
using namespace std;

// Partition function for QuickSort (descending order by .first)
int partition(vector<pair<double, int>> &nums, int low, int high)
{
    double pivot = nums[high].first; // choose last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (nums[j].first >= pivot) // >= for descending order
        {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[high]);
    return i + 1;
}

// QuickSort function
void quickSort(vector<pair<double, int>> &nums, int low, int high)
{
    if (low < high)
    {
        int pi = partition(nums, low, high);

        quickSort(nums, low, pi - 1);
        quickSort(nums, pi + 1, high);
    }
}

int FracKnapsack(vector<int> p, vector<int> w, int c, vector<float> &selected)
{
    double maxp = 0;
    int n = p.size();

    vector<pair<double, int>> pw;

    for (int i = 0; i < n; i++)
    {
        pw.push_back({(double)p[i] / w[i], i});
    }

    quickSort(pw, 0, pw.size() - 1);

    for (int i = 0; i < pw.size(); i++)
    {
        int ind = pw[i].second;

        if (w[ind] <= c)
        {
            c = c - w[ind];
            maxp = maxp + p[ind];
            selected[i] = 1;
        }
        else
        {
            maxp = maxp + (c * pw[i].first);
            selected[i] = (float)c / w[ind];
            break;
        }
    }

    return maxp;
}

int main()
{
    cout << "\nTest Case 1\n";
    vector<int> profit = {5, 10, 15, 7, 8, 9, 4};
    vector<int> weight = {1, 3, 5, 4, 1, 3, 2};
    vector<float> selected(profit.size(), 0);
    int capacity = 15;

    double ans = FracKnapsack(profit, weight, capacity, selected);

    cout << "Maximum Profit= " << ans << "\n";
    cout << "Selected Items = [";
    for (int i = 0; i < selected.size(); i++)
    {
        cout << selected[i] << ",";
    }
    cout << ']';

    cout << "\n\nTest Case 2\n";
    vector<int> profit1 = {60, 100, 120};
    vector<int> weight1 = {10, 20, 30};
    vector<float> selected1(profit1.size(), 0);
    int capacity1 = 50;

    double ans1 = FracKnapsack(profit1, weight1, capacity1, selected1);

    cout << "Maximum Profit= " << ans1 << "\n";
    cout << "Selected Items = [";
    for (int i = 0; i < selected1.size(); i++)
    {
        cout << selected1[i] << ",";
    }
    cout << ']';

    cout << "\n\nTest Case 3\n";
    vector<int> profit2 = {10, 5, 15, 7, 6, 18, 3};
    vector<int> weight2 = {2, 3, 5, 7, 1, 4, 1};
    vector<float> selected2(profit2.size(), 0);
    int capacity2 = 15;

    double ans2 = FracKnapsack(profit2, weight2, capacity2, selected2);

    cout << "Maximum Profit= " << ans2 << "\n";
    cout << "Selected Items = [";
    for (int i = 0; i < selected2.size(); i++)
    {
        cout << selected2[i] << ",";
    }
    cout << "]\n";
    return 0;
}

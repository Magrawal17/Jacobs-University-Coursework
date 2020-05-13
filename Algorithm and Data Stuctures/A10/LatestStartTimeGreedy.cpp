#include <iostream>
using namespace std;

struct Activitiy
{
    int start, finish;
};

bool activityCompare(Activitiy s1, Activitiy s2)
{
    return (s1.start < s2.start);
}

void lateststarttime(Activitiy arr[], int n)
{

    sort(arr, arr + n, activityCompare); //sorted according to there start time unlike the one in which you sort it accroding;
                                        // finsih time

    cout << "\nFollowing activities are selected\n";
    int i = n - 1;
    cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";

    for (int j = n - 2; j >= 0; j--)
    {
        if (arr[j].finish <= arr[i].start)
        {
            cout << "(" << arr[j].start << ", " << arr[j].finish << "), ";
            i = j;
        }
    }
}

int main()
{
    Activitiy arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);
    lateststarttime(arr, n);
    return 0;
}

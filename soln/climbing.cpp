/*

Name:  Aryan Rusia
SID:   1669003
CCID:  rusia
CMPUT 275 Winter 2022
Weekly Exercise 7 - Divide and Conquer
-------------------------------------------

*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned int uint;

// Forward declaration of function "climbing"
uint climbing(const uint *heights, uint length, uint rest, uint limit);

int main()
{
    // Declaring variables and taking corresponding inputs;

    // Shows length of peak array
    uint index;
    cin >> index;

    // Rest Time
    uint rest;
    cin >> rest;

    // Maximum limit of time
    uint limit;
    cin >> limit;

    // Declaring peak array, storing heights of mountain
    uint peak[index] = {};

    // Taking inputs for peak array
    for (uint i = 0; i < index; i++)
    {
        cin >> peak[i];
    }

    // Calling the climbing function and printing the output
    cout << climbing(peak, index, rest, limit) << endl;

    return 0;
}

uint climbing(const uint *heights, uint length, uint rest, uint limit)
{
    /*

    Description : This function determines the minimum value of burst, required to
                  reach the highest peak of mountain, within a time limit. In between
                  rest time is also considered.

    Arguements :

        const uint *heights : Array which contains the value of peaks
        uint length : It gives the length of the array
        uint rest : It gives us the value of rest time
        uint limit : It gives us the value of maximum amount of time to climb the mountain.

    Return :
        uint : Returns the value of minimum burst

    */

    // Flags if rest time == 0
    bool cond1 = (rest == 0);

    // Flags if the length is 1
    bool cond2 = (length == 1);

    // Flags if the limit is equal to the max peak value
    bool cond3 = (limit == heights[length - 1]);

    // Declaring and initializing the higher index
    uint higher_index = heights[length - 1];

    // Declaring the lower index
    uint lower_index;

    // Declaring the middle index [(low+high)/2]
    uint mid_index;

    // Declaring the maximum height difference
    uint max_height_diff = heights[0];

    // This variable stores the difference in heights of peaks
    uint delta_height;

    // The max peak is equal to last element of peak array
    uint mountain_peaks_num = (length - 1);

    // While loop to find the maximum height diff and the lower index
    uint index = (length - 1 - mountain_peaks_num);

    while (mountain_peaks_num != 0)
    {
        delta_height = (heights[index + 1] - heights[index]);

        // Finds the maximum difference in heights
        max_height_diff = max(max_height_diff, delta_height);

        // lower index is equal to the max height difference
        lower_index = max_height_diff;

        // Initializing the value of mid index as [(high+low)/2]
        mid_index = (higher_index + lower_index) / 2;

        mountain_peaks_num--;
    }

    // Execute while loop to find the lower/higher index, which actually stores our answer
    while (true)
    {
        uint min_burst_time = 0;

        uint mid_change = mid_index;

        uint iter = 0;

        while (iter < length)
        {
            // The if-else condition is finding the difference in heights of consecutice peaks
            if (iter == 0)
            {
                delta_height = heights[iter];
            }
            else
            {
                delta_height = (heights[iter] - heights[iter - 1]);
            }

            // The condition flags if the difference in heights is greater than mid value
            bool cond4 = (delta_height > mid_change);

            // Adds the rest time and difference in heights
            uint sum = delta_height + rest;

            // Adding the sum in the min_burst_time
            min_burst_time = min_burst_time + sum;

            // If cond4 is true, then update mid_change as equal to the mid_index
            if (cond4)
            {
                mid_change = mid_index;
            }

            // If diff in heights is less than the mid value, then subtract the value fo rest
            if (!cond4)
            {
                min_burst_time = min_burst_time - rest;
            }

            // Value of mid_change gets updated
            mid_change = mid_change - delta_height;

            iter++;
        }

        // Updating lower index
        if (min_burst_time > limit)
        {
            lower_index = mid_index + 1;
        }

        // Updating higher index
        else if (limit >= min_burst_time)
        {
            higher_index = mid_index;
        }

        // If low index is equal to the high index, then break the loop
        if (lower_index == higher_index)
            break;

        // Update the value of middle index
        mid_index = (higher_index + lower_index) / 2;
    }

    uint answer = lower_index;

    // If cond1 is true, then return the maximum height difference will be the minimum busrt time.
    if (cond1)
    {
        answer = max_height_diff;
    }

    // If cond2 is true, then return the value of height stored at index 0.
    if (cond2)
    {
        answer = heights[0];
    }

    // If cond3 is true, then return the value of maximum height of the mountain.
    if (cond3)
    {
        answer = heights[length - 1];
    }

    return answer;
}
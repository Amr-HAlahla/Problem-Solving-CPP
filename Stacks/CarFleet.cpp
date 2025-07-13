#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

/*
This solution computes the number of car fleets that will arrive at the target.
- Each car is paired with its position and the time it takes to reach the target.
- Cars are sorted by position in descending order (closest to the target first).
- We iterate from the car closest to the target to the farthest.
- If a car takes longer to reach the target than the last fleet, it forms a new fleet.
- Otherwise, it joins the fleet ahead of it (since it cannot pass).
- The number of fleets is incremented only when a car cannot catch up to the fleet ahead.
*/

int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    int n = position.size();
    vector<pair<int, double>> cars;

    // Pair each car's position with its arrival time
    for (int i = 0; i < n; ++i)
    {
        double time = (double)(target - position[i]) / speed[i];
        cars.push_back({position[i], time});
    }

    // Sort by position descending (closest to target first)
    sort(cars.rbegin(), cars.rend());

    int fleets = 0;
    double lastTime = 0;

    for (auto &[pos, time] : cars)
    {
        if (time > lastTime)
        {
            fleets++;        // New fleet
            lastTime = time; // Update last fleet arrival time
        }
        // Else: it joins previous fleet (do nothing)
    }

    return fleets;
}

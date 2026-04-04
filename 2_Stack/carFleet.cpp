#include<iostream>
#include<vector>
#include<algorithm>
#include<stack> 

using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, int>> cars;

    for(int i=0; i<position.size(); i++) {
        cars.push_back({position[i], speed[i]});
    }

    sort(cars.rbegin(), cars.rend());

    stack<double> fleetStack;

    for(const auto& car : cars) {
        double timeFleet = static_cast<double>(target - car.first) / car.second;

        if(fleetStack.empty() || timeFleet > fleetStack.top()) {
            fleetStack.push(timeFleet);
        }
    }
    return fleetStack.size();
}

int main() {
    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};

    int result = carFleet(target, position, speed);
    cout << "Number of car fleets: " << result << endl;  // Output should be 3

    return 0;
}


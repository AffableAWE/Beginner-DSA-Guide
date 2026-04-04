#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<double> getCollisionTimes(vector<vector<int>>& cars) {
    int n = cars.size();
    vector<double> result(n, -1);
    stack<int> st;

    // Iterate over the cars in reverse order
    for (int i = n - 1; i >= 0; i--) {
        int position = cars[i][0];
        int speed = cars[i][1];

        // Check the stack to find collisions
        while (!st.empty()) {
            int j = st.top();
            int positionAhead = cars[j][0];
            int speedAhead = cars[j][1];

            // If the current car is slower or has the same speed, no collision possible
            if (speed <= speedAhead) {
                st.pop();
                continue;
            }

            // Calculate the time of collision
            double collisionTime = (double)(positionAhead - position) / (speed - speedAhead);

            // Check if the collision time is valid and within bounds
            if (result[j] == -1 || collisionTime <= result[j]) {
                result[i] = collisionTime;
                break;
            }
            
            st.pop();
        }

        // Push the current car's index onto the stack
        st.push(i);
    }

    return result;
}

int main() {
    // Input: [[1,2],[2,1],[4,3],[7,2]]
    vector<vector<int>> cars = {{1, 2}, {2, 1}, {4, 3}, {7, 2}};

    vector<double> result = getCollisionTimes(cars);

    // Print the result
    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}



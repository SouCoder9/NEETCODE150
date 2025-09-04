#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<double, double>> cars;
    for (int i = 0; i < position.size(); i++) {
        double time = (double)(target - position[i]) / speed[i];
        cars.push_back({position[i], time});
    }
    sort(cars.begin(), cars.end(), greater<pair<double, double>>());
    int fleets = 0;
    double currTime = 0;
    for (const auto& car : cars) {
        if (car.second > currTime) {
            fleets++;
            currTime = car.second;
        }
    }
    return fleets;
}
int main(){
    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};
    int result = carFleet(target, position, speed);
    cout << "Number of car fleets: " << result << endl;
    return 0;
}
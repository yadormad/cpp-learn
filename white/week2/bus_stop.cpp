#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm> 

using namespace std;

map<string, vector<string>> bus_routes;
vector<string> bus_list;

vector<string> BusesForStops(const string& stop) {
    vector<string> buses;
    for (const auto& bus : bus_list) {
        auto stop_it = find(bus_routes[bus].begin(), bus_routes[bus].end(), stop);
        if (stop_it != bus_routes[bus].end()) {
            buses.push_back(bus);
        }
    }
    return buses;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "NEW_BUS") {
            string bus;
            int stop_count;
            cin >> bus >> stop_count;
            vector<string> stops(stop_count);
            for (auto& stop: stops) {
                cin >> stop;
            }
            bus_routes[bus] = stops;
            bus_list.push_back(bus);
        }
        if (command == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            auto buses = BusesForStops(stop);
            if (buses.empty()) {
                cout << "No stop" << endl;
            } else {
                for (const auto& bus : buses) {
                    cout << bus << ' ';
                }
                cout << endl;
            }
        }
        if (command == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            auto bus_route = bus_routes.find(bus);
            if (bus_route == bus_routes.end()) {
                cout << "No bus" << endl;
            } else {
                for (auto stop : bus_route->second) {
                    auto interchanges = BusesForStops(stop);
                    interchanges.erase(find(interchanges.begin(), interchanges.end(), bus));
                    cout << "Stop " << stop << ": ";
                    if (interchanges.empty()) {
                        cout << "no interchange" << endl;
                    } else {
                        for (auto interchange : interchanges) {
                            cout << interchange << ' ';
                        }
                        cout << endl;
                    }
                }
            }
        }
        if (command == "ALL_BUSES") {
            if (bus_routes.empty()) {
                cout << "No buses" << endl;
            } else {
                for (const auto& bus_route : bus_routes) {
                    cout << "Bus " << bus_route.first << ": ";
                    for (const auto& stop : bus_route.second) {
                        cout << stop << ' ';
                    }
                    cout << endl;
                }
            }
        }
    }
}

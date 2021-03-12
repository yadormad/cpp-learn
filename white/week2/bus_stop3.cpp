#include <string>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<set<string>, int> bus_routes;
    int route_counter = 0;
    for (int i = 0; i < n; i++) {
        int stops_count;
        cin >> stops_count;
        set<string> stops;
        for (int j = 0; j < stops_count; j++) {
            string stop;
            cin >> stop;
            stops.insert(stop);
        }
        auto route_it = bus_routes.find(stops);
        if (route_it == bus_routes.end()) {
            bus_routes[stops] = ++route_counter;
            cout << "New bus " << route_counter << endl;
        } else {
            cout << "Already exists for " << bus_routes[stops] << endl;
        }
    }
}

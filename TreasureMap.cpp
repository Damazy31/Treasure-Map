#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "Treasure.h"

using namespace std;

int treasureMap(string map) {
	int level = 0;
	int result = -1;
	int number_of_treasures = 0;
	vector <Treasure> treasures;
	vector <pair<int, int>> numbers_of_treasures_on_levels;

	for (int i = 0; i < map.length(); i++) {
		if (map[i] == '(') {
			level--;
		}
		else if (map[i] == ')') {
			level++;
		}
		else if (map[i] == '*') {
			Treasure new_treasure = Treasure(i,level);
			number_of_treasures++;
			treasures.push_back(new_treasure);
			if (numbers_of_treasures_on_levels.size() > 0) {
				bool flag = true;
				for (int j = 0; j < numbers_of_treasures_on_levels.size(); j++) {
					if (numbers_of_treasures_on_levels[j].second == new_treasure.getLevel()) {
						numbers_of_treasures_on_levels[j].first++;
						flag = false;
						break;
					}
				}
				if (flag) {
					pair<int, int> new_number_of_treasures_on_level(1, new_treasure.getLevel());
					numbers_of_treasures_on_levels.push_back(new_number_of_treasures_on_level);
				}
			}
			else {
				pair<int, int> new_number_of_treasures_on_level(1, new_treasure.getLevel());
				numbers_of_treasures_on_levels.push_back(new_number_of_treasures_on_level);
			}
		}
	}

	sort(numbers_of_treasures_on_levels.rbegin(), numbers_of_treasures_on_levels.rend());
	
	for (int i = 0; i < number_of_treasures; i++) {
		if (numbers_of_treasures_on_levels[0].second == treasures[i].getLevel()) {
			result = treasures[i].getId();
			break;
		}
	}

	return result;
}

int main() {
	int result;
	string map;
	cout << "Insert map: ";
	cin >> map;
	result = treasureMap(map);
	cout << "Result: " << result << "\n";
	return 0;
}

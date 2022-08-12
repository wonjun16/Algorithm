#include<iostream>
#include<vector>
#include<algorithm>

bool compare(std::pair<std::string, std::pair<int, int>> a, std::pair<std::string, std::pair<int, int>> b) {
	if (a.second.first == b.second.first)
		return a.second.second > b.second.second;
	else
		return a.second.first > b.second.first;
}

void main() {
	std::vector<std::pair<std::string, std::pair<int, int>>> students;
	students.push_back(std::pair<std::string, std::pair<int, int>>("student1", std::pair<int, int>(90, 19980716)));
	students.push_back(std::pair<std::string, std::pair<int, int>>("student2", std::pair<int, int>(87, 19970614)));
	students.push_back(std::pair<std::string, std::pair<int, int>>("student3", std::pair<int, int>(90, 19981123)));
	students.push_back(std::pair<std::string, std::pair<int, int>>("student4", std::pair<int, int>(95, 19960203)));
	students.push_back(std::pair<std::string, std::pair<int, int>>("student5", std::pair<int, int>(96, 19970913)));
	std::sort(students.begin(), students.end(), compare);
	for (int i = 0; i < students.size(); i++)
		std::cout << students[i].first << ' ';
}
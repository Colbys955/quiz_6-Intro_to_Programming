/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Structure for veteran information
struct Veteran {
	string name;
	int age;
	vector<string> medals; // Each veteran can have multiple medals
};

// Function prototypes
void displayBanner();
void addVeteran(vector<Veteran>& veterans);
void displayVeterans(const vector<Veteran>& veterans);
void searchByMedal(const vector<Veteran>& veterans);
void medalStatistics(const vector<Veteran>& veterans);
void removeVeteran(vector<Veteran>& veterans);
void sortVeteransByAge(vector<Veteran>& veterans);

int main() {
	vector<Veteran> veterans;
	int choice;

	displayBanner();

	do {
		cout << "\n=== MAIN MENU ===\n";
		cout << "1. Add a veteran and their medals\n";
		cout << "2. Display all veterans and medals\n";
		cout << "3. Search veterans by medal\n";
		cout << "4. Show medal statistics\n";
		cout << "5. Remove a veteran by name\n";
		cout << "6. Sort veterans by age\n";
		cout << "7. Exit\n";
		cout << "Choose an option (1-7): ";
		cin >> choice;
		cin.ignore(); // clear newline

		switch(choice) {
		case 1:
			addVeteran(veterans);
			break;
		case 2:
			displayVeterans(veterans);
			break;
		case 3:
			searchByMedal(veterans);
			break;
		case 4:
			medalStatistics(veterans);
			break;
		case 5:
			removeVeteran(veterans);
			break;
		case 6:
			sortVeteransByAge(veterans);
			break;
		case 7:
			cout << "Thank you for honoring our veterans!\n";
			break;
		default:
			cout << "Invalid choice. Try again.\n";
		}

	} while(choice != 7);

	return 0;
}


void displayBanner() {
	cout << "===========================================\n";
	cout << "      VETERANS HONOR AND MEDAL TRACKER     \n";
	cout << "===========================================\n";
}

void addVeteran(vector<Veteran>& veterans) {
	Veteran v;
	cout << "Enter veteran's name: ";
	getline(cin, v.name);

	cout << "Enter age: ";
	cin >> v.age;
	cin.ignore();

	int medalCount;
	cout << "How many medals does this veteran have? ";
	cin >> medalCount;
	cin.ignore();

	for (int i = 0; i < medalCount; i++) {
		string medal;
		cout << "Enter medal #" << (i + 1) << ": ";
		getline(cin, medal);


		if (find(v.medals.begin(), v.medals.end(), medal) == v.medals.end()) {
			v.medals.push_back(medal);
		} else {
			cout << "Duplicate medal ignored!\n";
			i--;
		}
	}

	veterans.push_back(v);
	cout << "Veteran added successfully.\n";
}

void displayVeterans(const vector<Veteran>& veterans) {
	if (veterans.empty()) {
		cout << "No veterans stored yet.\n";
		return;
	}

	for (const auto& v : veterans) {
		cout << "\nName: " << v.name
		     << "\nAge: " << v.age
		     << "\nMedals: ";
		for (size_t i = 0; i < v.medals.size(); i++) {
			cout << v.medals[i];
			if (i < v.medals.size() - 1) cout << ", ";
		}
		cout << "\n";
	}
}

void searchByMedal(const vector<Veteran>& veterans) {
	string medal;
	cout << "Enter medal to search for: ";
	getline(cin, medal);

	bool found = false;

	for (const auto& v : veterans) {
		if (find(v.medals.begin(), v.medals.end(), medal) != v.medals.end()) {
			cout << v.name << " (Age " << v.age << ") has this medal.\n";
			found = true;
		}
	}

	if (!found) {
		cout << "No veterans found with that medal.\n";
	}
}

void medalStatistics(const vector<Veteran>& veterans) {
	if (veterans.empty()) {
		cout << "No data available.\n";
		return;
	}

	vector<string> allMedals;
	for (const auto& v : veterans) {
		for (const string& m : v.medals) {
			allMedals.push_back(m);
		}
	}

	sort(allMedals.begin(), allMedals.end());

	cout << "\n=== Medal Statistics ===\n";
	string current = "";
	int count = 0;

	for (size_t i = 0; i < allMedals.size(); i++) {
		if (i == 0 || allMedals[i] == current) {
			current = allMedals[i];
			count++;
		} else {
			cout << current << ": " << count << "\n";
			current = allMedals[i];
			count = 1;
		}
	}

	if (!allMedals.empty())
		cout << current << ": " << count << "\n";
}

void removeVeteran(vector<Veteran>& veterans) {
	string name;
	cout << "Enter veteran's name to remove: ";
	getline(cin, name);

	auto it = remove_if(veterans.begin(), veterans.end(),
	[&](const Veteran& v) {
		return v.name == name;
	});

	if (it != veterans.end()) {
		veterans.erase(it, veterans.end());
		cout << "Veteran removed successfully.\n";
	} else {
		cout << "Veteran not found.\n";
	}
}

void sortVeteransByAge(vector<Veteran>& veterans) {
	sort(veterans.begin(), veterans.end(),
	[](const Veteran& a, const Veteran& b) {
		return a.age < b.age;
	});

	cout << "Veterans sorted by age.\n";
}


/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function prototypes
void displayBanner();
void addHeroicDeed(vector<string>& deeds, vector<string>& branches);
void displayDeeds(const vector<string>& deeds, const vector<string>& branches);
void displayStatistics(const vector<string>& deeds, const vector<string>& branches);
void createPatrioticPattern();
void searchByBranch(const vector<string>& deeds, const vector<string>& branches);

int main() {
	vector<string> heroicDeeds;
	vector<string> serviceBranches;
	int choice;

	// Display program banner
	displayBanner();

	do {
		// Main menu
		cout << "\n=== MAIN MENU ===\n";
		cout << "1. Add a veteran's heroic deed\n";
		cout << "2. Display all heroic deeds\n";
		cout << "3. Show tribute statistics\n";
		cout << "4. Create patriotic pattern\n";
		cout << "5. Search deeds by branch\n";
		cout << "6. Exit\n";
		cout << "Choose an option (1-6): ";
		cin >> choice;
		cin.ignore();  // clear newline

		switch(choice) {
		case 1:
			addHeroicDeed(heroicDeeds, serviceBranches);
			break;
		case 2:
			displayDeeds(heroicDeeds, serviceBranches);
			break;
		case 3:
			displayStatistics(heroicDeeds, serviceBranches);
			break;
		case 4:
			createPatrioticPattern();
			break;
		case 5:
			searchByBranch(heroicDeeds, serviceBranches);
			break;
		case 6:
			cout << "Thank you for honoring our veterans!\n";
			break;
		default:
			cout << "Invalid choice. Try again.\n";
		}

	} while(choice != 6);

	return 0;
}

// Display Banner
void displayBanner() {
	cout << "========================================\n";
	cout << "      VETERANS DAY TRIBUTE PROGRAM      \n";
	cout << "========================================\n";
	cout << "   Honoring Those Who Served Our Nation\n";
	cout << "========================================\n\n";
}

// Add Heroic Deed
void addHeroicDeed(vector<string>& deeds, vector<string>& branches) {
	string branch, deed;
	cout << "\nEnter the veteran's military branch: ";
	getline(cin, branch);
	cout << "Enter the veteran's heroic deed: ";
	getline(cin, deed);

	branches.push_back(branch);
	deeds.push_back(deed);

	cout << "Heroic deed added successfully!\n";
}

// Display All Heroic Deeds
void displayDeeds(const vector<string>& deeds, const vector<string>& branches) {
	if (deeds.empty()) {
		cout << "\nNo heroic deeds recorded yet.\n";
		return;
	}

	cout << "\n--- List of Heroic Deeds ---\n";
	for (size_t i = 0; i < deeds.size(); ++i) {
		cout << i + 1 << ". [" << branches[i] << "] " << deeds[i] << "\n";
	}
}

// Display Statistics
void displayStatistics(const vector<string>& deeds, const vector<string>& branches) {
	if (deeds.empty()) {
		cout << "\nNo heroic deeds recorded yet.\n";
		return;
	}

	cout << "\n--- Tribute Statistics ---\n";
	cout << "Total heroic deeds: " << deeds.size() << "\n";

	// Count deeds by branch
	vector<string> uniqueBranches;
	vector<int> counts;

	for (size_t i = 0; i < branches.size(); ++i) {
		bool found = false;
		for (size_t j = 0; j < uniqueBranches.size(); ++j) {
			if (uniqueBranches[j] == branches[i]) {
				counts[j]++;
				found = true;
				break;
			}
		}
		if (!found) {
			uniqueBranches.push_back(branches[i]);
			counts.push_back(1);
		}
	}

	cout << "Deeds by branch:\n";
	for (size_t i = 0; i < uniqueBranches.size(); ++i) {
		cout << " - " << uniqueBranches[i] << ": " << counts[i] << "\n";
	}
}

// Create Patriotic Pattern
void createPatrioticPattern() {
	int rows;
	cout << "\nEnter number of rows for patriotic pattern: ";
	cin >> rows;
	cin.ignore();

	cout << "\n--- Patriotic Pattern ---\n";
	for (int i = 1; i <= rows; ++i) {
		for (int j = 0; j < i; ++j) {
			if (j % 3 == 0)
				cout << "R ";
			else if (j % 3 == 1)
				cout << "W ";
			else
				cout << "B ";
		}
		cout << "\n";
	}
}

// Search Deeds by Branch
void searchByBranch(const vector<string>& deeds, const vector<string>& branches) {
	if (deeds.empty()) {
		cout << "\nNo heroic deeds recorded yet.\n";
		return;
	}

	string searchBranch;
	cout << "\nEnter the branch to search: ";
	getline(cin, searchBranch);

	cout << "\nHeroic deeds in " << searchBranch << ":\n";
	bool found = false;
	for (size_t i = 0; i < deeds.size(); ++i) {
		if (branches[i] == searchBranch) {
			cout << i + 1 << ". " << deeds[i] << "\n";
			found = true;
		}
	}
	if (!found) {
		cout << "No heroic deeds found for this branch.\n";
	}
}

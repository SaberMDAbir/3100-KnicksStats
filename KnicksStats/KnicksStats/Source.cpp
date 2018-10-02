//MD Abir A. Choudhury
//051018 - Assignment 11
//CIS 3100 - Knicks Stats

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//class definitions
class Stats {
public:
	//variables
	string name;
	int pointsMade;
	int numRebounds;
	int numAssist;

	//member functions
};

//function protocols
void displayMenu();
void readFile(Stats Player[], int &count);
void writeFile(Stats Player[], int count);
void checkUserInput(int &choice);
void displayMostPointUser(Stats Player[], int count);
void report(Stats Player[], int count);
void doubledouble(Stats Player[], int count);
void tripletriple(Stats Player[], int count);

int main() {
	int choice = 0;
	int const SIZE = 50;
	Stats Player[SIZE];
	int count = 0;

	//load in the file
	readFile(Player, count);
	
	do {
		displayMenu();
		cin >> choice;
		checkUserInput(choice);

		if (choice == 1) {
			displayMostPointUser(Player, count);
		}
		else if (choice == 2) {
			doubledouble(Player, count);
		}
		else if (choice == 3) {
			tripletriple(Player, count);
		}
		else if (choice == 4) {
			report(Player, count);
		}
	} while (choice != 0);
	
	writeFile(Player, count);

	system("PAUSE");
	return 0;
}

//function defintions
void displayMenu() {
	cout << "==========================\n"
		<< "Knicks Stats App Main Menu\n"
		<< "1 - Most Scorer Player\n"
		<< "2 - Double-Double\n"
		<< "3 - Triple-Double\n"
		<< "4 - Report\n"
		<< "0 - Exit\n"
		<< "Pick a choice?\n";
} // displays the menu in the do loop
void readFile(Stats Player[], int &count) {
	ifstream fileIn("knicks.txt");

	if (!fileIn) {
		cout << "Failed to find file.\n";
		exit(EXIT_FAILURE);
	}
	while (!fileIn.eof()) {
		fileIn >> Player[count].name;
		fileIn >> Player[count].pointsMade;
		fileIn >> Player[count].numRebounds;
		fileIn >> Player[count].numAssist;
		count++;
	}
	fileIn.close();
}
void writeFile(Stats Player[], int count) {
	ofstream fileOut("fileOutput.txt");

	for (int i = 0; i < count; i++) {
		fileOut << Player[i].name << " " << Player[i].pointsMade << " " << Player[i].numRebounds << " " << Player[i].numAssist;
		if (i < count - 1) {
			fileOut << endl;
		}
	}
	
	fileOut.close();
}
void checkUserInput(int &choice) {
	if (choice < 0 || choice > 4) {
		cout << "You have entered an invalid number\n"
			<< "Choose another number: ";
		cin >> choice;
		checkUserInput(choice);
	}
	else {
		choice = choice;
	}
}
void displayMostPointUser(Stats Player[], int count) {
	int max = Player[0].pointsMade;
	string tempString = Player[0].name;
	for (int i = 0; i < count; i++) {
		if (Player[i].pointsMade > max) {
			max = Player[i].pointsMade;
			tempString = Player[i].name;
		}
	}
	cout << "The player who scored the most is " << tempString << endl;
}
void report(Stats Player[], int count) {
	for (int i = 0; i < count; i++) {
		cout << Player[i].name << " Points: " << Player[i].pointsMade << " Rebounds: "
			<< Player[i].numRebounds << " Assists: " << Player[i].numAssist << endl;
	}
}
void doubledouble(Stats Player[], int count) {
	for (int i = 0; i < count; i++) {
		if ((Player[i].numAssist > 9 && Player[i].numRebounds > 9) || (Player[i].numAssist > 9 && Player[i].pointsMade > 9) || (Player[i].numRebounds > 9 && Player[i].pointsMade > 9)) {
			cout << Player[i].name << " achieved double double\n";
		}
	}
}
void tripletriple(Stats Player[], int count) {
	for (int i = 0; i < count; i++) {
		if ((Player[i].numAssist > 9 && Player[i].numRebounds > 9) && (Player[i].pointsMade > 9)) {
			cout << Player[i].name << " achieved triple triple\n";
		}
	}
}
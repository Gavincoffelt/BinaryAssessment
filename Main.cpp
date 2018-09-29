#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <filesystem>
#include "saveData.h"
#include "MonsterClass.h"
using namespace std;
void menu();
void exit();
void addMonster();
void browseMonster();
void removeMonster();
void viewByID();
int UI = 0;
	string getID;
	int loop = 0;
	int main() {
		do {
			menu();
			cin >> UI;
			if (UI == 1) {
				addMonster();
			}
			else if (UI == 2) {
				removeMonster();
			}
			else if (UI == 3) {
				viewByID();
			}
			else if (UI == 4) {
				browseMonster();
			}
			else if (UI == 5) {
				exit();
			}
			else {
				cout << "Please Pick one of the options" << endl;
			}
		} while (loop != 70);
	}
void browseMonster() {
	cout << "001: Bulbasaur. " << "013: Weedle" << endl; 
	cout << "002: Ivysaur. " << "014: Kakuna" << endl;
	cout << "003: Venusaur. " << "015: Beedrill" << endl;
	cout << "004: Charmander. " << "016: Pidgey"<< endl;
	cout << "005: Charmeleon. " << "017: Pidgeotto" << endl;
	cout << "006: Charizard. " << "018: Pidgeot" << endl;
	cout << "007: Squirtle. " << "019: Ratatta" << endl;
	cout << "008: Wartortle. " << "020: Raticate" << endl;
	cout << "009: Blastoise. " << "021: Spearow" << endl;
	cout << "010: Caterpie. " << "022: Fearow" << endl;
	cout << "011: Metapod. " << "023: Ekans" << endl;
	cout << "012: Butterfree. " << "024: Arbok" << endl;
	cout << "013: Weedle. " << "025: Pikachu" << endl;
	cout << "014: Kakuna. " << "026: Raichu" << endl;
	viewByID();
}
void addMonster() {
	Monster newMonster;
	cout << "Whats this monsters name?" << endl;
	cin >> newMonster.name;
	cout << "Whats this monsters type?" << endl;
	cin >> newMonster.type;
	cout << "How much HP does this monster have?" << endl;
	cin >> newMonster.HP;
	cout << "How would you Describe this monster?" << endl;
	cin.clear();
	cin.ignore(10000, '\n');
	getline(cin, newMonster.description); 
	cout << "Please enter a Three digit ID code for this monster" << endl;
	cin >> newMonster.IDnumber;
	
	fstream file;
	file.open("Pokemon/"+newMonster.IDnumber+".bin", ios::out | ios::binary);

	if (!file.is_open()) { 
		cout << "Failed." << endl;
		system("exit");
	}

	file << newMonster.IDnumber << endl;
	file << newMonster.name << endl;
	file << newMonster.type << endl;
	file << newMonster.HP << endl;
	file << newMonster.description << endl;

	file.flush();
	file.close();
	int main();
}
void removeMonster() {
	cout << "Please enter a Three digit number 001 - 026" << endl;
	cin >> getID;
	fstream file;
	file.open("Pokemon/" + getID + ".bin", ios_base::in | ios::binary);
	file.clear();
}
void viewByID() {
	cout << "Please enter a Three digit number 001 - 026" << endl;
	cin >> getID;
	fstream file;
	file.open("Pokemon/"+getID+".bin", ios_base::in | ios::binary);

	if (!file.is_open()) {
		cout << "Failed." << endl;
		system("exit");
	}
	string buffer;

	getline(file, buffer);
	cout <<"ID: "<< buffer << endl;
	getline(file, buffer);
	cout << "Name: " << buffer << endl;
	getline(file, buffer);
	cout << "Type: " << buffer << endl;
	getline(file, buffer);
	cout << "HP: " << buffer << endl;
	getline(file, buffer);
	cout << "Description: " << buffer << endl;
	file.flush();
	file.close();
	system("pause");
}
void exit() {
	loop = 70;
	cout << "Good Luck!" << endl;
	system("pause");
	system("exit");
}
void menu() {
	cout << "Welcome to the Monster Bestiary." << endl;
	cout << "What would you like to do?" << endl;
	cout << "1: Add a monster by ID." << endl;
	cout << "2: Remove monster by ID." << endl;
	cout << "3: View a monster by ID." << endl;
	cout << "4: Browse Monsters." << endl;
	cout << "5: Exit." << endl;
}





////int helloWorldFunc() {
//	// Hello World Function.
//	fstream file;
//	file.open("Helloworld.bin", ios::out | ios::binary);
//	
//	if (!file.is_open()) {
//		cout << "Failed." << endl;
//		return -1;
//	}
//	file << "Hello world!" << endl;
//	file.flush();
//	file.close();
//
//
//
//}
//





/*saveData firstSave;
firstSave.playerName = "Bob";
firstSave.deathCount = 15;
firstSave.deepestFloor = 5;
firstSave.hasBeenBeatenGame = false;
firstSave.timePlayed = 36000;

fstream file;
file.open("firstSave.bin", ios::out | ios::binary);
if (!file.is_open()) {
cout << "Failed" << endl;
return -1;
}
file << firstSave.playerName << endl;
file << firstSave.deathCount << endl;
file << firstSave.deepestFloor << endl;
file << firstSave.hasBeenBeatenGame << endl;
file << firstSave.timePlayed << endl;

file.flush();
file.close();

file.open("firstSave.bin", ios::in | ios::binary);
string buffer;
while (getline(file, buffer))
{
cout << buffer << endl;
}
system("pause");*/

#include <iostream>
#include <string>
using namespace std;

void process();

void write(string input){
	cout << input << endl;
}
void menu(){
	write("WELCOME!");
	write("Please select one of the following functions:");
	write("1) Kilograms to Pounds");
	write("2) Celsius to Kelvin");
	write("3) Teaspoons to Milliliters");
	write("4) Multiplication Table");
	write("5) Squares Table");
	write("x) Exit");
	process();
}

void clearScreen() {
	cout << string(100, '\n'); //because system() is evil
}

void kilogramsToPounds(){
	write("Kilograms to Pounds");
	write("-------------------");
	write("");
	cout << "Enter Kilograms: " << flush;
	int kilograms;
	cin >> kilograms;
	write("");
	cout << kilograms << " Kilograms = " << kilograms*2.2 << " Pounds" << endl;
	write("");

	write("press 6 to exit to menu or 7 to run this again ");
	int input;
	cin >> input; 
	if (input == 7){
		clearScreen();
		kilogramsToPounds();
	}
	else {
		clearScreen();
		menu(); }
}

void celsiusToKelvin(){
	write("Kilograms to Pounds");
	write("-------------------");
	write("");
	cout << "Enter Kilograms: " << flush;
	int kilograms;
	cin >> kilograms;
	write("");
	cout << kilograms << " Kilograms = " << kilograms*2.2 << " Pounds" << endl;
	write("");

	write("press 6 to exit to menu or 7 to run this again ");
	int input;
	cin >> input;
	if (input == 7){
		clearScreen();
		celsiusToKelvin();
	}
	else {
		clearScreen();
		menu();
	}
}

void process(){
	int input;
	cin >> input;

	switch (input){
	case 1:
		clearScreen();
		kilogramsToPounds();
		break;
	case 2:
		clearScreen();
		break;
	case 3:
		clearScreen();
		break;
	case 4:
		clearScreen();
		break;
	case 5:
		clearScreen();
		break;
	case 6:
		clearScreen();
		menu();
	default:
		break;
	}
}

int main(){
	menu();
}

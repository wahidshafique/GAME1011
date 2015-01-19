#include <iostream>
#include <string>
using namespace std;

void process();
void kilogramsToPounds();
void celsiusToKelvin();
void teaspoonsToMil();
void Multiplication();

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

void endMessage(void(*function)()){
	write("");
	write("press 6 to exit to menu or 7 to run this again ");
	int input;
	cin >> input;
	if (input == 7){
		clearScreen();
		(*function)();
	} else {
		clearScreen();
		menu();
	}
}

void kilogramsToPounds(){
	write("Kilograms to Pounds");
	write("-------------------");
	write("");
	cout << "Enter Kilograms: " << flush;
	int kilograms;
	cin >> kilograms;
	write("");
	cout << kilograms << " Kilograms = " << kilograms * 2.2 << " Pounds" << endl;

	endMessage(&kilogramsToPounds);
}

void celsiusToKelvin(){
	write("Celsius to Kelvin");
	write("-------------------");
	write("");
	cout << "Enter Celsius: " << flush;
	int celsius;
	cin >> celsius;
	write("");
	cout << celsius << " Celsius = " << celsius + 273.15 << " Kelvin" << endl;

	endMessage(&celsiusToKelvin);
}

void teaspoonsToMil(){
	write("Teaspoons to Milliliters");
	write("-------------------");
	write("");
	cout << "Teaspoons: " << flush;
	int teaspoons;
	cin >> teaspoons;
	write("");
	cout << teaspoons << " Teaspoons = " << teaspoons * 4.92 << " Milliliters" << endl;

	endMessage(&teaspoonsToMil);
}

void Multiplication(){
	write("Multiplication Table");
	write("-------------------");
	write("");
	cout << "Enter in a value to make the table : " << flush;
	int number;
	cin >> number;
	write("");
	if (number > 0){
		for (int i = 1; i < number; i++){
			for (int j = 1; j < number; j++){
				cout << i*number << endl;
				cout << j*number << endl;
			}
		}

	}
	else Multiplication();
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
		celsiusToKelvin();
		break;
	case 3:
		clearScreen();
		teaspoonsToMil();
		break;
	case 4:
		clearScreen();
		Multiplication();
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

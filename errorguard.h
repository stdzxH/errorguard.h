#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void gstoi(string &input,bool negative = false){
	
	do {
		char inputChar[input.length()];
		strcpy(inputChar,input.c_str());
		
		bool isValue = true;
		for (int i = 0; i < input.length(); i++){
			if ((isdigit(inputChar[i]) == false and inputChar[i] != '-') or (inputChar[i] == '-' and i != 0) or (inputChar[i] == '-' and i == 0 and negative == false))
				isValue = false;
			if (input.empty())
				isValue = false;
		}
		
		if (isValue == false){
			cin.sync();
			cout<<"Invalid input, input must be number: ";
			getline(cin,input);
		}
		else
			break;
	} while (true);
	
	stoi(input);
}

void gstod(string &input, bool negative = false){
	int decimalCount = 0;
	
	do {
		char inputChar[input.length()];
		strcpy(inputChar,input.c_str());
		
		bool isValue = true;
		
		for (int i = 0; i < input.length(); i++){
			if ((isdigit(inputChar[i]) == false and inputChar[i] != '-' and inputChar[i] != '.') or (inputChar[i] == '-' and i != 0) or (inputChar[i] == '-' and i == 0 and negative == false))
				isValue = false;
			if (inputChar[i] == '.')
				decimalCount += 1;
			if (input.empty())
				isValue = false;
			if (inputChar[i] == '.' and decimalCount > 1)
				isValue = false;
		}
		
		if (isValue == false){
			cin.sync();
			cout<<"Invalid input, input must be number: ";
			getline(cin,input);
			decimalCount = 0;
		}
		else
			break;
	} while (true);
	
	stod(input);
}

void getos(string &input){
	
	while (input.empty()){
		cin.sync();
		cout<<"Invalid input, input is empty"<<endl;
		getline(cin,input);
	}
	
}

void gslower(string &input){
	char inputChar[input.length()];
	strcpy(inputChar, input.c_str());
	string newInput, current;
	
	for (int i = 0; i < input.length(); i++){
		current = (char) tolower(inputChar[i]);
		newInput.append(current);
	}
	
	input = newInput;
}

void gsupper(string &input){
	char inputChar[input.length()];
	strcpy(inputChar, input.c_str());
	string newInput, current;
	
	for (int i = 0; i < input.length(); i++){
		current = (char) toupper(inputChar[i]);
		newInput.append(current);
	}
	
	input = newInput;
}

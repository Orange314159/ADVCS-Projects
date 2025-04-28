// C++ program to display "Hello World"

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

struct NATION{
	string name;
	string region;
	double value;
};

void simpleSortTotal(NATION* s[], int c);

// Main() function: where the execution of program begins
int main(){
	string n;
	string r = "";
	string v;
	string empty;
	ifstream file ("WPP2015_MORT_F07_1_LIFE_EXPECTANCY_0_BOTH_SEXES.csv");
	NATION nations[209];
	NATION* ns[209];
	int count;

	//init struct col 3, col 16
	if(file.is_open()){
		for (int i = 0; i < 29; i++){
			std::getline(file, empty);
		} // skip the first few lines
		int i = 0;
		for (int k = 0; k < 229; k ++){
			
			// READ EACH LINE
			std::getline(file, empty, ',');
			std::getline(file, empty, ',');
			std::getline(file, n, ','); // name
			if (n == "\"China"){ // WHY ARE THERE COMMAS IN THE NAMES OF COUNTRIES!!!
				std::getline(file, n, ',');
				n = "\"China," + n;
			}
			std::getline(file, empty, ',');
			std::getline(file, empty, ',');
			std::getline(file, empty, ',');
			std::getline(file, empty, ',');
			std::getline(file, empty, ',');
			std::getline(file, empty, ',');
			std::getline(file, empty, ',');
			std::getline(file, empty, ',');
			std::getline(file, empty, ',');
			std::getline(file, empty, ',');
			std::getline(file, empty, ',');
			std::getline(file, empty, ',');
			std::getline(file, v, ','); // value
			std::getline(file, empty, ',');
			std::getline(file, empty, '\n');
			// FINISH READ

			n = n.substr(1,n.length()-2); // remove quotes
			

			if (n != "AFRICA" && n != "ASIA" && n != "NORTHERN AMERICA" && n != "SOUTHERN AMERICA" && n != "EUROPE" && n != "LATIN AMERICA AND THE CARIBBEAN" &&  n != "OCEANIA"){
				if (n != "Western Europe" && n != "Northern Europe" && n != "Eastern Europe" && n != "Southern Europe" && n != "Western Asia" && n != "Northern Asia" && n != "Eastern Asia" && n != "Southern Asia" && n != "Western Africa" && n != "Northern Africa" && n != "Eastern Africa" && n != "Southern Africa" && n != "Other non-specified areas" && n != "South America" && n != "Australia/New Zealand"){
					nations[i].name = n;
					nations[i].value = std::stof(v);;
					nations[i].region = r;
				} else {
					i--;
				}
			} else {
				r = n;
				i--;
			}
			i++;
		}
		file.close();
		count = i-1;
	}

	for (int i=0; i < count; i++){
		ns[i] = &nations[i];
	}
	
	simpleSortTotal(ns, 209);


	int usPlace = 0;
	for (int i=0; i < count; i++)
		std::cout << "Record: " << ns[i]->name <<", " << ns[i]->region << ", " << ns[i]->value << endl;

	for (int i=0; i < count; i++){
		usPlace++;
		if (ns[i]->name == "United States of America"){
			break;
		}
	}
	std::cout << "The US places: " << usPlace << " out of all nations." << endl << "\n-----------------------------------------------------------------------------\n\n";

	usPlace = 0;
	for (int i=0; i < count; i++)
		if (ns[i]->region == "NORTHERN AMERICA" || ns[i]->name == "Japan" || ns[i]->name == "Japan" || ns[i]->name == "New Zealand" || ns[i]->name == "Australia" || ns[i]->region == "EUROPE"){
			std::cout << "Record: " << ns[i]->name <<", " << ns[i]->region << ", " << ns[i]->value << endl;
		}

	for (int i=0; i < count; i++){
		if (ns[i]->region == "NORTHERN AMERICA" || ns[i]->name == "Japan" || ns[i]->name == "Japan" || ns[i]->name == "New Zealand" || ns[i]->name == "Australia" || ns[i]->region == "EUROPE"){
			usPlace++;		
		}
		if (ns[i]->name == "United States of America"){
			break;
		}
	}
	std::cout << "The US places: " << usPlace << " out of some nations." << endl;
		
	return 0;
}

void simpleSortTotal(NATION* ns[] , int c) {
	for (int i=0; i < c; i++){
		for (int j=i; j+1 < c; j++){
			if (ns[i]->value < ns[j]->value) {
				NATION* temp;
				temp  = ns[i];
				ns[i] = ns[j];
				ns[j] = temp;
			}
		}
		
	}
} 
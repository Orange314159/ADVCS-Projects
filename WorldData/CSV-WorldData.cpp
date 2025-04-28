// C++ program to display "Hello World"

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;


int sort(map<string, float>& M)
{
 
    // Declare a multimap
    multimap<float, string> MM;
 
    for (auto& it : M) {
        MM.insert({ it.second, it.first });
    }
 
    // Print the multimap
	int counter = 0;
	int placeUSA = 0;
    for (auto& it : MM) {
        cout << it.second << ' ' << it.first << endl;
		counter++;
		if (it.second == "United States of America"){
			placeUSA = counter;
		}
    }
	return (counter - placeUSA)+1;
}

// Main() function: where the execution of program begins
int main()
{
	// cout << "test";
	string line;
	string line2;
	ifstream file ("WPP2015_MORT_F07_1_LIFE_EXPECTANCY_0_BOTH_SEXES.csv");

	map<string, float> nation; // col 3, col 16
	if(file.is_open()){
		for (int i = 0; i < 30; i++){
			getline(file, line);
		}

		for(int i = 0; i <3; i++){
			getline(file, line, ',');
		}
		for(int i = 0; i < 13; i++){
			getline(file, line2, ',');
		}


		line = line.substr(1,line.length()-2);
		nation[line] = std::stof(line2);
		// std::cout << line << " " << line2 << endl;


		

		for (int j = 0; j<227; j++){
			for(int i = 0; i <4; i++){
				getline(file, line, ',');
				if (line == "\"China"){ // WHY ARE THERE COMMAS IN THE NAMES OF COUNTRIES!!!
					getline(file, line, ',');
					line = "\"China," + line;
				}
			}
			for(int i = 0; i < 13; i++){
				getline(file, line2, ',');
			}

			line = line.substr(1,line.length()-2);

			if (line != "AFRICA" && line != "ASIA" && line != "NORTHERN AMERICA" && line != "SOUTHERN AMERICA" && line != "EUROPE" && line != "LATIN AMERICA AND THE CARIBBEAN" && line != "Western Europe" && line != "Northern Europe" && line != "Eastern Europe" && line != "Southern Europe" && line != "Western Asia" && line != "Northern Asia" && line != "Eastern Asia" && line != "Southern Asia" && line != "OCEANIA" && line != "Western Africa" && line != "Northern Africa" && line != "Eastern Africa" && line != "Southern Africa" && line != "Other non-specified areas" && line != "South America")
				nation[line] = std::stof(line2);
			// regex_replace(line, com, "");
			// std::cout << line << " " << line2 << endl;


		}

		int place = sort(nation);

		cout << "The US places: " << place << " out of all nations." << endl << "\n-----------------------------------------------------------------------------\n\n";
		
		file.seekg(0);
	}

	// ifstream file ("WPP2015_MORT_F07_1_LIFE_EXPECTANCY_0_BOTH_SEXES.csv");
	

	map<string, float> nation2; // col 3, col 16
	if(file.is_open()){
		for (int i = 0; i < 150; i++){
			getline(file, line);
		}
		for(int i = 0; i <3; i++){
			getline(file, line, ',');
		}
		for(int i = 0; i < 13; i++){
			getline(file, line2, ',');
		}

		line = line.substr(1,line.length()-2);
		nation2[line] = std::stof(line2);
	
		for (int j = 0; j<44; j++){
			for(int i = 0; i <4; i++){
				getline(file, line, ',');
				if (line == "\"China"){ // WHY ARE THERE COMMAS IN THE NAMES OF COUNTRIES!!!
					getline(file, line, ',');
					line = "\"China," + line;
				}
			}
			for(int i = 0; i < 13; i++){
				getline(file, line2, ',');
			}
			line = line.substr(1,line.length()-2);

			if (line != "AFRICA" && line != "ASIA" && line != "NORTHERN AMERICA" && line != "SOUTHERN AMERICA" && line != "EUROPE" && line != "LATIN AMERICA AND THE CARIBBEAN" && line != "Western Europe" && line != "Northern Europe" && line != "Eastern Europe" && line != "Southern Europe" && line != "Western Asia" && line != "Northern Asia" && line != "Eastern Asia" && line != "Southern Asia" && line != "OCEANIA" && line != "Western Africa" && line != "Northern Africa" && line != "Eastern Africa" && line != "Southern Africa" && line != "Other non-specified areas" && line != "South America")
				nation2[line] = std::stof(line2);
		}

		file.seekg(0);

		for (int i = 0; i < 237; i++){
			getline(file, line);
		}
		for(int i = 0; i <3; i++){
			getline(file, line, ',');
		}
		for(int i = 0; i < 13; i++){
			getline(file, line2, ',');
		}

		line = line.substr(1,line.length()-2);
			if (line != "AFRICA" && line != "ASIA" && line != "NORTHERN AMERICA" && line != "SOUTHERN AMERICA" && line != "EUROPE" && line != "LATIN AMERICA AND THE CARIBBEAN" && line != "Western Europe" && line != "Northern Europe" && line != "Eastern Europe" && line != "Southern Europe" && line != "Western Asia" && line != "Northern Asia" && line != "Eastern Asia" && line != "Southern Asia" && line != "OCEANIA" && line != "Western Africa" && line != "Northern Africa" && line != "Eastern Africa" && line != "Southern Africa" && line != "Other non-specified areas" && line != "South America")
			nation2[line] = std::stof(line2);
	
		for (int j = 0; j<3; j++){
			for(int i = 0; i <4; i++){
				getline(file, line, ',');
				if (line == "\"China"){ // WHY ARE THERE COMMAS IN THE NAMES OF COUNTRIES!!!
					getline(file, line, ',');
					line = "\"China," + line;
				}
			}
			for(int i = 0; i < 13; i++){
				getline(file, line2, ',');
			}
			line = line.substr(1,line.length()-2);

			if (line != "AFRICA" && line != "ASIA" && line != "NORTHERN AMERICA" && line != "SOUTHERN AMERICA" && line != "EUROPE" && line != "LATIN AMERICA AND THE CARIBBEAN" && line != "Western Europe" && line != "Northern Europe" && line != "Eastern Europe" && line != "Southern Europe" && line != "Western Asia" && line != "Northern Asia" && line != "Eastern Asia" && line != "Southern Asia" && line != "OCEANIA" && line != "Western Africa" && line != "Northern Africa" && line != "Eastern Africa" && line != "Southern Africa" && line != "Other non-specified areas" && line != "South America")
				nation2[line] = std::stof(line2);
		}


		file.seekg(0); // aus
		for (int i = 0; i < 241; i++){
			getline(file, line);
		}
		for(int i = 0; i <3; i++){
			getline(file, line, ',');
		}
		for(int i = 0; i < 13; i++){
			getline(file, line2, ',');
		}
		line = line.substr(1,line.length()-2);
		nation2[line] = std::stof(line2);
		file.seekg(0); // jap
		for (int i = 0; i < 98; i++){
			getline(file, line);
		}
		for(int i = 0; i <3; i++){
			getline(file, line, ',');
		}
		for(int i = 0; i < 13; i++){
			getline(file, line2, ',');
		}
		line = line.substr(1,line.length()-2);
		nation2[line] = std::stof(line2);


		file.close();

		int place = sort(nation2);

		cout << "The US places: " << place << " out of some nations." ;
		
		
	}
	return 0;
}
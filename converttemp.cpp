// converttemp.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;


vector<string> cities;
vector<double> CelsiusTemps;
double fahrenheitToCelsius(double);
void readFile(), outputFile(vector<string>& t_cities, vector<double>& t_Celsius);

int main()
{
	readFile();
	outputFile(cities, CelsiusTemps);



return 0;
}
//Function for converting to Celsius
double fahrenheitToCelsius(double ftemp) {
	return (ftemp - 32.0) * 5.0 / 9.0;

}
//Function for reading the file
void readFile() {
	ifstream inFS;
	double fTemp;
	string cityName;
	//attempt to open the file
	inFS.open("FahrenheitTemperature.txt");

	//if the file isnt open, print and error message
	if (!inFS.is_open()) {
		cout << "Could not open file";
	}
	//if it does open, seperate the values from the file into two vectors
	while (!inFS.fail()) {
		inFS >> cityName;
		inFS >> fTemp;

		CelsiusTemps.push_back(fahrenheitToCelsius(fTemp));
		cities.push_back(cityName);
		
	}

	//Close the file once it is done
	inFS.close();
}
//Generate the output file by passing in the two vectors
void outputFile(vector<string>& t_cities, vector<double>& t_CelsiusTemps) {
	ofstream outFS;
	
	//Generate the output file
	outFS.open("CelsiusTemperature.txt");

	//If it doesnt open, print error message
	if (!outFS.is_open()) {
		cout << "Could not open file CelsiusTemperature.txt" << endl;

	}
	else {
		//if it doesnt fail, load file with our cities and temps

		for (int c = 0; c < t_CelsiusTemps.size(); c++) {
			
			outFS << t_cities[c] << " " << t_CelsiusTemps[c] << setprecision(4)<<endl; // 
		}
		outFS.close();
	}
}


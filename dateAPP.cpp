#include<iostream>
#include<ctime>
#include <fstream>
#include <cstdlib>
#include<vector>

#include "Date.h"

using namespace std;

int main() {

	ifstream fin;

	// Open the input file
	fin.open("date_in.txt");
	if (fin.fail()) {
		cout << "Input file opening failed.\n";
		exit(1);
	}

	ofstream fout;
	// Open the output file
	fout.open("date_out.txt");
	if (fout.fail()) {
		cout << "Output file opening failed.\n";
		exit(1);
	}

	char delimiter;
	int day = 0;
	int month = 0;
	int year = 0;

	// Read multiple dates from the file
	while (fin >> day) {
		fin.get(delimiter);  // Gets and ignores delimiter
		fin >> month;
		fin.get(delimiter);  // Gets and ignores delimiter
		fin >> year;
		fin.get(delimiter);  // Gets and ignores delimiter
		// reuses the previous delimiter if no new one is present 

		// Create a Date object d for each date in the file
		Date d(day, month, year);
		cout << d << endl;   // Output the date to console
		fout << d << endl;   // Output the date to file
	}

	// Close the files
	fin.close();
	fout.close();

	return 0;
}


/*
#include<iostream>
#include<ctime>
#include <fstream>
#include <cstdlib>
#include<vector>

#include "Date.h"

using namespace std;

int main() {

	ifstream fin;

	//Read a date from the file
	fin.open("date_in.txt");
	if (fin.fail()) {
		cout << "Input file opening failed.\n";
		exit(1);
	}

	char deliminator;
	int day = 0;
	int month = 0;
	int year = 0;

	fin >> day;
	fin.get(deliminator);
	fin >> month;
	fin.get(deliminator);
	fin >> year;
	fin.get(deliminator);

	Date d(day, month, year);
	cout << d << endl;

	//output the date to a file
	ofstream fout;

	fout.open("date_out.txt");
	if (fout.fail()) {
		cout << "Output file opening failed.\n";
		exit(1);
	}

	fout << d << endl;
	return 0;
}

*/

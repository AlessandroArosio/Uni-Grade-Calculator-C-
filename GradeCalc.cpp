// GradeCalc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{
	// variables needed
	vector<int>* courseWork = new vector<int>; // heap vector storing all the scores from the coursework.
	vector<string>* course = new vector<string>;
	int total = 0;
	int weight;
	int input;
	string name;
	char answer;

	int i = 0; // vector's counter
	bool moreModules = true;
	char more;
	bool moreGrades = true;

	do
	{
		cout << "Input the module's name: " << endl;
		getline(cin, name);
		(*course).push_back(name); //pushing module's name

		do {
			cout << "Input the grade obtained:" << endl;
			cin >> input;
			cout << "Input its weight: " << endl;
			cin >> weight;
			total += input*weight / 100;
			cout << "There are more grades for this module? Y/N" << endl;
			cin >> more;
			if (more != 'y') {
				moreGrades = false;
				(*courseWork).push_back(total); //pushing grade
			}
		} while (moreGrades);

		total = 0;
		moreGrades = true;
		cout << "Do you want to calculate more grades? Y/N" << endl;
		cin >> answer;
		if (answer != 'y') {
			moreModules = false;
		}
	} while (moreModules);

	for (i = 0; i < courseWork->size(); ++i){
	cout << "Module " << (*course)[i] << ", you got an overall mark of: " << (*courseWork)[i] << " out of 100" << endl;
	}
	delete course;
	delete courseWork;
	return 0;
}


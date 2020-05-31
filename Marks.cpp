#define _CRT_SECURE_NO_WARNINGS
// Should hold mark related functions.
#include <iostream>
#include "Marks.h"

using namespace std;

void clear(void);

void markstat() {
	// VARS:
	char assessmentName[40];	// Name of assessment.

	int* marks = nullptr;		// Create pointer for marks.
	int numMarks = 0;			// Number of marks.
	
	char aft;					// Detect trail chars for numMarks.
	int keepTrying = 1;			// Looper.

	// PRINT TITLE:
	cout << "Mark Stats Program" << endl;
	// cout << endl;

	// ACCEPT INPUTS:
	cout << "Please enter the assessment name: ";
	cin >> assessmentName;
	clear();

	// GET NUMBER OF MARKS:
	cout << "Please enter the number of marks: ";
	do {
		// Number of marks input:
		numMarks = 0;
		scanf_s("%d%c", &numMarks, &aft);
		// Check if valid number:
		if (numMarks == 0) {
			cout << "Invalid Number, try again: ";
			clear();
		}
		// Check if there are trailing chars:
		else if (aft != '\n') {
			cout << "Invalid trailing characters, try again: ";
			clear();
		}
		// Check if numMarks is between 5 and 50:
		else if (numMarks < 5 || numMarks > 50) {
			cout << "Invalid value(5 <= value <= 50), try again: ";
		}
		// If all checks pass, end loop:
		else {
			cout << "DONE" << endl;
			keepTrying = 0;
		}
	} while (keepTrying == 1);

	// Allocate memory for marks:
	marks = new int[numMarks];
	
	// GET numMarks x marks:
	cout << "Please enter " << numMarks << " marks (0<=Mark<=100): " << endl;

	for (int i = 0; i < numMarks; i++) {
		cout << i + 1 << "> ";
		cin >> marks[i];
	}
	

	// PRINT OUTPUT:
	cout << "Thank you..." << endl;
	cout << "Assessment Name: " << assessmentName << endl;
	cout << "----------------" << endl;

	for (int i = 0; i < numMarks; i++) {
		if (i == numMarks - 1) {
			cout << marks[i] << endl;
		}
		else {
			cout << marks[i] << ", ";
		}
	}

	cout << endl;

	cout << "Average: ";
	cout << "Number of passing marks: ";

	/*
	output:
	Mark Stats Program.

	Please enter the assessment name: Midterm Test
	Please enter the number of marks: 3
	Invalid value (5<=value<=50), try again: three
	Invalid Number, try again: 3marks
	Invalid trailing characters, try again: 9
	Please enter 9 marks (0<=Mark<=100):
	1> 200
	Invalid value (0<=value<=100), try again: 34
	2> 89
	3> 55
	4> 23
	5> 50
	6> 79
	7> 100
	8> 60
	9> 72
	Thank you...
	Assessment Name: Midterm Test
	----------------
	100, 89, 79, 72, 60, 55, 50, 34, 23
	Average: 62.4
	Number of Passing Marks: 7

	*/
};

// clear empties the input buffer 
//
void clear(void)
{
	while (getchar() != '\n')
		;  // empty statement intentional 
}
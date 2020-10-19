/*
-------------------------------
Aiden Trimble
C++ Fall 2020
Due: October 19th
Lab 4 Temperature Output
Imputting data from files to create a weather chart
-------------------------------
*/


// Libraries used to gain access to needed syntax.
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//Creats a function name that is used and defined later to calculate the stars for the positive numbers
void stars(float tempdata);
//Creates a function name that is used and defined later to calculate the stars for the negative numbers
void negstars(float tempdata);
//Creates a function name for later used to input spaces
void spaces();

int main()
{
	
	//enables the file to be used as an input file
	ifstream inFile;
	//Gives a name to the file location
	string inputFile = "C:/Users/adtri/Desktop/C++ Saves/Lab4/Lab4/inputFile.dat";
	//Opens the input file
	inFile.open(inputFile);
	
	//Gives the name "gap" a specific amount of spaces for the display
	string gap = "        ";
	//Outputs the top of the weather display and sections of where the temperatures are
	cout << gap << " " << "-30" << gap << "0" << gap << "30" << gap << "60" << gap << "90" << gap << "120" << "\n";
	//Outputs the lines under the temperature display
	cout << "\t" << "--------------------------------------------------------" << endl;

	//Checks the file location
	if (!inFile)
	{
		cout << "Could not Find File!\n";
		return 1;

	}

	//Gives the data in the file a name
	float tempdata;
	//Reads what is in the file
	inFile >> tempdata;
	//Checks to see if the file is valid
	if (!inFile)
	{             
		cout << "Failed to Read File" << endl;
		return 1;
	}
	
//This while loops the procedure of checking to see if the data is between -30 and 120, takes the data from the input file, calculates the stars for the input, and repeats for the next data input
while(inFile)
	{
	
		//This statement will happen if the input data is not between -30 and 120
		if ((tempdata < -30) || (tempdata > 120))
		{
			cout << "Input is out of bounds" << endl;
		
		}
		
		//This statement will happen if the input data is larger than or equal to 0
		else if (tempdata >= 0)
		{
			cout << tempdata << "\t";
			spaces();
			cout << "|";
			stars(tempdata);
			cout << endl;
		}
		//This statement will happen if the input data is less than 0
		else if (tempdata < 0)
		{
			cout << tempdata << "\t";
			negstars(tempdata);
			cout << "|\n";
		}

		//Reads the file again at the end of the loop
	inFile >> tempdata;
	}
return 0;
}

//Defines the "spaces" function so that the line in the chart is alines with 0
void spaces()
{
	int data2 = 1;
	while (data2 <= 12)
	{
		data2++;
		cout << " ";
	}
}
//Defines the function for the positive data for the displayed stars
void stars(float tempdata)
{
	int num1 = ((tempdata/float(3)) + .5);
	int data = 1;

	while (data <= num1)
	{
		data++;
		cout << '*';
	}
}
//Defines the function for the negative data for the displayed stars to the left of 0
void negstars(float tempdata)
{
	int num2 = ((abs((tempdata / 3))) + .5);
	int data3 = 1;
	int data4 = 1;
	int negSpaces = (12 - num2);

	while (data3 <= negSpaces)
	{
		data3++;
		cout << " ";
	}
	while (data4 <= num2)
	{
		data4++;
		cout << '*';
	}
}

/*
	Author:		Megan Molumby
	Course:		COP 2220
	Project:	1
	Title:		Unit conversion Tool
	

*/



#include <stdio.h>
#include <stdlib.h>

#define HEADER "%15s%15s%15s%15s\n" //Displays output Header
#define ROWS "%15s%15d%15s%15.3f\n"	//Displays output Rows

#define F2M 0.3048
#define P2K 0.4536

int main()
{	
	//Declare Variables
	int fDegrees, feet, pounds;
	double cDegrees, meters, kilograms;

	printf("Megan Molumby\n");
	printf("Project 1 - Unit Conversion Tool\n");

	//Get user input
		printf("\nEnter a Fahrenheit temperature (integer): ");
		scanf("%d", &fDegrees);
		printf("Enter a distance in feet (integer): ");
		scanf("%d", &feet);
		printf("Enter a weight in pounds (integer): ");
		scanf("%d", &pounds);

	//Perform Conversions
		cDegrees = (fDegrees - 32) * 5 / 9;
		meters = feet*F2M;
		kilograms = pounds*P2K;

	//Display Results
		printf("\n");
		printf(HEADER, "Original", "Value", "Converted To", "Value");
		printf(HEADER, "---------", "-----", "------------", "-----");
		printf(ROWS, "Fahtrenheit", fDegrees, "Celsius", cDegrees);
		printf(ROWS, "Feet", feet, "Meters", meters);
		printf(ROWS, "Pounds", pounds, "Kilograms", kilograms);
		printf("\n");

		system("pause");
		return (0);
	





}
/*
Author:		Megan Molumby
Course:		COP 2220
Project:	   2
Title:		Unit conversion Tool~modularized, checking ranges.


*/

#include <stdio.h>
#include <stdlib.h>

#define HEADER "%13s%13s%13s%13s%13s%13s\n" //Displays output Header
#define ROWS "%13s%13d%13s%13.3f%13s%13.3f\n"	//Displays output Rows

#define F2M 0.3048
#define P2K 0.4536
#define TRUE 1
#define FALSE 0

void convertDistance(int feet, double *pmeters, double *pinches);
void convertTemperature(int fahrenheit, double *pcelsius, double *pkelvin);
void convertWeight(int pounds, double *pkilograms, double *pstones);
void displayReport(int fahrenheit, int feet, int pounds, double celsius, double meters, double kilograms, double kelvin, double inches, double stones);
int getInput(int *pfahrenheit, int *pfeet, int *ppounds);
void performConversions(int fahrenheit, int feet, int pounds, double *pcelsius, double *pmeters, double *pkilograms, double *pkelvin, double *pinches, double *pstones);
int withinRange(int input, int minRange, int maxRange);


int main()
{
	//Declare Variables
	int fahrenheit, feet, pounds;
	double celsius, meters, kilograms, kelvin, inches, stones;

	printf("Megan Molumby\n");
	printf("Project 1 - Unit Conversion Tool\n");

	if (getInput(&fahrenheit, &feet, &pounds) == TRUE)
	{
		performConversions(fahrenheit, feet, pounds, &celsius, &meters, &kilograms, &kelvin, &inches, &stones);
		displayReport(fahrenheit, feet, pounds, celsius, meters, kilograms, kelvin, inches, stones);
	}


	system("pause");
	return (0);


}

int getInput(int *pfahrenheit, int *pfeet, int *ppounds)
{
	printf("\nEnter a Fahrenheit temperature (integer) [0-212]: ");
		if (scanf("%d", pfahrenheit) == 1)
		{
			if (!withinRange(*pfahrenheit, 0, 212) == TRUE)
			{
				return FALSE;
			}
		}
		else
		{
			printf("%s", "The entered temperature value is invalid.\n");
			return FALSE;
		}

	printf("Enter a distance in feet (integer) [0-100]: ");
		if (scanf("%d", pfeet) == 1)
		{
			if (!withinRange(*pfeet, 0, 100) == TRUE)
			{
				return FALSE;
			}
		}
		else
		{
			printf("%s", "The entered distance value is invalid.\n");
			return FALSE;
		}

	printf("Enter a weight in pounds (integer) [0-100]: ");
		if (scanf("%d", ppounds) == 1)
		{
			if (!withinRange(*ppounds, 0, 100) == TRUE)
			{
				return FALSE;
			}
		}
		else
		{
			printf("%s", "The entered weight value is invalid.\n");
			return FALSE;
		}

}

int withinRange(int input, int minRange, int maxRange)
{
	//if input is less than min range or input is greater than max range = false
	if (input<minRange || input>maxRange)
	{
		printf("%s%d%s%d%s", "\nThe entered value is out of range [", minRange, "-", maxRange, "].\n");
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

void performConversions(int fahrenheit, int feet, int pounds, double *pcelsius, double *pmeters, double *pkilograms, double *pkelvin, double *pinches, double *pstones)
{

	convertDistance(feet, pmeters, pinches);
	convertTemperature(fahrenheit, pcelsius, pkelvin);
	convertWeight(pounds, pkilograms, pstones);

}

void convertDistance(int feet, double *pmeters, double *pinches)
{
	*pmeters = feet*F2M;
	*pinches = feet * 12;

}

void convertTemperature(int fahrenheit, double *pcelsius, double *pkelvin)
{
	*pcelsius = (fahrenheit - 32) * 5 / 9;
	*pkelvin = (fahrenheit + 459.67) * 5 / 9;
}

void convertWeight(int pounds, double *pkilograms, double *pstones)
{

	*pkilograms = pounds*P2K;
	*pstones = pounds*0.0714285714;
}

void displayReport(int fahrenheit, int feet, int pounds, double celsius, double meters, double kilograms, double kelvin, double inches, double stones)
{
	printf("\n");
	printf(HEADER, "Original", "Value", "Converted To", "Value", "Converted To", "Value");
	printf(HEADER, "---------","-----","------------","-----","------------","-----");
	printf(ROWS, "Fahrenheit", fahrenheit, "Celsius", celsius, "Kelvin", kelvin);
	printf(ROWS, "Feet", feet, "Meters", meters, "Inches", inches);
	printf(ROWS, "Pounds", pounds, "Kilograms", kilograms, "Stones", stones);
	printf("\n");
	
}




//dont use pointers in report print out
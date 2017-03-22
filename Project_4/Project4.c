#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include "..\..\stdbool.h"
#include <math.h>
#define ARRAY_SIZE 100
/*
** Authors: Megan Molumby, Matt Rutherford, Abubakr Hassan
** Course: COP 2220
** Project #: 4
** Title: Random Number Statistics
** Due Date: 11/21/2014
**
** Reads the Input file.
** Validates the Input and the it is within range.
** Generates random numbers and creates an array for those numbers
** Calculates the Average, Maximum, Median and Minimum statistics 
** of the random numbers.
** Displays the Statistics as well as the random numbers. Or will 
** display an error message if the filname is not attached, if the values are out of range, 
**and if the value is invalid.
**
*/

//Function Prototypes
void generateNumbers(int b[], int pSeed, int pCount);
void initializeArray(int b[]);
bool readFile(char *filename, int *pSeed, int *pCount);
void calculateStatistics(int b[], int *pMin, int *pMax, double *pMedian, double *pAverage);
void copyArray(int b [], int copy[]);
double getAverage(int b[]);
int getMax(int b[]);
double getMedian(int b[]);
int getMin(int b[]);
void initializeArray(int b[]);
void printReport (int b[], int pCount, int min, int max, double median, double average);
void sortArray(int b[]);
void swap(int b[], int pos1, int pos2);
bool validateInput(int pSeed, int pCount);
bool withinRange(int value, int minRange, int maxRange);


int main(int argc, char* argv[])
{
	int pSeed, pCount,min,max;
	double median, average;
	int b[ARRAY_SIZE]; //b is an array of 100 
	printf("%s", "Megan Molumby\n");
	printf("%s","Project 4-Random Number Statistics\n");
	readFile(argv[1], &pSeed, &pCount);
	validateInput(pSeed,pCount);
	generateNumbers(b, pSeed, pCount);
	calculateStatistics(b, &min, &max, &median, &average);
	printReport(b, pCount, min, max, median, average);

	system("pause");
	return 0;
}
bool validateInput(int seed, int count)
{
	bool isvalid=false;

	if(seed>0)
	{
		if(withinRange(seed,0,10000)==true)
		{
			if(count>0)
			{
				if(withinRange(count, 100, 1000)==true)
				{
					isvalid=true;
				}
				else
				{
					printf("%s", "/nThe supplied value is out of range [100-1000]/n");
				}
			}

		}
		else
		{
			printf("%s", "/nThe supplied value is out range[0-10000]/n");
		}

	}
	return isvalid;
}

bool withinRange(int value, int minRange, int maxRange)
{
	bool isvalid=true;

	if (value< minRange || value > maxRange)
	{
		printf("%s%d%s%d%s", "\nThe entered value is out of range [", minRange, " - ", maxRange, "].\n");
		isvalid=false;
	}


	return isvalid;
}

bool readFile(char *filename, int *pSeed, int *pCount)
{
	bool isvalid=false;
	FILE *Input;
	Input=fopen(filename, "r");

	if (Input!=NULL)
	{
		if(fscanf(Input,"%d %d", pSeed, pCount)==2)
		{
			isvalid=true;
		}

		fclose(Input);
	}
	else
	{
	  printf("%s", "The required filename parameter is missing");
	}


	return isvalid;

}
void generateNumbers(int b[], int pSeed, int pCount)
{
	int x;
	initializeArray(b);
	srand(pSeed);
	for (x=0; x<pCount; x++)
	{
		b[rand()%100] ++;
	}
}

void initializeArray(int b[])////should be good
{
	int x = 0;
	for (x = 0; x < 100; x++)
	{
		 b[x] = 0;
	}
	

}

void calculateStatistics(int b[], int*pMin, int*pMax, double *pMedian, double *pAverage)
{
	
	*pAverage=getAverage(b);
	*pMax=getMax(b);
	*pMin=getMin(b);
	*pMedian=getMedian(b);

}
double getAverage(int b[])
{
	double sum=0.0;
	int x=0;
	for(x=0; x<ARRAY_SIZE; x++)
	{
		sum+=b[x];
		
	}
	return sum/ARRAY_SIZE;
}

int getMax(int b[])
{
		int x;
		int max=0;
		for (x=0; x<ARRAY_SIZE; x++)
		{
			if(b[x] > max)
			{
				max=b[x];
			}
		}
		return max;
}

int getMin(int b[])
{
	int x;
	int min=0;
	for(x=0; x<ARRAY_SIZE; x++)
	{
		if(b[x] < min)
		{
			min=b[x];
		}
	}
	return min;
}

double getMedian(int b[])
{
	double median;
	int copy[ARRAY_SIZE]={0}, middle=ARRAY_SIZE/2;

	copyArray(b, copy);
	sortArray(copy);
	median=copy[middle];
	if(ARRAY_SIZE%2==0)
	{
		median=((copy[middle]+copy[middle-1])/2);///LOOK AT AGAIN!

	}
	
	return median;

}
void copyArray(int b[], int copy[])
{
	int x=0;
	for(x=0; x<ARRAY_SIZE; x++)
	{
		copy[x]=b[x];
	}
}
void sortArray(int copy[])///bubble sort inefficient 
{
		/*bool swapped=true;
		int x,y;

		for (y=0; y<99 && swapped; y++)//traversal loop
		{
			swapped=false;
			for(x=0;x<(99-y)-1; x++)//comparison loop
			{
				if(copy[x]>copy[x+1])
				{
					swap(copy, x, x+1);
				}
			}
		}

		*/
		int x, y, min;
		for(x=0;x<ARRAY_SIZE-1;x++)
		{
			min=x;
			for(y=x+1;y<ARRAY_SIZE;y++)
			{
				if(copy[y]<copy[min])
				{
					min=y;
				}
			}
			if(min!=x)
			{
				swap(copy, x, min);

			}

		}


}

void swap (int copy[], int pos1, int pos2)///swaps place values of array to put in order
{
	int temp= copy[pos2];//creates a temporary value in order to keep from losing the value, while its is being swapped.
	copy[pos2]=copy[pos1];
	copy[pos1]=temp;

}

void printReport (int b[], int pCount, int min, int max, double median, double average)
{
	int x=0,y=0, col=0;
	printf("%s%d", "Minimum Count:", min);
	printf("%s%d", "\nMaximum Count:", max);
	printf("%s%.2f", "\nMedian Count:", median);
	printf("%s%.2f", "\nAverage Count:", average);
	printf("%s", "\nArray Analysis (Position: Count [Percentage]\n");

	for (x=0; x<ARRAY_SIZE; x++)
	{
		if(x%8==0)
		{	
			printf("\n");
		}
	
	printf("%2d : %2d [%2.1f%%] ", x, b[x], (double) b[x]/pCount*100);
	}
}
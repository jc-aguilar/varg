/*
 * Jose Aguilar
 * NID: jo019867 
 * COP 3502
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include"Varg.h"

char mostFrequentChar(int n, ...)
{
	int i, mostFrequent = 0, p = 0;
	char array[26]= ""; // array to hold char arguments 
	int count[26] = {0}; // integer array to keep count of char frequency 
	va_list argp; // variable list argp
	
	va_start(argp, n); // initialize arpg, n is the first variable to be passed

	for (i = 0; i < n; i++)
	{
		p = va_arg(argp, int); // store variables from argp in p
		if(p >='a' && p <= 'z') // checks if incoming variables are lowercase a-z
		{
			array[i] = p; // array to store the chars temporarily in p 
			count[array[i] - 'a']++; // keeps count of the frequency of each char
		}
	}
	for ( i = 0; i < n; i++) // for loop loops n times 
	{ // if there is no tie it will return the index in the array with the highest count
		if (array[i] > mostFrequent && mostFrequent < count[array[i]])
		{
			mostFrequent = array[mostFrequent]; 
		}
		else if (array[i] > mostFrequent || mostFrequent > count[array[i]])
		{// if there is a tie, return the first index to reach the most frequent value
			mostFrequent = array[i];
		}
		else if (count[array[0]] < count[array[i]])
		{
			count[array[0]] = count[array[i]]; // sorts the array by count 
		}
	}
	va_end(argp); // empty the argument list 
	
	return mostFrequent;
}

char fancyMostFrequentChar(char c, ...)
{
	char fancy = c; // variable to hold first argument in list 
	int j, k; // control variables 
	char arr[26] = "";
	int frequency[26] = {0};
	
	va_list argp;
	// returns NULL if c is NULL
	if (c == '\0')
	{
		return '\0';
	}
	va_start(argp, c); // start of argument list argp with argument c
	
	while (j = va_arg(argp, int) != '\0') // look for arguments if the list isn't NULL
	{
		if (j >='a' && j <= 'z') // checks if incoming variables are lowercase a-z
		{
			arr[k] = j; // array to store the chars temporarily in p 
			frequency[arr[k] - 'a']++; // keeps count of the frequency of each char
		}
		if (arr[j] < frequency[arr[k]]) 
		{
		     fancy = arr[j]; // returns the most frequent char
		}
	}	
	va_end(argp); // empty the argument list 
	
	return fancy;
}	
// function that returns how diffcult this program was between 1-5
double difficultyRating(void)
{
	double difficulty;
	difficulty = 4.98;
	return difficulty;
}	
// function that retuns the ammount of hours spent 
// working on this program 
double hoursSpent(void)
{
	double hours;
	hours = 8.5;
	return hours;
}
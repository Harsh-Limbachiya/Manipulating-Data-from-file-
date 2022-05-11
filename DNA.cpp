/* ------------------------------------------------------
Workshop 2 part 2
Name     : Harsh Vishnu Limbachiya
Email    : hvlimbachiya@myseneca.ca
studentId: 157295197
Filename : DNA.cpp
date     : 31/1/2022
-----------------------------------------------------------*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments, also for the read function Harmish helped me*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "DNA.h"
#include "cStrTools.h"
using namespace std;
namespace sdds
{
	int size = 0;
	Dna* DnaRecMatched = nullptr;
	FILE* fptr;

	//open file for reading
	bool beginSearch(const char* filename)
	{
		fptr = fopen("lowBaseDnaSmall.csv", "r");
		int flag;
		if (fptr != NULL)
		{
			flag = true;
		}
		else
		{
			flag = false;
		}
		return flag;
	}

	//dynamically creates array for matched strands
	bool read(const char* subDNA)
	{
		int id;
		char strand[1001] = {};
		strand[1001 - 1] = '\0';
		while (fscanf(fptr, "%d,%[^\n]\n", &id, strand) != EOF)
		{
			if (strstr(strand, subDNA))
				size++;
		}
		rewind(fptr);
		if (size == 0)
			return false;

		DnaRecMatched = new Dna[size];
		int i = 0;
		while (fscanf(fptr, "%d,%[^\n]\n", &id, strand) != EOF)
		{
			if (strstr(strand, subDNA))
			{
				DnaRecMatched[i].dnaID = id;
				DnaRecMatched[i].dnaStrand = new char[strLen(strand) + 1];
				strCpy(DnaRecMatched[i].dnaStrand, strand);
				i++;
			}
		}
		rewind(fptr);
		return true;
		
	}

	//Sorts the dynamic array of DNA matches found in the file based on the ids in ascending order.
	void sort()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if (DnaRecMatched[j].dnaID > DnaRecMatched[j + 1].dnaID)
				{
					Dna temp;
					temp = DnaRecMatched[j];
					DnaRecMatched[j] = DnaRecMatched[j + 1];
					DnaRecMatched[j + 1] = temp;
				}
			}
		}
	}


//Displays the dynamic DNA records in specific format
	void displayMatches()
	{
		cout << size << " matches found:" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << ") " << DnaRecMatched[i].dnaID << ":" << endl;
			cout << DnaRecMatched[i].dnaStrand << endl;
			cout << "======================================================================" << endl;
		}
	}

	//Deallocates all the dynamic memory within the DNA array elementsand the DNA array itself
	void deallocate()
	{
		for (int i = 0; i < size; i++)
			delete[] DnaRecMatched[i].dnaStrand;
		delete[] DnaRecMatched;
		size = 0;
	}

	//Finalizes the program by releasing the resources allocated by the program
	void endSearch()
	{
		fclose(fptr);
		cout << "DNA Search Program Closed." << endl;
	}

}
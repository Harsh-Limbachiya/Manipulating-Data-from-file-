/* ------------------------------------------------------
Workshop 2 part 2
Name     : Harsh Vishnu Limbachiya
Email    : hvlimbachiya@myseneca.ca
studentId: 157295197
Filename : DNA.h
date     : 31/1/2022
-----------------------------------------------------------*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments*/

#ifndef _DNA_H
#define _DNA_H
#pragma once

namespace sdds
{
	struct Dna
	{
		int dnaID = 0;
		char* dnaStrand = nullptr;
	};
	//open file for reading 
	bool beginSearch(const char* filename);
	//dynamically creates array for matched strands
	bool read(const char* subDNA);
	//Sorts the dynamic array of DNA matches found in the file based on the ids in ascending order.
	void sort();
	//Displays the dynamic DNA records in specific format
	void displayMatches();
	//Deallocates all the dynamic memory within the DNA array elementsand the DNA array itself
	void deallocate();
	//Finalizes the program by releasing the resources allocated by the program
	void endSearch();
}

#endif
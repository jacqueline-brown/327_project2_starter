/*
 * functionstocomplete.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: keith
 */

//============================================================================
//	TODO add necessary includes here
//============================================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <array>
#include <time.h>
#include "constants.h"
#include "utilities.h"
#include "array_functions.h"
//============================================================================
//	stuff you will need
//============================================================================
//TODO define a structure to track words and number of times they occur
using namespace std;
using namespace constants;
struct tracker {
	string word;
	int numberOfOccurances;
};
//TODO add a global array of entry structs (global to this file)
tracker arrayOfStructs[constants::MAX_WORDS];
//TODO add variable to keep track of next available slot in array
int nextSlot;
//TODO define all functions in header file
void clearArray() {

}

int getArraySize() {
	int count = 0;
	/*for(int i = 0; unsigned(i) < sizeof(arrayOfStructs); i++){
		if(!end(arrayOfStructs))
				count += 1;
	}*/
	while(!(end(arrayOfStructs)))
		count += 1;
	return count;
}

std::string getArrayWordAt(int i){
	return "";
}

int getArrayWord_NumbOccur_At(int i) {
	return 0;
}

bool processFile(std::fstream &myfstream) {
	string line;
	if (!(myfstream.is_open()))
		return false;
	while (!(myfstream.eof())){
		getline(myfstream, line);
		processLine(line);
	}
	return true;
}

void processLine(std::string &myString){
	strip_unwanted_chars(myString);
	stringstream ss(myString);
	string token;
	while(getline(ss,token,constants::CHAR_TO_SEARCH_FOR)) {
		processToken(token);
	}
}

void processToken(std::string &token) {

}

bool openFile(std::fstream& myfile, const std::string& myFileName, std::ios_base::openmode mode) {
	myfile.open(myFileName.c_str());
	if (myfile.is_open()) {
		return true;
	}
	return false;
}

void closeFile(std::fstream& myfile){
	myfile.close();
}

int writeArraytoFile(const std::string &outputfilename){
	return 0;
}

void sortArray(constants::sortOrder so){

}
//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!

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
tracker arrayOfStructs[MAX_WORDS];
//TODO add variable to keep track of next available slot in array
int nextSlot=0;
//TODO define all functions in header file
void clearArray() {
	nextSlot = 0;
}

int getArraySize() {
	return nextSlot;
}

std::string getArrayWordAt(int i){
	return arrayOfStructs[i].word;
}

int getArrayWord_NumbOccur_At(int i) {
	return arrayOfStructs[i].numberOfOccurances;
}

bool processFile(std::fstream &myfstream) {
	string line;
	if (!(myfstream.is_open())){
		return false; }
	while (!(myfstream.eof())){
		getline(myfstream, line);
		processLine(line);
	}
	return true;
}

void processLine(std::string &myString){
	stringstream ss(myString);
	string token;
	while(getline(ss,token,CHAR_TO_SEARCH_FOR)) {
		processToken(token);
	}
}

void processToken(std::string &token) {
	strip_unwanted_chars(token);
	if(!(strip_unwanted_chars(token))){
			return;
	}
	for(int i = 0; i < getArraySize(); i++){
		string word1 = arrayOfStructs[i].word;
		toUpper(word1);
		string tempToken = token;
		toUpper(tempToken);

		if(word1 == tempToken) {
			arrayOfStructs[i].numberOfOccurances += 1;
			return;
		}
	}

	if(token.length() != 0){
		arrayOfStructs[nextSlot] = tracker();
		arrayOfStructs[nextSlot].numberOfOccurances = 1;
		arrayOfStructs[nextSlot].word = token;
		nextSlot++;
	}


}

bool openFile(std::fstream& myfile, const std::string& myFileName, std::ios_base::openmode mode) {
	myfile.open(myFileName.c_str());
	return myfile.is_open();
}

void closeFile(std::fstream& myfile){
	if(myfile.is_open()==true){
		myfile.close();
}
}

int writeArraytoFile(const std::string &outputfilename){
	ofstream wordcounter;
	wordcounter.open(outputfilename.c_str());
	if(!(wordcounter.is_open()))
		return FAIL_FILE_DID_NOT_OPEN;
	if(getArraySize() == 0)
		return FAIL_NO_ARRAY_DATA;

	for(int i = 0; i < getArraySize(); i++){
		wordcounter << arrayOfStructs[i].word << " " << arrayOfStructs[i].numberOfOccurances << endl;
	}
	wordcounter.close();

	return SUCCESS;
}

void sortArray(constants::sortOrder so){
	switch (so) {
	case constants::NONE:
		break;
	case constants::ASCENDING:
	{
		tracker temp;
		for(int i = 0; i < getArraySize()-1; i++) {
			for(int j = i+1; j < getArraySize(); j++){
				string word1 = arrayOfStructs[i].word;
				string word2 = arrayOfStructs[j].word;
				toUpper(word1);
				toUpper(word2);
				if(word1 > word2) {
					temp = arrayOfStructs[i];
					arrayOfStructs[i] = arrayOfStructs[j];
					arrayOfStructs[j] = temp;
				}
			}
		}
		break;
	}
	case constants::DESCENDING:
	{
		tracker temp ;
			for(int i = 0; i < getArraySize()-1; i++) {
				for(int j = i + 1; j < getArraySize(); j++){
					string word1 = arrayOfStructs[i].word;
					string word2 = arrayOfStructs[j].word;
					toUpper(word1);
					toUpper(word2);
					if(word1 < word2) {
						temp = arrayOfStructs[i];
						arrayOfStructs[i] = arrayOfStructs[j];
						arrayOfStructs[j] = temp;
					}
				}

			}
		break;
	}
	case constants::NUMBER_OCCURRENCES:
	{
		for(int i = 0; i < getArraySize(); i++){
			for(int j = 0; j < getArraySize(); j++) {
				int num1 = arrayOfStructs[i].numberOfOccurances;
				int num2 = arrayOfStructs[j].numberOfOccurances;
				if(num1 > num2) {
					tracker temp = arrayOfStructs[i];
					arrayOfStructs[i] = arrayOfStructs[j];
					arrayOfStructs[j] = temp;
				}
			}
		}
		break;
	}
}
}
//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!

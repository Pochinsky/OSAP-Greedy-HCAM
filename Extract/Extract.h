#include <string>
#include <vector>
#include "../Data/Data.h"
/**
 * split a string in a substrings separated by a splitter
 * 
 * @param   str       string to split
 * @param   splitter  char that delimiter each substrin
 * @returns a vector with substrings from split
 */
vector<string> splitString(string str, char splitter);
/**
 * get data of an instance of OSAP from .txt file
 * 
 * @param   filename path to file to read
 * @returns a Data class with data extracted from the instance
 */
Data extractData(string filename);
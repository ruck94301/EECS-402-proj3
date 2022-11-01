#include <iostream>
#include <fstream>

#include "PatternClass.h"

using namespace std;

void PatternClass::loadPattern(string filename)
{
  ifstream inFile;

  cout << "DEBUG loading " << filename << endl;
  inFile.open(filename.c_str());

  inFile.close();
}

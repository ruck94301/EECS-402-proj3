#include <iostream>
#include <fstream>

#include "PPMClass.h"

using namespace std;

// class PPMClass
// {
// }

void PPMClass::loadImg(string filename)
{
  ifstream inFile;

  cout << "DEBUG loading " << filename << endl;
  inFile.open(filename.c_str());

  inFile.close();
}

void PPMClass::saveImg(string filename)
{
  ofstream outFile;

  cout << "DEBUG saving " << filename << endl;
  outFile.open(filename.c_str());

  outFile.close();
}

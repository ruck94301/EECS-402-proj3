#include <iostream>
#include <limits>
#include <string>

// [1] https://stackoverflow.com/questions/72315735/
//     how-to-make-cin-only-take-integer-inputs

using namespace std;

int main_menu();

int main()
{
  string ppm_filename;
  int choice;

  // initial prompt
  cout << "Enter string for PPM image file name to load: " << endl;
  cin >> ppm_filename;
  cout << "DEBUG ppm_filename: " << ppm_filename << endl;

  while (true)
  {
    choice = main_menu();

    switch (choice)
    {
      case 5:
        cout << "Thank you for using this program" << endl;
        return 0;
      default:
        cout << "bad choice" << endl;
    }
  }

  return 0;
}

int main_menu()
{
  int choice;

  cout << "1. Annotate image with rectangle" << endl;
  cout << "2. Annotate image with pattern from file" << endl;
  cout << "3. Insert another image" << endl;
  cout << "4. Write out current image" << endl;
  cout << "5. Exit the program" << endl;
  cout << "Enter int for main menu choice: " << endl;

  cin >> choice;

  // see [1]
  if (cin.fail()) {
    cout << "DEBUG cin.fail()" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  cout << "DEBUG choice: " << choice << endl;

  return choice;
}

/*
Enter string for PPM image file name to load: deer.ppm
1. Annotate image with rectangle
2. Annotate image with pattern from file
3. Insert another image
4. Write out current image
5. Exit the program
Enter int for main menu choice: 1
1. Specify upper left and lower right corners of rectangle
2. Specify upper left corner and dimensions of rectangle
3. Specify extent from center of rectangle
Enter int for rectangle specification method: 3
Enter rectangle center row and column: 132 327
Enter int for half number of rows: 12
Enter int for half number of columns: 12
1. Red
2. Green
3. Blue
4. Black
5. White
Enter int for rectangle color: 1
1. No
2. Yes
Enter int for rectangle fill option: 1
1. Annotate image with rectangle
2. Annotate image with pattern from file
3. Insert another image
4. Write out current image
5. Exit the program
Enter int for main menu choice: 4
Enter string for PPM file name to output: new1.ppm
1. Annotate image with rectangle
2. Annotate image with pattern from file
3. Insert another image
4. Write out current image
5. Exit the program
Enter int for main menu choice: 1
1. Specify upper left and lower right corners of rectangle
2. Specify upper left corner and dimensions of rectangle
3. Specify extent from center of rectangle
Enter int for rectangle specification method: 1
Enter upper left corner row and column: 300 312
Enter lower right corner row and column: 364 337
1. Red
2. Green
3. Blue
4. Black
5. White
Enter int for rectangle color: 3
1. No
2. Yes
Enter int for rectangle fill option: 1
1. Annotate image with rectangle
2. Annotate image with pattern from file
3. Insert another image
4. Write out current image
5. Exit the program
Enter int for main menu choice: 4
Enter string for PPM file name to output: new2.ppm
1. Annotate image with rectangle
2. Annotate image with pattern from file
3. Insert another image
4. Write out current image
5. Exit the program
Enter int for main menu choice: 3
Enter string for file name of PPM image to insert: topHat.ppm
Enter upper left corner to insert image row and column: 35 280
1. Red
2. Green
3. Blue
4. Black
5. White
Enter int for transparecy color: 5
1. Annotate image with rectangle
2. Annotate image with pattern from file
3. Insert another image
4. Write out current image
5. Exit the program
Enter int for main menu choice: 4
Enter string for PPM file name to output: new3.ppm
1. Annotate image with rectangle
2. Annotate image with pattern from file
3. Insert another image
4. Write out current image
5. Exit the program
Enter int for main menu choice: 2
Enter string for file name containing pattern: ohdeerPattern.txt
Enter upper left corner of pattern row and column: 140 375
1. Red
2. Green
3. Blue
4. Black
5. White
Enter int for pattern color: 5
1. Annotate image with rectangle
2. Annotate image with pattern from file
3. Insert another image
4. Write out current image
5. Exit the program
Enter int for main menu choice: 4
Enter string for PPM file name to output: new4.ppm
1. Annotate image with rectangle
2. Annotate image with pattern from file
3. Insert another image
4. Write out current image
5. Exit the program
Enter int for main menu choice: 1
1. Specify upper left and lower right corners of rectangle
2. Specify upper left corner and dimensions of rectangle
3. Specify extent from center of rectangle
Enter int for rectangle specification method: 2
Enter upper left corner row and column: 375 200
Enter int for number of rows: 50
Enter int for number of columns: 200
1. Red
2. Green
3. Blue
4. Black
5. White
Enter int for rectangle color: 5
1. No
2. Yes
Enter int for rectangle fill option: 2
1. Annotate image with rectangle
2. Annotate image with pattern from file
3. Insert another image
4. Write out current image
5. Exit the program
Enter int for main menu choice: 4
Enter string for PPM file name to output: new5.ppm
1. Annotate image with rectangle
2. Annotate image with pattern from file
3. Insert another image
4. Write out current image
5. Exit the program
Enter int for main menu choice: 5
Thank you for using this program
*/

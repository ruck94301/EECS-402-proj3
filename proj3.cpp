#include <iostream>
#include <limits>
#include <string>

#include "PPMClass.h"

// [1] https://stackoverflow.com/questions/72315735/
//     how-to-make-cin-only-take-integer-inputs

using namespace std;

int main();
int main_menu();
int menu_rectangle_specification_method();
int menu_rectangle_color();
int menu_rectangle_fill_option();
int menu_transparency_color();
int menu_pattern_color();

int main()
{
  string ppm_filename;
  string output_filename;
  int choice;
  int rectangle_specification_method;
  int rectangle_color;
  int rectangle_fill_option;
  int transparency_color;
  int pattern_color;
  PPMClass image;

  // initial prompt
  cout << "Enter string for PPM image file name to load: ";
  cin >> ppm_filename;
  cout << "DEBUG ppm_filename: " << ppm_filename << endl;

  // load from ppm_filename, or error
  image.load(ppm_filename);

  while (true)
  {
    choice = main_menu();

    switch (choice)
    {
      case 1:  // 1. Annotate image with rectangle
        while (true)
        {
          rectangle_specification_method = menu_rectangle_specification_method();

          switch(rectangle_specification_method)
          {
            case 1:
// Enter upper left corner row and column: 300 312
// Enter lower right corner row and column: 364 337
              break;
            case 2:
// Enter upper left corner row and column: 375 200
// Enter int for number of rows: 50
// Enter int for number of columns: 200
              break;
            case 3:
// Enter rectangle center row and column: 132 327
// Enter int for half number of rows: 12
// Enter int for half number of columns: 12
              break;
            case 0:
              break;
            default:
              cout << "ERROR impossible" << endl;
              return 1;
          }
        }

        while (true)
        {
          rectangle_color = menu_rectangle_color();

          switch(rectangle_color)
          {
            case 1:
              break;
            case 2:
              break;
            case 3:
              break;
            case 4:
              break;
            case 5:
              break;
            case 0:
              break;
            default:
              cout << "ERROR impossible" << endl;
              return 1;
          }
        }

        while (true)
        {
          rectangle_fill_option = menu_rectangle_fill_option();

          switch(rectangle_fill_option)
          {
            case 1:
              break;
            case 2:
              break;
            case 0:
              break;
            default:
              cout << "ERROR impossible" << endl;
              return 1;
          }
        }

        // do something with image, rectangle, color, & fill option
        cout << "DEBUG Do something with image, rectangle, color & fill option" << endl;

        break;
		
      case 2:  // 2. Annotate image with pattern from file
// Enter string for file name containing pattern: ohdeerPattern.txt
// Enter upper left corner of pattern row and column: 140 375

        while (true)
        {
          pattern_color = menu_pattern_color();

          switch(pattern_color)
          {
            case 1:
              break;
            case 2:
              break;
            case 3:
              break;
            case 4:
              break;
            case 5:
              break;
            case 0:
              break;
            default:
              cout << "ERROR impossible" << endl;
              return 1;
          }
        }

        // Do something with image, overlay_pattern, location, & transparency_color
        cout << "DEBUG Do something with image, overlay_pattern, location, & transparency_color " << endl;
        break;
		
      case 3:  // 3. Insert another image
// Enter string for file name of PPM image to insert: topHat.ppm
// Enter upper left corner to insert image row and column: 35 280

        while (true)
        {
          transparency_color = menu_transparency_color();

          switch(transparency_color)
          {
            case 1:
              break;
            case 2:
              break;
            case 3:
              break;
            case 4:
              break;
            case 5:
              break;
            case 0:
              break;
            default:
              cout << "ERROR impossible" << endl;
              return 1;
          }
        }

        // Do something with image, overlay_image, location, & transparency_color
        cout << "DEBUG Do something with image, overlay_image, location, & transparency_color " << endl;

        break;
      case 4:  // 4. Write out current image
        cout << "Enter string for PPM file name to output: " << endl;
        cin >> output_filename;

        cout << "DEBUG output_filename: " << output_filename << endl;

        // save to output_filename, or error
        image.save(output_filename);

        break;
      case 5:  // 5. Exit the program
        cout << "Thank you for using this program" << endl;
        return 0;
      case 0:
        break;
      default:
        cout << "ERROR impossible" << endl;
        return 1;
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
  cout << "Enter int for main menu choice: ";

  cin >> choice;

  if (cin.fail()) {
    cout << "ERROR expected an integer" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return 0;
  }

  if (!(choice >= 1 && choice <= 5))
  {
    cout << "ERROR expected an integer in [1,5]" << endl;
    return 0;
  }

  // choice is an integer in [1,5]
  cout << "DEBUG choice: " << choice << endl;
  return choice;
}

int menu_rectangle_specification_method()
{
  int choice;

  cout << "1. Specify upper left and lower right corners of rectangle" << endl;
  cout << "2. Specify upper left corner and dimensions of rectangle" << endl;
  cout << "3. Specify extent from center of rectangle" << endl;
  cout << "Enter int for rectangle specification method: ";

  cin >> choice;

  if (cin.fail()) {
    cout << "ERROR expected an integer" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return 0;
  }

  if (!(choice >= 1 && choice <= 3))
  {
    cout << "ERROR expected an integer in [1,3]" << endl;
    return 0;
  }

  // choice is an integer in [1,3]
  cout << "DEBUG rectangle specification method: " << choice << endl;
  return choice;
}

int menu_rectangle_color()
{
  int choice;

  cout << "1. Red" << endl;
  cout << "2. Green" << endl;
  cout << "3. Blue" << endl;
  cout << "4. Black" << endl;
  cout << "5. White" << endl;
  cout << "Enter int for rectangle color: ";

  cin >> choice;

  if (cin.fail()) {
    cout << "ERROR expected an integer" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return 0;
  }

  if (!(choice >= 1 && choice <= 5))
  {
    cout << "ERROR expected an integer in [1,5]" << endl;
    return 0;
  }

  // choice is an integer in [1,5]
  cout << "DEBUG rectangle color: " << choice << endl;
  return choice;
}

int menu_rectangle_fill_option()
{
  int choice;

  cout << "1. No" << endl;
  cout << "2. Yes" << endl;
  cout << "Enter int for rectangle fill option: ";

  cin >> choice;

  if (cin.fail()) {
    cout << "ERROR expected an integer" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return 0;
  }

  if (!(choice >= 1 && choice <= 2))
  {
    cout << "ERROR expected an integer in [1,2]" << endl;
    return 0;
  }

  // choice is an integer in [1,2]
  cout << "DEBUG rectangle fill option: " << choice << endl;
  return choice;
}

int menu_transparency_color()
{
  int choice;

  cout << "1. Red" << endl;
  cout << "2. Green" << endl;
  cout << "3. Blue" << endl;
  cout << "4. Black" << endl;
  cout << "5. White" << endl;
  cout << "Enter int for transparecy color: ";
  // cout << "Enter int for transparency color: ";

  cin >> choice;

  if (cin.fail()) {
    cout << "ERROR expected an integer" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return 0;
  }

  if (!(choice >= 1 && choice <= 5))
  {
    cout << "ERROR expected an integer in [1,5]" << endl;
    return 0;
  }

  // choice is an integer in [1,5]
  cout << "DEBUG transparency color: " << choice << endl;
  return choice;
}

int menu_pattern_color()
{
  int choice;

  cout << "1. Red" << endl;
  cout << "2. Green" << endl;
  cout << "3. Blue" << endl;
  cout << "4. Black" << endl;
  cout << "5. White" << endl;
  cout << "Enter int for pattern color: ";

  cin >> choice;

  if (cin.fail()) {
    cout << "ERROR expected an integer" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return 0;
  }

  if (!(choice >= 1 && choice <= 5))
  {
    cout << "ERROR expected an integer in [1,5]" << endl;
    return 0;
  }

  // choice is an integer in [1,5]
  cout << "DEBUG pattern color: " << choice << endl;
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

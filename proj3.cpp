#include <iostream>
#include <limits>
#include <string>

#include "ColorClass.h"
#include "PPMClass.h"

// [1] https://stackoverflow.com/questions/72315735/
//     how-to-make-cin-only-take-integer-inputs

using namespace std;

int main();
int main_menu();
int menu_rectangle_specification_method();
ColorClass menu_color(string prompt);
int menu_rectangle_fill_option();

int main()
{
  string ppm_filename;
  string output_filename;
  string prompt;
  bool done;
  int choice;
  int rectangle_specification_method;
  ColorClass rectangle_color;
  int rectangle_fill_option;
  ColorClass transparency_color;
  ColorClass pattern_color;
  PPMClass image, image2;
  int row, column;

  // initial prompt
  cout << "Enter string for PPM image file name to load: ";
  cin >> ppm_filename;
  cout << "DEBUG ppm_filename: " << ppm_filename << endl;

  // load from ppm_filename, or error
  image.loadImg(ppm_filename);

  done = false;
  while (!done)
  {
    choice = main_menu();

    switch (choice)
    {
      case 1:  // 1. Annotate image with rectangle
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
          default:
            cout << "ERROR impossible" << endl;
            return 1;
        }

        prompt = "Enter int for rectangle color: ";
        rectangle_color = menu_color(prompt);

        rectangle_fill_option = menu_rectangle_fill_option();

        switch(rectangle_fill_option)
        {
          case 1:
            break;
          case 2:
            break;
          default:
            cout << "ERROR impossible" << endl;
            return 1;
        }

        // do something with image, rectangle, color, & fill option
        cout << "DEBUG Do something with image, rectangle, color & fill option" << endl;

        break;
		
      case 2:  // 2. Annotate image with pattern from file
// Enter string for file name containing pattern: ohdeerPattern.txt
// Enter upper left corner of pattern row and column: 140 375

        prompt = "Enter int for pattern color: ";
        pattern_color = menu_color(prompt);

        // Do something with image, overlay_pattern, location, & transparency_color
        cout << "DEBUG Do something with image, overlay_pattern, location, & transparency_color " << endl;
        break;
		
      case 3:  // 3. Insert another image
        cout << "Enter string for file name of PPM image to insert: ";
        cin >> ppm_filename;
        image2.loadImg(ppm_filename);

        cout << "Enter upper left corner to insert image row and column: ";
        cin >> row >> column;

        cout << "DEBUG row: " << row << endl;
        cout << "DEBUG column: " << column << endl;

        prompt = "Enter int for transparecy color: ";  // sic
        transparency_color = menu_color(prompt);

        cout << "DEBUG Insert another image..." << endl;
        // ...

        break;

      case 4:  // 4. Write out current image
        cout << "Enter string for PPM file name to output: " << endl;
        cin >> output_filename;

        // cout << "DEBUG output_filename: " << output_filename << endl;

        image.saveImg(output_filename);

        break;

      case 5:  // 5. Exit the program
        cout << "Thank you for using this program" << endl;
        done = true;
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
  bool done;
  int choice;

  do
  {
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
    }
  
    if (choice >= 1 && choice <= 5)
    {
      done = true;
    }
    else
    {
      cout << "ERROR expected an integer in [1,5]" << endl;
      done = false;
    }
  } while (!done);

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

  if (cin.fail()) 
  {
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

ColorClass menu_color(string prompt)
{
  ColorClass result;
  bool done;
  int choice;

  do 
  {
    cout << "1. Red" << endl;
    cout << "2. Green" << endl;
    cout << "3. Blue" << endl;
    cout << "4. Black" << endl;
    cout << "5. White" << endl;
    cout << prompt;

    cin >> choice;

    if (cin.fail()) {
      cout << "ERROR expected an integer" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  
    if (choice >= 1 && choice <= 5)
    {
      done = true;
    }
    else
    {
      cout << "ERROR expected an integer in [1,5]" << endl;
      done = false;
    }
  } while (!done);

  switch (choice)
  {
    case 1:  // 1. Red
      result.setColor(255, 0, 0);
      break;
    case 2:  // 2. Green
      result.setColor(0, 255, 0);
      break;
    case 3:  // 3. Blue
      result.setColor(0, 0, 255);
      break;
    case 4:  // 4. Black
      result.setColor(0, 0, 0);
      break;
    case 5:  // 5. White
      result.setColor(255, 255, 255);
      break;
    default:
      cout << "ERROR impossible" << endl;
  }

  return result;
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

#include<iostream>
#include<iomanip>
#include<cmath>
#include <algorithm>
#include <sstream>

using std::cout;
using std::cin;
using std::string;

const float rydberg_energy = 13.606;

float calculate_transition_energy(int atomic_number, int initial_level, int final_level)
{
  // Calculates the transition energy using the rydberg formula
  return (rydberg_energy * pow(atomic_number, 2) *
   ((1/pow(initial_level, 2)) - (1/pow(final_level, 2))));
}

int get_integer_input(const string& message) {
  // Validates input to ensure positive integer type
  string line;
  int input;

  while (true) 
  {
    cout << "\n" << message;
    getline(cin, line);

    std::stringstream ss(line);
    if (ss >> input && !(ss >> line) && input > 0) 
    {
        return input;
    } else 
    {
        cout << "\033[1;31mError: Input must be a positive integer.\033[0m\n";
    }
  }
}

char get_char_input(string message, char &extra)
{
  // Retrieves a character input and converts to lowercase
  char input;

  cout << "\n" << message;
  cin.get(input);
  cin.get(extra);
  input = tolower(input);

  return input;
}

int main()
{
  int atomic_number;
  int initial_number;
  int final_number;
  char units;
  char extra_input;
  char keep_running = 'y';

  while(keep_running == 'y')
  {
    atomic_number = get_integer_input("Enter atomic number: ");
    initial_number = get_integer_input("Enter initial quantum number: ");

    while (true)
    {
      final_number = get_integer_input("Enter final quantum number: ");
      if (final_number <= initial_number)
        cout << "\033[1;31mError: Final level (n2) must be greater than initial level (n1).\033[0m\n";
      else 
        break;
    }

    string message = "Should the answer be given in Joules (type 'j') or Electron Volts (type 'e'): ";
    
    units = get_char_input(message, extra_input);
    // Character input validation
    while ((units != 'j' && units != 'e') || extra_input != '\n')
    {
      // Ignore extra letters - only need look at first two
      while (extra_input != '\n' && cin.get(extra_input));

      cout << "\033[1;31mError: Input must be either 'j' or 'e' \033[0m\n";
      units = get_char_input(message, extra_input);
    }

    float photon_energy = calculate_transition_energy(atomic_number, initial_number, final_number);

    // Check which units to output answer in, convert if necessary
    if(units == 'e')
    {
      cout << "Transition Energy: " << photon_energy << " eV" << std::endl;
    }
    else
    {
      photon_energy *= 1.6 * pow(10, -19);
      cout << "Emmited Photon Energy: " << photon_energy << " J" << std::endl;
    }

    message = "Would you like to calculate again for different values? (Y/N): ";
    
    keep_running = get_char_input(message, extra_input);
    // Character input validation
    while ((keep_running != 'y' && keep_running != 'n') || extra_input != '\n')
    {
      while (extra_input != '\n' && cin.get(extra_input));

      cout << "\033[1;31mError: Input must be either 'y' or 'n' \033[0m\n";
      keep_running = get_char_input(message, extra_input);
    }
  }

  return 0;
}
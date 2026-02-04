#include<iostream>
#include<iomanip>
#include<cmath>
using std::cout;
using std::cin;

const float rydberg_energy = 13.606;


float calculate_transition_energy(int atomic_number, int initial_level, int final_level)
{
  // Calculates the transition energy using the rydberg formula
  return (rydberg_energy * pow(atomic_number, 2) *
   ((1/pow(initial_level, 2)) - (1/pow(final_level, 2))));
}


int get_integer_input(std::string message)
{
  // Validates input to ensure positive integer type
  int input;

  cout << message;
  while (!(cin >> input) || input < 1) 
  {
    cout << "Error: Invalid input, please enter an integer greater than 0: ";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "\n" << message;
  }

  return input;
}

int get_char_input(std::string message)
{
  // Validates input to ensure character type
  char input;

  cout << message;
  while (!(cin >> input)) 
  {
    cout << "Error: Invalid input, please enter a single character ";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  return input;
}


int main()
{
  int atomic_number;
  int initial_number;
  int final_number = -1;
  char units;
  char running = 'y';

  while(running == 'y')
  {
    atomic_number = get_integer_input("Enter atomic number: ");
    initial_number = get_integer_input("Enter initial quantum number: ");
    final_number = get_integer_input("Enter final quantum number: ");

    units = get_char_input("Should the answer be given in Joules (type 'j') or Electron Volts (type 'e'): ");
    tolower(units); 

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

    running = get_char_input("Would you like to calculate again for different values? (Y/N): ");
    tolower(running);
  }

  return 0;
}
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

float CalculateTransitionEnergy(float R, int Z, int n1, int n2)
{
    // Calculates the transition energy using the rydberg formula
    return R * pow(Z, 2) * ( (1/pow(n1, 2)) - (1/pow(n2, 2)) );
}

int main()
{
    float rydbergEnergy = 13.606;
    int atomicNumber;
    int initialNumber;
    int finalNumber;
    char units;
    char running = 'y';


    cout << "Enter atomic number: ";
    cin >> atomicNumber;

    cout << "Enter initial quantum number: ";
    cin >> initialNumber;

    cout << "Enter final quantum number: ";
    cin >> finalNumber;

    cout << "Would you like the answer in Joules (type 'j') or Electron Volts (type 'e'): ";
    cin >> units;
    
    // Ensure answer is in lowercase
    tolower(units);

    float photonEnergy = CalculateTransitionEnergy(rydbergEnergy, atomicNumber, 
      initialNumber, finalNumber);

    // Check which units to output answer in, convert if necessary
    if (units == 'e')
    {
      cout << "Transition Energy: " << photonEnergy << " eV" << endl;
    }
    else
    {
      photonEnergy *= 1.6 * pow(10, -19);
      cout << "Emmited Photon Energy: " << photonEnergy << " J" << endl;
    }

  return 0;
}
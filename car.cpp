#include <iostream>
#include <string>
using namespace std;

const int FULL_TANK = 14;

class FancyCar {
   public:
      // Default constructor
      FancyCar();
      
      // Constructor (string make, double mpg)
      FancyCar(string carMake, double carMpg);
      
      // Return car model
      string GetModel();
      
      // Return miles per gallon (MPG)
      double GetMPG();
      
      // Return miles on odometer
      int CheckOdometer();
      
      // Return amount of gas in tank
      double CheckGasGauge();
      
      // Honk horn
      void HonkHorn();
      
      // Drive car requested miles but check for enough
      // gas and check for positive value
      void Drive(int milesToDrive);
      
      // Add gas to tank. Check for positive value.
      void AddGas(double amtToAdd) ;
      
      // Set boolean variable to true
      void StartEngine();
      
      // Set boolean variable to false
      void StopEngine();

   private:
      int odometer;
      double gallons;
      double mpg;
      double capacity;
      string model;
      bool engineOn; 
};

FancyCar::FancyCar() {
   odometer = 5;
   gallons = FULL_TANK;
   mpg = 24.0;
   model = "Old Clunker";
   engineOn = false;
}

FancyCar::FancyCar(string carMake, double carMpg) {
    odometer = 5;
   gallons = FULL_TANK;
   mpg = carMpg;
   model = carMake;
   engineOn = false;
}

// Return car model
string FancyCar::GetModel() {
   return model;
}

// Return miles per gallon (MPG)
double FancyCar::GetMPG() {
   return mpg;
}

// Return miles on odometer
int FancyCar::CheckOdometer() {
   return odometer;
}

// Return amount of gas in tank
double FancyCar::CheckGasGauge() {
   return gallons;
}

// Honk horn
void FancyCar::HonkHorn() {
   cout << "The " << model << " says beep beep!";
}

// Drive car requested miles but check for enough
// gas and check for positive value
void FancyCar::Drive(int milesToDrive) {
   
   if (milesToDrive > 0 && engineOn){
    double milesAvailable =  gallons * mpg;
    gallons = milesToDrive > milesAvailable ? 0 : milesToDrive/mpg;
    odometer = milesToDrive > milesAvailable ? milesAvailable : milesToDrive;
    if (gallons == 0) { !engineOn; }
   }
}

// Add gas to tank. Check for positive value.
void FancyCar::AddGas(double amtToAdd) {
  if (amtToAdd > 0 && !engineOn){
    gallons = gallons + amtToAdd > FULL_TANK ? FULL_TANK : gallons + amtToAdd;
  }
}

// Set boolean variable to true
 void FancyCar::StartEngine(){
    engineOn = true;
}

// Set boolean variable to false
void FancyCar::StopEngine(){
   engineOn = false; 
}

int main() {
   FancyCar car;
   car.Drive(50);
   cout << "Miles driven: " << car.CheckOdometer() << endl;
   cout << "Gas Tank: " <<  car.CheckGasGauge() << " gallons" << endl;
   
   /* Add statements as functions are completed to support development mode test */
   
   return 0;
}
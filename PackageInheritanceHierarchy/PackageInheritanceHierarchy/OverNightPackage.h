#include "Package.h"
#ifndef ONPackage_H
#define ONPackage_H
class OverNightPackage :
    public Package
{
public:
    //Constructor
    OverNightPackage(std::string, std::string, std::string, std::string, std::string,
        std::string, std::string, std::string, std::string, std::string,
        double, double, double);
    //Setter functions
    void setAdditionalFeesPerOunce(double);
    //Calculate cost function
    double calculateCost() const;
    //Dispaly other details like weight and cost
    void displayDetails() const;
protected:
    double additionalFeesPerOunce;
};
#endif
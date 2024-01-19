#include "Package.h"
#ifndef TWO_DAY_P_H
#define TWO_DAY_P_H
class TwoDayPackage :
    public Package
{
public:
    //Constructor
    TwoDayPackage(std::string, std::string, std::string, std::string, std::string,
        std::string, std::string, std::string, std::string, std::string,
        double, double, double);
    //Setter method
    void setFlatFee(double);
    //Calculate total cost
    double calculateCost() const;
    //Display details like weight, fees
    void displayDetails() const;
protected:
    double flatFee;
};
#endif


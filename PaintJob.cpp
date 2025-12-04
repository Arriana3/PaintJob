#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int getRooms()
{
    int rooms;
    cout << "How many rooms need painting? : ";
	cin >> rooms;
    while (rooms <= 0){
        cout << "Invalid input. Number of rooms must be greater than 0. Try again: ";
		cin >> rooms;
    }
    return rooms;
}

int getSqft(int room)
{
    int sqft;
    cout << "What is the square footage of room " << room << "? : ";
	cin >> sqft;
    while (sqft <= 0)
    { 
        cout << "Invalid input. Square footage must be greater than 0. Try again: ";
		cin >> sqft;
    }
    return sqft;
}

double getPaintCost()
{
    double paintCost;
    cout << "What is the cost of paint per gallon? : ";
	cin >> paintCost;
	while (paintCost < 10)
    {
        cout << "Invalid input. Paint cost must be greater than 10. Try again: ";
		cin >> paintCost;
    }
    return paintCost;
}

    double gallonsForSqft(int totalSqft)
{
    return  double (totalSqft) / 110.0;
}

double paintCharge(double paintCostPerGallon, double gallons)
{
    return paintCostPerGallon * gallons;
}

double laborCharge(int totalSqft)
{
    double laborHours = (double(totalSqft) / 110.0) * 8.0;
    return laborHours * 25.0;
}

int main()
{
    int rooms = getRooms();

    int totalSqft = 0;
    for (int i = 1; i <= rooms; ++i) {
        totalSqft += getSqft(i);
    }

    double paintCostPerGallon = getPaintCost();

    double gallonsNeeded = gallonsForSqft(totalSqft);
   

    double totalPaintCost = paintCharge(paintCostPerGallon, gallonsNeeded);
    double totalLaborCost = laborCharge(totalSqft);
    double laborHours = (double(totalSqft) / 110.0) * 8.0;
   
    cout << " Estimate for painting " << rooms << " rooms.\n";
    cout << "Gallons of paint to purchase: " << round(gallonsNeeded) << "\n";
    cout << "Number of labor hours required: " << round(laborHours) << "\n";
 cout << fixed << setprecision(2);
    cout << "Total cost of paint: $" << totalPaintCost << "\n";
    cout << "Total cost of labor: $" << totalLaborCost << "\n";
    cout << "Total cost of the paint job: $" << (totalPaintCost + totalLaborCost) << "\n";

    return 0;
}
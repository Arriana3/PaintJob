

#include <iostream>
using namespace std;

int getRooms()
{
    int rooms;
    cout << "how many rooms need painting ? : " << endl;
    cin >> rooms;
    if (rooms <= 1)
    {
        cout << "Invalid input. Number of rooms must be greater than 1." << endl;
        cin >> rooms;
    }
    return rooms;
}

double getSqft()
{
    double sqft;
    cout << "What is the Square footage of each room ? : " << endl;
    cin >> sqft;
    if (sqft <= 0)
    {
        cout << "Invalid input. Square footage must be greater than 0. Try again." << endl;
       cin >> sqft;
    }
    return sqft;

}
double getPaintCost()
{
    double paintCost;
    cout << "What is the cost of paint per gallon ? : " << endl;
    cin >> paintCost;
    if (paintCost <= 10)
    {
        cout << "Invalid input. Paint cost must be greater than $10. Try again." << endl;
        cin >> paintCost;
    }
    return paintCost;
}

double gallonsPerRoom(int sqft)
{
    double gallons;
    gallons = sqft / 110;

    return gallons;

}
double PaintCharge(double paintCost, double gallons)
{
    double totalPaintCost;
    totalPaintCost = paintCost * gallons;
    return totalPaintCost;
}

double LaborCharge(int sqft)
{
    double laborHours;
    double laborCost;
    laborHours = (sqft / 110) * 8;
    laborCost = laborHours * 25;
    return laborCost;
}



int main()
{
   
    int rooms=getRooms();
    double sqft = 0;
    double total = 0;
    double Paintcost = 0;
	double GallonsNeeded = 0;
    ;
   for (int i = 0; i < rooms; i++)
    {
		double sqft = getSqft();
        GallonsNeeded = gallonsPerRoom(sqft);
        Paintcost = getPaintCost();
    }

    Paintcost = PaintCharge(Paintcost, GallonsNeeded);
    double laborHours = 0;
      double laborCharge = LaborCharge(sqft);
		total += Paintcost + laborCharge;



    

    cout << "Estimate for Painting " << rooms << " rooms." << endl;
    cout << "Gallons of Paint to be purchased : " << GallonsNeeded << endl;
    cout << "Number of hours required to paint the rooms: " << laborHours << endl;
    cout << "Total cost of paint : $" << Paintcost << endl;
    cout << "Total cost of labor: $" << laborCharge << endl;
    cout << "Total cost of the paint job : $" << total <<   endl;
    return 0;
}
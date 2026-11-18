// Pizza Party Planner
// Adrian Marinas
// 11/18/2026
// Create a program to plan for a pizza party
// I wrote this code myself

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double NUM_SLICES = 8.0;
const double GST_TAX = 0.05;

// --------------------- prototypes ----------------------

void printBanner();
int calcSliceNeed(int numGuest, int sliceGuest);
int calcOrderPizza(int sliceNeed);
double calcsubTotal(int orderPizza, double pricePizza);
double calcGstTax(double subTotal);
double calcPerGuest(double finalTotal, int numGuest);

// --------------------- main function ------------------
int main () {
    string partyName;
    int numGuest; // number of guests
    int sliceGuest; // slices per guest
    double pricePizza; // price per pizza
    int sliceNeed; // slices needed
    int orderPizza; // amount of pizzas to order
    double subTotal; // total before tax
    double finalTotal; // total after tax
    double gstTax; // the tax
    double perGuest; // total per guest

    cout << fixed << setprecision(2); // two decimal places from here on
    cout << "Please enter your party name: ";
    getline(cin, partyName);
    cout << "Please enter the amount of guests";
    cin >> numGuest;
    cout << "How many slice for each guest?";
    cin >> sliceGuest;
    cout << "What is the price per pizza?";
    cin >> pricePizza;


    cout << "Party Name: " << partyName << endl;
    cout << "Number of guests: " << numGuest << endl;
    cout << "Slices per guest: " << sliceGuest << endl;
    cout << "Price per pizza: $" << pricePizza << endl << endl;

    sliceNeed = calcSliceNeed(numGuest, sliceGuest);
    orderPizza = calcOrderPizza(sliceNeed);
    subTotal = calcsubTotal(orderPizza, pricePizza);
    gstTax = calcGstTax(subTotal);
    finalTotal = subTotal + gstTax;
    perGuest = calcPerGuest(finalTotal, numGuest);


    printBanner();
    cout << "Party:                 " << partyName << endl;
    cout << "Guests:                " << numGuest << endl;
    cout << "Slices needed:         " << sliceNeed << endl;
    cout << "Pizzas to order:       " << orderPizza << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Subtotal:              $" << subTotal << endl;
    cout << "GST (5%):              $" << gstTax << endl;
    cout << "Total:                 $" << finalTotal << endl;
    cout << "Per guest:             $" << perGuest << endl;
    cout << "=========================================" << endl;
}

// ---------------------- function definitions -----------------

// PURPOSE: Prints the three-line banner at the top of the receipt
// INPUT: none
// OUTPUT: none
void printBanner() {
    cout << "=========================================" <<endl;
    cout << "           PIZZA PARTY PLANNER           " << endl;
    cout << "-----------------------------------------" << endl;
}

// PURPOSE: calculates the slices of pizza needed
// INPUT: guests - the number of guests
//        slicesPerGuest - the number of slices each guest is going to eat
// OUTPUT: returns the total number of slices needed for the party.
int calcSliceNeed(int numGuest, int sliceGuest) {
    return numGuest * sliceGuest;
}

// PURPOSE: calculates how many whole pizzas to order, rounded up
// INPUT: sliceNeed - the amount of slices needed
// OUTPUT: returns the total amount of pizzas to order
int calcOrderPizza(int sliceNeed) {
    return ceil(sliceNeed/NUM_SLICES);
}


// PURPOSE: calculates the gst of the order
// INPUT: subTotal - the cost of the order before tax
// OUTPUT: returns the GST on the order
double calcGstTax(double subTotal) {
    return subTotal * GST_TAX;
}

// PURPOSE: calculates the subtotal of the order
// INPUT: orderPizza - the amount of pizzas to order
//        pricePizza - the price of each pizza
// OUTPUT: returns the cost before tax
double calcsubTotal(int orderPizza, double pricePizza) {
    return orderPizza * pricePizza;
}

// PURPOSE: calculate how much each guest has to pay
// INPUT: finalTotal - the total cost of the order including GST
//        numGuest - the amount of guests attending the party
// OUTPUT: returns each guest's share of the total
double calcPerGuest(double finalTotal, int numGuest) {
    return finalTotal/numGuest;
}


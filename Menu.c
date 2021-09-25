#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{

time_t t; 
    // create array to hold prices of each food item 
    double prices [] = { 9.95 , 4.55 , 13.25, 22.35};
    
    // create 2d array to hold string names of each 
    char foods [4][15] = {"salad", "soup", "sandwich", "pizza"};

    // random time 
    srand((unsigned) time(&t));
    
    // declare tip percentage 
    double Tip;
    printf("What is the Tip?: ");
    scanf("%lf", &Tip);
    
    //Declare Tax on Food Items
    double Tax;
    printf("What is the Tax?: ");
    scanf("%lf", &Tax);

    //Choose a integer between 0 and 3
    int i = rand() % 4;

    //Multiply the price of food by the tax converted to decimal form to find total cost with Tax!!
    double TaxMeal = prices[i] * Tax/100; 
    double TaxCost = (prices[i] * (1+(Tax/100)));

     //Multiply the price of food by the Tip converted to decimal form to find total cost with Tip!!
    double Tipping = (TaxCost * Tip/100);

    //Total cost of the Meal including Tip and Tax
    double TotalPrice = (TaxCost) * (1+(Tip/100));

    //Print everything out
    printf("The Tax Total cost will be %.2f\n", TaxMeal);
    printf("The Tip Total will be %.2f\n", Tipping);
    printf("The total cost of the Food %s, at %.2f including Tax and Tip will be %.2f", foods[i], prices[i], TotalPrice);


    return 0;
}
/* Unit 8 Assigment passing a struct by pointer (*)
Kiet Vo
COSC 1436_57002_Dr_T */
#include <iostream>
#include <string>
using namespace std;
//declaration of the struct

struct car
{
  string Make;
  string Model;
  int Year;
  string Color;
};
//function defenition declare above in main()
void printCar(car *c)
{
  cout << "\nCar details: " << endl;
  cout << "Make - " << c->Make << endl;
  cout << "Model - " << c->Model << endl;
  cout << "Year - " << c->Year << endl;
  //set the color cariable based on the year and print it
  if(c->Year <= 2010)
  {
    c->Color = "RED";
  }
  else if(c->Year > 2010)
  {
    c->Color = "GREEN";
  }
  //print the color to the screen
  cout << "Color: " << c->Color << endl;
}
  void preserveData(car &c)
  {
    cout << "\nORIGINAL DATA in c: ";
    printCar(&c);

      car *p_car = &c;

    cout << "\nData copied into a new struct ";
    printCar(p_car);

      new(p_car) car;
      cout << p_car->Year << endl;//print current year
      new(p_car) car(); //default constructor
      cout << p_car->Year << endl; //print 0

    cout << "\nData after default const. reset: ";
    printCar(p_car);

    cout << "\nORIGINAL DATA in c: ";
    printCar(&c);
  }


int main() 
{
  //declare an instance of the struct
  car car1;
  car1.Make = "Toyota";
  car1.Model = "Avalon";
  car1.Year = 2009;

  car car2 = {"Tesla", "Model 3", 2019};

  car car3 ={"Honda", "Accord", 2013};
  
  //print each car
  printCar(&car1);
  printCar(&car2);
  printCar(&car3);

  preserveData(car1);
  preserveData(car2);
  preserveData(car3);

  return 0;
}
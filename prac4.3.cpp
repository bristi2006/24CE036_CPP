#include <iostream>
#include <queue>
#include <string>
using namespace std;
class Fuel {
protected:
string fuelType;
public:
    Fuel(string fuel = "") {
        fuelType = fuel;
    }
  void displayFuel() const {
        cout << "Fuel Type: " << fuelType << endl;
    }
};
class Brand {
protected:
    string brandName;
public:
    Brand(string brand = "") {
        brandName = brand;
    }
void displayBrand() const {
        cout << "Brand Name: " << brandName << endl;
    }
};
class Car : public Fuel, public Brand {
public:
 Car(string brand = "", string fuel = "") : Brand(brand), Fuel(fuel) {}
void displayCar() const {

        displayBrand();
        displayFuel();
    }
};
int main() {
    int n;
    cout << "Enter the number of cars: ";
    cin >> n;

    cout << "\n=== STL Approach (using std::queue) ===" << endl;
    queue<Car> carQueue;
 for (int i = 0; i < n; ++i) {
        string brand, fuel;
        cout << "\nEnter details for Car " << i + 1 << ":" << endl;
        cout << "Enter brand name: ";
        cin >> brand;
        cout << "Enter fuel type: ";
        cin >> fuel;

        Car c(brand, fuel);
        carQueue.push(c);
    }
 cout << "\nCars in service queue (FIFO order):" << endl;

    while (!carQueue.empty()) {
        carQueue.front().displayCar();
        cout << "---------------------" << endl;
        carQueue.pop();
    }
  cout << "\n=== Non-STL Approach (using Array) ===" << endl;
    Car* carArray = new Car[n];
  for (int i = 0; i < n; ++i) {
        string brand, fuel;
        cout << "\nEnter details for Car " << i + 1 << ":" << endl;
        cout << "Enter brand name: ";
        cin >> brand;
        cout << "Enter fuel type: ";
        cin >> fuel;
 carArray[i] = Car(brand, fuel);
    }
 cout << "\nCars stored in Array:" << endl;
    for (int i = 0; i < n; ++i) {
        carArray[i].displayCar();
        cout << "---------------------" << endl;
    }
 delete[] carArray;
 cout<<"24ce036_Bristi"<<endl;
    return 0;

}

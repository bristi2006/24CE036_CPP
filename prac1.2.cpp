
/* Programmer: Bristi Gopani
   Date:10-2-25
   Aim:to create a product management system for a retail store*/

#include<iostream>
#include<string>
using namespace std;

// Products class to manage product details
class Products
{
    // Private data members to store product information
    int PId, PStock;            // Product ID and available stock
    string PName;               // Product name
    float Price_per_unit;       // Price per unit of the product

    public:
    // Function to add a new product
    void AddProduct()
    {
        cout << "\nEnter the Product ID:";
        cin >> PId;
        cout << "\nEnter the Product Name:";
        cin >> PName;
        cout << "\nEnter the available Product quantity:";
        cin >> PStock;
        cout << "\nEnter the Product Price Per Unit:";
        cin >> Price_per_unit;
    }

    // Function to update the stock of a product by product ID
    void UpdateStock(int Product_id)
    {
        if(Product_id == PId) // Check if the provided ID matches
        {
            cout << "\nEnter the Updated available Product quantity:";
            cin >> PStock;
            cout << "\nThe Updated available Product quantity is: " << PStock;
        }
        else
        {
            cout << "\nID Number not found"; // Error message if ID doesn't match
        }
    }

    // Inline function to calculate the total value of a product
    inline float CalculateTotalValue(float value)
    {
        value = (Price_per_unit) * (PStock); // Total value = price * stock
        return value;
    }
};

int main()
{
    Products Items[10]; // Array to store up to 10 products

    int n; // Number of product types
    cout << "\nEnter the types of products available:";
    cin >> n;

    float v, TotalValue = 0;
    int id, i, o; // Loop and menu choice variables

    // Menu-driven system for product management
    do
    {
        cout << "\nEnter (1) to Add Product";
        cout << "\nEnter (2) to Update Stock";
        cout << "\nEnter (3) to calculate total value of all products";
        cout << "\nEnter (4) to exit\n";
        cin >> o;

        switch(o)
        {
            case 1:
                // Add details for each product
                for(i = 0; i < n; i++)
                    Items[i].AddProduct();
                break;

            case 2:
                 // Product ID to update
                cout << "\nEnter the id number of product to update the stock:";
                cin >> id;
                // Search for the product and update its stock
                for(i = 0; i < n; i++)
                {
                    Items[i].UpdateStock(id);
                }
                break;

            case 3:

                // Calculate the total value of all products
                for(i = 0; i < n; i++)
                {
                    v = Items[i].CalculateTotalValue(TotalValue);
                    TotalValue += v; // Accumulate the total value
                }
                cout << "\nTotal Value is: " << TotalValue;
                break;

            case 4:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout<<"24CE036"<<endl;
    } while(o != 4); // Continue until user chooses to exit

    return 0;
}

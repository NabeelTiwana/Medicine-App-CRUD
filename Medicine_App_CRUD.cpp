
/*
    Medical Store
        - Item Record
            - id
            - name
            - price
            - quantity
*/

#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

void menu()
{
    cout << "a. Add Item\n";
    cout << "d. Delete Item\n";
    cout << "u. Update Item\n";
    cout << "s. Search Item\n";
    cout << "v. View complete Items\n";
    cout << "e. Exit\n";
}
int searchItem(int *ids, int id, int products)
{
    if (products == 0)
    {
        return -1;
    }

    for (int i = 0; i < products; i++)
    {
        if (ids[i] == id)
            return i;
    }

    return -1;
}
bool insertItem(int *ids, string *names, double *prices, int *quantities, int &products)
{
    int id, quantity;
    string name;
    double price;
    cout << "Enter ID : ";
    cin >> id; // 101 enter

    int index = searchItem(ids, id, products);
    if (index != -1)
    {
        return false;
    }

    cin.ignore();
    cout << "Enter name : ";
    getline(cin, name);
    cout << "Enter price : ";
    cin >> price;
    cout << "Enter Quantity : ";
    cin >> quantity;

    // store these variables into arrays
    ids[products] = id;
    names[products] = name;
    prices[products] = price;
    quantities[products] = quantity;
    products++;
    return true;
}
void displayItem(int *ids, string *names, double *prices, int *quantities, int index)
{
    cout << "ID         : " << ids[index] << endl;
    cout << "NAME       : " << names[index] << endl;
    cout << "PRICE      : " << prices[index] << endl;
    cout << "QUANTITY   : " << quantities[index] << endl<< endl;
}
int main()
{
    int size = 5;
    int products = 0;
    char choice;
    // parallel arrays
    int *ids = new int[size];
    string *names = new string[size];
    double *prices = new double[size];
    int *quantities = new int[size];
    ////////////////////////////////////

    do
    {
        system("cls");
        menu();
        choice = getche();
        if (choice == 'a' || choice == 'A')
        {
            if (products == size)
            {
                // regrow arrays
                // regrow ids array
                int *temp = new int[size * 2];
                for (int i = 0; i < size; i++)
                {
                    temp[i] = ids[i];
                }
                delete[] ids;
                ids = temp;

                // regrow names
                string *temp1 = new string[size * 2];
                for (int i = 0; i < size; i++)
                {
                    temp1[i] = names[i];
                }
                delete[] names;
                names = temp1;

                // regrow price
                double *temp2 = new double[size * 2];
                for (int i = 0; i < size; i++)
                {
                    temp2[i] = prices[i];
                }
                delete[] prices;
                prices = temp2;

                // regrow quantity
                temp = new int[size * 2];
                for (int i = 0; i < size; i++)
                {
                    temp[i] = quantities[i];
                }
                delete[] quantities;
                quantities = temp;

                size = size * 2;
            }

            bool flag = insertItem(ids, names, prices, quantities, products);
            if (flag)
            {
                cout << "Data inserted successfully\n";
            }
            else
            {
                cerr << "Trying to add duplicate data\n";
            }
        }
        else if (choice == 's' || choice == 'S')
        {
            int id;
            cout << "Enter the id to search Item : ";
            cin >> id;

            int index = searchItem(ids, id, products);
            if (index == -1)
            {
                cout << "Item with id " << id << " not found in our records\n";
            }
            else
            {
                cout << "    ITEM INFORMATION\n";
                displayItem(ids, names, prices, quantities, index);
            }
        }
        else if (choice == 'v' || choice == 'V')
        {
            cout << "    ITEM INFORMATION\n";
            for (int i = 0; i < products; i++)
            {
                displayItem(ids, names, prices, quantities, i);
            }
        }
        else if (choice == 'u' || choice == 'U')
        {
            int id;
            cout << "Enter the id to update Item : ";
            cin >> id;

            int index = searchItem(ids, id, products);
            if (index == -1)
            {
                cout << "Item with id " << id << " not found in our records\n";
            }
            else
            {
                cout << "    ITEM INFORMATION\n";
                displayItem(ids, names, prices, quantities, index);

                cout << "press 1 to update price\n";
                cout << "press 2 to update quantity\n";
                choice = getche();
                if (choice == '1')
                {
                    double price;
                    cout << "Enter new price : ";
                    cin >> price;
                    prices[index] = price;
                    cout << "Prices updated successfully\n";
                }
                else if (choice == '2')
                {
                    int quant;
                    cout << "Enter new quantity : ";
                    cin >> quant;
                    quantities[index] = quant;
                    cout << "Quantity updated successfully\n";
                }
                else
                {
                    cerr << "Wrong choice selected\n";
                }
            }
        }
        else if (choice == 'd' || choice == 'D')
        {
            int id;
            cout << "Enter the id to delete Item : ";
            cin >> id;

            int index = searchItem(ids, id, products);
            if (index == -1)
            {
                cout << "Item with id " << id << " not found in our records\n";
            }
            else
            {
                cout << "    ITEM INFORMATION\n";
                displayItem(ids, names, prices, quantities, index);

                cout << "Do you really want to delete (1/0)\n";
                choice = getche();
                if (choice == '1')
                {
                    if (index == products - 1)
                    {
                        products--;
                    }
                    else
                    {
                        for (int i = index; i < products - 1; i++)
                        {
                            ids[i] = ids[i + 1];
                            prices[i] = prices[i + 1];
                            names[i] = names[i + 1];
                            quantities[i] = quantities[i + 1];
                        }
                        products--;
                    }
                    cout << "Product Deleted Successfully\n";
                }
                else if (choice == '0')
                {
                    cout << "Ok. Thank you\n";
                }
                else
                {
                    cerr << "Wrong choice selected\n";
                }
            }
            if(products==0){
              cout<<"List is empty:\n";
            }
        }

        system("pause");
    } while (choice != 'e' && choice != 'E');

    return 0;
}

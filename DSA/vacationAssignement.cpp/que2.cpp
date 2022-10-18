#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int Normal_Discount_Status;
int Jubilee_Discount_Status;
struct date
{
    int day;
    int month;
    int year;
} Normal_Discount_Date_Stamp, Jubilee_Discount_Date_Stamp;
class Manager_Functions
{

public:
    /*
Stored in this order :
ID
name
DOB
address
points
last transaction
Normal Discount status
Jubilee discount status
*/
    void Add_Customer(string name, string DOB, string address);
    /*
Grocery : 1
Garments : 2
Electronics :3
*/
    void Add_Item(string name, int quantity, int type, int price);
    // Returns a vector list of all customer ID
    vector<string> Generate_Customer_ID_List();
    // Returns a vector list of all item ID
    vector<string> Generate_Item_ID_List();
    /*
    1 : name
    2 : DOB
    3 : Address
    4 : Points
    5 : Last Transaction
    Takes in the element key and the ID returns the entry in string
    */
    string Read_From_Customer_DB(int element, int ID);
    /*
    1 : Name
    2 : Type
    3 : Price
    4 : Quantity 
    Takes in the element key and the ID returns the entry in string
    */
    string Read_From_Item_DB(int element, int id); /*
    0 : items
    1 :Customer
    Generates a uniqe sequential id 
    */
    int Generate_ID(int type);
    /*Updates customer details, takes in element , id and new entry*/
    void Customer_Updation(int element, int ID, string New);
    /*Updates item details, takes in element, id entry*/
    void Item_Updation(int element, int ID, string New);
    void Initiate_Normal_Discount(struct date current);
    void Initiate_Jubilee_Discount(struct date current);
    int Discount(int id, struct date current);
    int Age_Calc(struct date current, struct date DOB);
    struct date Convert_To_Date(string raw_date);
    vector<int> Get_Points_List();
    vector<int> Get_Senior_Citizen_List(struct date current);
    friend int See_Points(int id);
    friend void Update_Address(int id, string new_address);
    friend void Display_Items(struct date *current);
    friend int Purchase_Item(int customer_id, int item_id, int quantity);
};
class Customer_Functions
{
public:
    int id;
    void Display_Items(struct date current, int id);
    int Purchase_Item(int customer_id, int item_id, int quantity, int current_date);
    int See_Points(int id);
    void Update_Address(int id, string new_address);
};

int main()
{
    int choice, type, price, id, quantity, element, item_id, points;
    string name, address, birth, last_trans, points_string, type_string, price_string, quantity_string, new_entry, tmp, DOB_string;
    struct date DOB;
    Manager_Functions M;
    Customer_Functions C;
    int date_int = 25112021;
    struct date current;
    current.day = 25;
    current.month = 11;
    current.year = 2021;

Identity:
    cout << "Who are you?\n"
         << endl;
    cout << "1.) The manager" << endl;
    cout << "2.) A Customer" << endl;

    cin >> choice;

    if (choice == 1)
    {
        cout << "Manager options :" << endl;

        while (1 <= choice <= 8)
        {
            cout << "Manager options :" << endl;
            cout << "1) Add Customer" << endl;
            cout << "2) Add Item" << endl;
            cout << "3) Read entries in customer database" << endl;
            cout << "4) Read entries in item database" << endl;
            cout << "5) Update Customer entries" << endl;
            cout << "6) Update Item entries" << endl;
            cout << "7) Initiate Loyalty Discount" << endl;
            cout << "8) Initiate Jubilee Discount" << endl;
            cin >> choice;
            getline(cin, tmp);
            switch (choice)
            {
            case 1:
                cout << "Enter the name" << endl;
                getline(cin, name);
                cout << "Enter the address" << endl;
                getline(cin, address);
                cout << "Enter birth date in DDMMYYYY format with no spaces" << endl;
                getline(cin, DOB_string);
                cin.ignore();
                M.Add_Customer(name, DOB_string, address);

                cout << "Customer Entry made" << endl;

                break;
            case 2:
                cout << "Enter the name" << endl;
                getline(cin, name);
                cout << "Enter stock quantity" << endl;
                cin >> quantity;
                cout << "Enter Type" << endl;
                cout << "1 for groceries" << endl;
                cout << "2 for garments" << endl;
                cout << "3 for electronics" << endl;
                cin >> type;
                cout << "Enter price" << endl;
                cin >> price;
                M.Add_Item(name, quantity, type, price);
                cout << "Item entry made" << endl;
                break;
            case 3:
                cout << "Enter Customer ID" << endl;
                cin >> id;
                name = M.Read_From_Customer_DB(1, id);
                birth = M.Read_From_Customer_DB(2, id);
                address = M.Read_From_Customer_DB(3, id);
                points_string = M.Read_From_Customer_DB(4, id);
                last_trans = M.Read_From_Customer_DB(5, id);
                cout << "| Name :" << name << "| DOB :" << birth << "| Address :" << address << "| Points :" << points_string << "| Last Transaction :" << last_trans << endl;
                break;
            case 4:
                cout << "Enter item id" << endl;
                cin >> id;
                name = M.Read_From_Item_DB(1, id);
                type_string = M.Read_From_Item_DB(2, id);
                price_string = M.Read_From_Item_DB(3, id);
                quantity_string = M.Read_From_Item_DB(4, id);

                cout << "| Name :" << name << "| Type :" << type_string << "| Price :" << price_string << "| Quantity :" << quantity_string;
                break;
            case 5:
                cout << "Enter Customer id" << endl;
                cin >> id;
                cout << "Enter the field you want to update" << endl;
                cout << "1 : Name\n 2 : DOB\n 3 :Address\n 4 :Points\n 5 : Last Transaction" << endl;
                cin >> element;
                cout << "Enter new entry" << endl;
                cin >> new_entry;

                M.Customer_Updation(element, id, new_entry);
                cout << "Updated" << endl;
                break;
            case 6:
                cout << "Enter item id" << endl;
                cin >> id;
                cout << "Enter the field you want to edit" << endl;
                cout << "1 : Name\n 2 : Type\n 3 : Price \n 4 : Quantity" << endl;
                cin >> element;
                cout << "Enter the new entry" << endl;
                cin >> new_entry;

                M.Item_Updation(element, id, new_entry);
                cout << "Updated" << endl;
                break;
            case 7:
                M.Initiate_Normal_Discount(current);
                cout << "Discount Initiated" << endl;
                break;
            case 8:
                M.Initiate_Jubilee_Discount(current);
                cout << "Discount Initiated" << endl;
                break;
            default:
                goto Identity;
                break;
            }
        }
    }
    else if (choice == 2)
    {
        cout << "Customer Options : " << endl;
        cout << "Enter customer id :" << endl;
        cin >> id;

        while (1 <= choice <= 4)
        {
            cout << "1) Display items" << endl;
            cout << "2) Purchase Items" << endl;
            cout << "3) See Points" << endl;
            cout << "4) Update Address" << endl;
            cin >> choice;

            switch (choice)
            {

            case 1:
                C.Display_Items(current, id);
                break;
            case 2:
                cout << "Enter item id" << endl;
                cin >> item_id;
                cout << "Enter quantity" << endl;
                cin >> quantity;

                C.Purchase_Item(id, item_id, quantity, date_int);

                cout << "Purchase done" << endl;

                break;
            case 3:
                points = C.See_Points(id);
                cout << "Points :" << points << endl;
                break;
            case 4:
                cout << "Enter new Address" << endl;
                getline(cin, tmp);
                getline(cin, address);
                M.Customer_Updation(3, id, address);
                break;
            default:
                goto Identity;
                break;
            }
        }
    }
    else
    {
        cout << "Invalid Input" << endl;
        goto Identity;
    }

    return 0;
}

//manager functions definition

void Manager_Functions ::Add_Customer(string name, string DOB_string, string address)
{

    int ID = Generate_ID(1);

    fstream DB;
    DB.open("Shopping Card Database.txt", ios ::app);
    DB << "ID :\n"
       << ID << endl;
    DB << "Name :\n"
       << name << endl;
    DB << "DOB :\n"
       << DOB_string << endl;
    DB << "Address\n"
       << address << endl;
    DB << "Points:\n"
       << 700 << endl;
    DB << "Last Transaction :\n"
       << "---" << endl;

    DB.close();
}
void Manager_Functions ::Add_Item(string name, int quantity, int type, int price)
{

    fstream DB;
    int ID = Generate_ID(0);

    DB.open("Item DB.txt", ios::app);

    DB << "ID :" << endl;
    DB << ID << endl;
    DB << "Name :" << endl;
    DB << name << endl;
    DB << "Type :" << endl;
    DB << type << endl;
    DB << "Price :" << endl;
    DB << price << endl;
    DB << "Quantity :" << endl;
    DB << quantity << endl;

    DB.close();
}
int Manager_Functions ::Generate_ID(int type)
{
    vector<string> ID_List;
    int last;

    if (type == 0)
    {
        /*Add code for ID gen for items*/
        ID_List = Generate_Item_ID_List();

        if (ID_List.size() == 0)
        {
            return 1;
        }
        else
        {
            last = stoi(ID_List.back());
            return ++last;
        }
    }
    else if (type == 1)
    {
        ID_List = Generate_Customer_ID_List();

        if (ID_List.size() == 0)
        {
            return 1;
        }
        else
        {
            last = stoi(ID_List.back());

            return ++last;
        }
    }
}
vector<string> Manager_Functions ::Generate_Customer_ID_List()
{
    string tmp;

    vector<string> ID_List;

    fstream DB;

    DB.open("Shopping Card Database.txt", ios ::in);

    while (DB.eof() == 0)
    {
        getline(DB, tmp);

        //compare returns 0 on equality
        if (!tmp.compare("ID :"))
        {
            getline(DB, tmp);
            ID_List.push_back(tmp);
        }
    }
    DB.close();
    return ID_List;
}
vector<string> Manager_Functions ::Generate_Item_ID_List()
{
    string tmp;

    vector<string> ID_List;
    fstream DB;

    DB.open("Item DB.txt", ios ::in);

    while (DB.eof() == 0)
    {
        getline(DB, tmp);
        if (!tmp.compare("ID :"))
        {
            getline(DB, tmp);
            ID_List.push_back(tmp);
        }
    }
    DB.close();

    return ID_List;
}
string Manager_Functions ::Read_From_Customer_DB(int element, int ID)
{
    fstream DB;
    string tmp;
    string id = to_string(ID);

    DB.open("Shopping Card Database.txt", ios ::in);
    switch (element)
    {
        //to retrieve name
        int i;
    case 1:
        while (DB.eof() == 0)
        {
            getline(DB, tmp);
            //returns true if the strings are equal, since compare returns 0 on equality
            if (!tmp.compare("ID :"))
            {
                getline(DB, tmp);
                //returns true if ID is equal to given id
                if (!tmp.compare(id))
                {
                    for (i = 0; i < 2; i++)
                    {
                        getline(DB, tmp);
                    }
                    return tmp;
                }
            }
        }

        break;
    //to retrieve DOB
    case 2:
        while (DB.eof() == 0)
        {
            getline(DB, tmp);
            //returns true if the strings are equal, since compare returns 0 on equality
            if (!tmp.compare("ID :"))
            {
                getline(DB, tmp);
                //returns true if ID is equal to given id
                if (!tmp.compare(id))
                {
                    for (i = 0; i < 4; i++)
                    {
                        getline(DB, tmp);
                    }
                    return tmp;
                }
            }
        }

        break;
    //to retrieve Address
    case 3:
        while (DB.eof() == 0)
        {
            getline(DB, tmp);
            //returns true if the strings are equal, since compare returns 0 on equality
            if (!tmp.compare("ID :"))
            {
                getline(DB, tmp);
                //returns true if ID is equal to given id
                if (!tmp.compare(id))
                {
                    for (i = 0; i < 6; i++)
                    {
                        getline(DB, tmp);
                    }
                    return tmp;
                }
            }
        }

        break;

        //to retrieve points
    case 4:
        while (DB.eof() == 0)
        {
            getline(DB, tmp);
            //returns true if the strings are equal, since compare returns 0 on equality
            if (!tmp.compare("ID :"))
            {
                getline(DB, tmp);
                //returns true if ID is equal to given id
                if (!tmp.compare(id))
                {
                    for (i = 0; i < 8; i++)
                    {
                        getline(DB, tmp);
                    }
                    return tmp;
                }
            }
        }

        break;

    //To retrieve Last transaction
    case 5:
        while (DB.eof() == 0)
        {
            getline(DB, tmp);
            //returns true if the strings are equal, since compare returns 0 on equality
            if (!tmp.compare("ID :"))
            {
                getline(DB, tmp);
                //returns true if ID is equal to given id
                if (!tmp.compare(id))
                {
                    for (i = 0; i < 10; i++)
                    {
                        getline(DB, tmp);
                    }
                    return tmp;
                }
            }
        }

        break;
    case 6:
        while (DB.eof() == 0)
        {
            getline(DB, tmp);
            //returns true if the strings are equal, since compare returns 0 on equality
            if (!tmp.compare("ID :"))
            {
                getline(DB, tmp);
                //returns true if ID is equal to given id
                if (!tmp.compare(id))
                {
                    for (i = 0; i < 12; i++)
                    {
                        getline(DB, tmp);
                    }
                    return tmp;
                }
            }
        }
        break;
    case 7:
        while (DB.eof() == 0)
        {
            getline(DB, tmp);
            //returns true if the strings are equal, since compare returns 0 on equality
            if (!tmp.compare("ID :"))
            {
                getline(DB, tmp);
                //returns true if ID is equal to given id
                if (!tmp.compare(id))
                {
                    for (i = 0; i < 10; i++)
                    {
                        getline(DB, tmp);
                    }
                    return tmp;
                }
            }
        }
        break;
    default:
        cout << "Invalid selection of type" << endl;
        break;
    }
    DB.close();
}
string Manager_Functions ::Read_From_Item_DB(int element, int ID)
{
    fstream DB;
    string tmp;

    string id = to_string(ID);

    DB.open("Item DB.txt", ios ::in);
    switch (element)
    {
        int i;
    //to get name
    case 1:
        while (DB.eof() == 0)
        {
            getline(DB, tmp);
            //returns true if the strings are equal, since compare returns 0 on equality
            if (!tmp.compare("ID :"))
            {
                getline(DB, tmp);
                //returns true if ID is equal to given id
                if (!tmp.compare(id))
                {
                    for (i = 0; i < 2; i++)
                    {
                        getline(DB, tmp);
                    }
                    return tmp;
                }
            }
        }
        break;
    //to get type
    case 2:
        while (DB.eof() == 0)
        {
            getline(DB, tmp);
            //returns true if the strings are equal, since compare returns 0 on equality
            if (!tmp.compare("ID :"))
            {
                getline(DB, tmp);
                //returns true if ID is equal to given id
                if (!tmp.compare(id))
                {
                    for (i = 0; i < 4; i++)
                    {
                        getline(DB, tmp);
                    }
                    return tmp;
                }
            }
        }
    //to get price
    case 3:
        while (DB.eof() == 0)
        {
            getline(DB, tmp);
            //returns true if the strings are equal, since compare returns 0 on equality
            if (!tmp.compare("ID :"))
            {
                getline(DB, tmp);
                //returns true if ID is equal to given id
                if (!tmp.compare(id))
                {
                    for (i = 0; i < 6; i++)
                    {
                        getline(DB, tmp);
                    }
                    return tmp;
                }
            }
        }
    case 4:
        while (DB.eof() == 0)
        {
            getline(DB, tmp);
            //returns true if the strings are equal, since compare returns 0 on equality
            if (!tmp.compare("ID :"))
            {
                getline(DB, tmp);
                //returns true if ID is equal to given id
                if (!tmp.compare(id))
                {
                    for (i = 0; i < 8; i++)
                    {
                        getline(DB, tmp);
                    }
                    return tmp;
                }
            }
        }
        break;
    default:
        break;
    }
}
void Manager_Functions ::Customer_Updation(int element, int ID, string New)
{
    fstream DB, Buffer;
    string tmp;
    std ::string id = to_string(ID);
    int i;

    //Generating the
    DB.open("Shopping Card Database.txt", ios ::in);
    Buffer.open("Buffer.txt", ios ::out);
    //Generating the updated file in Buffer
    switch (element)
    {
    //Update name
    case 1:
        while (DB.eof() == 0)
        {
            getline(DB, tmp);
            Buffer << tmp << endl;
            //returns true if the line is equal to "ID :"
            if (!tmp.compare("ID :"))
            {
                getline(DB, tmp);
                Buffer << tmp << endl;
                //returns true if the ID is equal to user inputted id
                if (!tmp.compare(id))
                {
                    for (i = 0; i < 1; i++)
                    {
                        getline(DB, tmp);
                        Buffer << tmp << endl;
                    }
                    getline(DB, tmp);
                    Buffer << New << endl;
                }
            }
        }
        break;
    case 2:
        while (DB.eof() == 0)
        {
            getline(DB, tmp);
            Buffer << tmp << endl;
            if (!tmp.compare("ID :"))
            {
                getline(DB, tmp);
                Buffer << tmp << endl;
                if (!tmp.compare(id))
                {
                    for (i = 0; i < 3; i++)
                    {
                        getline(DB, tmp);
                        Buffer << tmp << endl;
                    }
                    getline(DB, tmp);
                    Buffer << New << endl;
                }
            }
        }
        break;
    case 3:
        while (DB.eof() == 0)
        {
            getline(DB, tmp);
            Buffer << tmp << endl;
            if (!tmp.compare("ID :"))
            {
                getline(DB, tmp);
                Buffer << tmp << endl;
                if (!tmp.compare(id))
                {
                    for (i = 0; i < 5; i++)
                    {
                        getline(DB, tmp);
                        Buffer << tmp << endl;
                    }
                    getline(DB, tmp);
                    Buffer << New << endl;
                }
            }
        }
        break;
    case 4:
        while (DB.eof() == 0)
        {
            getline(DB, tmp);
            Buffer << tmp << endl;
            if (!tmp.compare("ID :"))
            {
                getline(DB, tmp);
                Buffer << tmp << endl;
                if (!tmp.compare(id))
                {
                    for (i = 0; i < 7; i++)
                    {
                        getline(DB, tmp);
                        Buffer << tmp << endl;
                    }
                    getline(DB, tmp);
                    Buffer << New << endl;
                }
            }
        }
        break;
    case 5:
        while (DB.eof() == 0)
        {
            getline(DB, tmp);
            Buffer << tmp << endl;
            if (!tmp.compare("ID :"))
            {
                getline(DB, tmp);
                Buffer << tmp << endl;
                if (!tmp.compare(id))
                {
                    for (i = 0; i < 9; i++)
                    {
                        getline(DB, tmp);
                        Buffer << tmp << endl;
                    }
                    getline(DB, tmp);
                    Buffer << New << endl;
                }
            }
        }
        break;
    case 6:
        while (DB.eof() == 0)
        {
            getline(DB, tmp);
            Buffer << tmp << endl;
            if (!tmp.compare("ID :"))
            {
                getline(DB, tmp);
                Buffer << tmp << endl;
                if (!tmp.compare(id))
                {
                    for (i = 0; i < 11; i++)
                    {
                        getline(DB, tmp);
                        Buffer << tmp << endl;
                    }
                    getline(DB, tmp);
                    Buffer << New << endl;
                }
            }
        }
        break;
    case 7:
        while (DB.eof() == 0)
        {
            getline(DB, tmp);
            Buffer << tmp << endl;
            if (!tmp.compare("ID :"))
            {
                getline(DB, tmp);
                Buffer << tmp << endl;
                if (!tmp.compare(id))
                {
                    for (i = 0; i < 13; i++)
                    {
                        getline(DB, tmp);
                        Buffer << tmp << endl;
                    }
                    getline(DB, tmp);
                    Buffer << New << endl;
                }
            }
        }
        break;
    default:
        cout << "Invalid selection of type" << endl;
        break;
    }

    DB.close();
    Buffer.close();
    //Copying the updated file into it's original location
    DB.open("Shopping Card Database.txt", ios ::out);
    Buffer.open("Buffer.txt", ios ::in);

    while (Buffer.eof() == 0)
    {
        getline(Buffer, tmp);
        DB << tmp << endl;
    }

    DB.close();
    Buffer.close();
}
void Manager_Functions ::Item_Updation(int element, int ID, string New)
{
    fstream DB, Buffer;
    string tmp;
    std ::string id = to_string(ID);
    int i;

    //Generating the
    DB.open("Item DB.txt", ios ::in);
    Buffer.open("Buffer.txt", ios ::out);
    //Generating the updated file in Buffer

    switch (element)
    {
    case 1:
        while (DB.eof() == 0)
        {
            getline(DB, tmp);
            Buffer << tmp << endl;
            //returns true if the line is equal to "ID :"
            if (!tmp.compare("ID :"))
            {
                getline(DB, tmp);
                Buffer << tmp << endl;
                //returns true if the ID is equal to user inputted id
                if (!tmp.compare(id))
                {
                    for (i = 0; i < 1; i++)
                    {
                        getline(DB, tmp);
                        Buffer << tmp << endl;
                    }
                    getline(DB, tmp);
                    Buffer << New << endl;
                }
            }
        }

        break;
    case 2:
        while (DB.eof() == 0)
        {
            getline(DB, tmp);
            Buffer << tmp << endl;
            //returns true if the line is equal to "ID :"
            if (!tmp.compare("ID :"))
            {
                getline(DB, tmp);
                Buffer << tmp << endl;
                //returns true if the ID is equal to user inputted id
                if (!tmp.compare(id))
                {
                    for (i = 0; i < 3; i++)
                    {
                        getline(DB, tmp);
                        Buffer << tmp << endl;
                    }
                    getline(DB, tmp);
                    Buffer << New << endl;
                }
            }
        }

        break;
    case 3:
        while (DB.eof() == 0)
        {
            getline(DB, tmp);
            Buffer << tmp << endl;
            //returns true if the line is equal to "ID :"
            if (!tmp.compare("ID :"))
            {
                getline(DB, tmp);
                Buffer << tmp << endl;
                //returns true if the ID is equal to user inputted id
                if (!tmp.compare(id))
                {
                    for (i = 0; i < 5; i++)
                    {
                        getline(DB, tmp);
                        Buffer << tmp << endl;
                    }
                    getline(DB, tmp);
                    Buffer << New << endl;
                }
            }
        }
        break;
    case 4:
        while (DB.eof() == 0)
        {
            getline(DB, tmp);
            Buffer << tmp << endl;
            //returns true if the line is equal to "ID :"
            if (!tmp.compare("ID :"))
            {
                getline(DB, tmp);
                Buffer << tmp << endl;
                //returns true if the ID is equal to user inputted id
                if (!tmp.compare(id))
                {
                    for (i = 0; i < 7; i++)
                    {
                        getline(DB, tmp);
                        Buffer << tmp << endl;
                    }
                    getline(DB, tmp);
                    Buffer << New << endl;
                }
            }
        }
        break;
    default:
        cout << "Invalid Selection type" << endl;
        break;
    }
    DB.close();
    Buffer.close();
    //Copying the updated file into it's original location
    DB.open("Item DB.txt", ios ::out);
    Buffer.open("Buffer.txt", ios ::in);

    while (Buffer.eof() == 0)
    {
        getline(Buffer, tmp);
        DB << tmp << endl;
    }

    DB.close();
    Buffer.close();
}
void Manager_Functions ::Initiate_Normal_Discount(struct date current)
{
    Normal_Discount_Status = 1;
    Normal_Discount_Date_Stamp.day = current.day;
    Normal_Discount_Date_Stamp.month = current.month;
    Normal_Discount_Date_Stamp.year = current.year;
}
void Manager_Functions ::Initiate_Jubilee_Discount(struct date current)
{
    Jubilee_Discount_Status = 1;
    Jubilee_Discount_Date_Stamp.day = current.day;
    Jubilee_Discount_Date_Stamp.month = current.month;
    Jubilee_Discount_Date_Stamp.year = current.year;
}
int Manager_Functions ::Discount(int id, struct date current)
{

    int i, j, k, Normal_Discount_Recievers[10], Jubilee_Discount_Recievers[10], size_of_list, list_element;
    int Normal_Eligible = 0;
    int Jubilee_Eligible = 0, Seniors_Check;
    //stores the amount of months since the last wave of discounts
    int No_Of_Months_Normal, No_Of_Months_Jubilee;
    vector<int> Points_List, Seniors_List;

    struct date *Customer_DOB;
    struct date *List_DOB;
    string tmp, customer_DOB_string;
    int customer_DOB_int, age;

    No_Of_Months_Normal = abs(current.day - Normal_Discount_Date_Stamp.day) + 30 * abs(current.month - Normal_Discount_Date_Stamp.month) + 365 * abs(current.year - Normal_Discount_Date_Stamp.year);

    No_Of_Months_Normal = No_Of_Months_Normal / 30;

    No_Of_Months_Jubilee = abs(current.day - Jubilee_Discount_Date_Stamp.day) + 30 * abs(current.month - Jubilee_Discount_Date_Stamp.month) + 365 * abs(current.year - Jubilee_Discount_Date_Stamp.year);

    No_Of_Months_Jubilee = No_Of_Months_Jubilee / 30;

    /*Add code that takes an array of points list of above 1000 and assigns the correct eligibility*/

    // This is for the normal discount
    Points_List = Get_Points_List();

    size_of_list = Points_List.size();

    for (i = 0; i < size_of_list; i++)
    {
        if (id == Points_List.at(i) && Normal_Discount_Status == 1)
        {
            Normal_Eligible = 1;
            break;
        }
    }

    //For Jubilee discount

    Seniors_List = Get_Senior_Citizen_List(current);

    for (i = 0; i < size_of_list; i++)
    {
        for (k = 0; k < Seniors_List.size(); k++)
        {
            if (Points_List.at(i) == Seniors_List.at(k))
                ;
            {
                Seniors_Check = 1;
            }
        }
        if (id == Points_List.at(i) && Seniors_Check == 1 && Jubilee_Discount_Status == 1)
        {
            Jubilee_Eligible = 1;
            break;
        }
    }

    //returns appropriate discount
    if (Normal_Eligible == 1 && Jubilee_Eligible == 0)
    {
        return 10;
    }
    else if (Normal_Eligible == 0 && Jubilee_Eligible == 1)
    {
        return 15;
    }
    else if (Normal_Eligible == 1 && Jubilee_Eligible == 1)
    {
        return 15;
    }
    else
    {
        return 0;
    }
};
int Manager_Functions ::Age_Calc(struct date current, struct date DOB)
{
    int age;

    age = abs(current.day - DOB.day) + 30 * abs(current.month - DOB.month) + 365 * abs(current.year - DOB.year);
    age = age / 365;
    return age;
}
struct date Manager_Functions ::Convert_To_Date(string raw_date)
{
    struct date DOB;
    long long int DOB_int;
    DOB_int = stoi(raw_date);

    DOB.year = DOB_int % 10000;
    DOB.month = ((DOB_int - DOB.year) / 10000) % 100;
    DOB.day = ((((DOB_int - DOB.year) / 10000) - DOB.month) / 100) % 100;

    return DOB;
};
vector<int> Manager_Functions ::Get_Points_List()
{
    vector<int> points_list;
    string tmp;
    int x;
    fstream List;

    List.open("1000 points list.txt", ios ::in);

    while (List.peek() != EOF)
    {
        getline(List, tmp);
        x = stoi(tmp);
        points_list.push_back(x);
    }

    return points_list;
}
vector<int> Manager_Functions ::Get_Senior_Citizen_List(struct date current)
{
    vector<int> Senior_Citizen_List;
    vector<string> All_List;
    int i, current_id, age;
    string tmp;
    struct date DOB;

    All_List = Generate_Customer_ID_List();

    for (i = 0; i < All_List.size(); i++)
    {

        current_id = stoi(All_List.at(i));

        tmp = Read_From_Customer_DB(2, current_id);
        //cout<<tmp<<endl;
        cout << "____________" << endl;
        DOB = Convert_To_Date(tmp);
        cout << DOB.day << "\n"
             << DOB.month << "\n"
             << DOB.day << endl;
        age = Age_Calc(current, DOB);

        if (age > 60)
        {
            Senior_Citizen_List.push_back(current_id);
        }
    }

    return Senior_Citizen_List;
}
//customer function definition

void Customer_Functions ::Display_Items(struct date current, int id)
{
    vector<string> ID_List;
    string name, price_string, quantity, type;
    int size, i, discount;
    float price;

    Manager_Functions M;

    discount = M.Discount(id, current);

    ID_List = M.Generate_Item_ID_List();

    size = ID_List.size();

    for (i = 0; i < size; i++)
    {
        //ID function returns strings

        name = M.Read_From_Item_DB(1, stoi(ID_List.at(i)));

        type = M.Read_From_Item_DB(2, stoi(ID_List.at(i)));

        //price is of int and the read function returns a string
        price_string = M.Read_From_Item_DB(3, stoi(ID_List.at(i)));
        price = stoi(price_string);
        price = price * (100 - discount) / 100;
        quantity = M.Read_From_Item_DB(4, stoi(ID_List.at(i)));

        cout << name << "\t|";
        if (stoi(type) == 1)
        {
            cout << "Grocery\t|";
        }
        else if (stoi(type) == 2)
        {
            cout << "Garments\t|";
        }
        else if (stoi(type) == 3)
        {
            cout << "Electronics\t|";
        }

        cout << "Price :" << price << "\t|";

        if (quantity != "0")
        {
            cout << "Quantity :" << quantity << "\t|";
        }
        else
        {
            cout << "Quantity : Out of Stock\t|";
        }

        cout << "Discount :" << discount << "\t";

        cout << endl;
    }
}
int Customer_Functions ::Purchase_Item(int customer_id, int item_id, int quantity, int current_date)
{
    Manager_Functions M;
    int price, stock, points, type, tmp;

    price = stoi(M.Read_From_Item_DB(3, item_id));
    stock = stoi(M.Read_From_Item_DB(4, item_id));
    points = stoi(M.Read_From_Customer_DB(4, customer_id));
    type = stoi(M.Read_From_Item_DB(2, item_id));

    if (stock < 1)
    {
        cout << "item out of stock";
        return 0;
    }
    tmp = stock;
    stock = stock - quantity;
    if (stock < 1)
    {
        cout << "Not enough items in stock " << tmp << "Only available" << endl;
    }

    if (type == 1)
    {
        points = points + (price * quantity) / 100;
    }
    else if (type == 2)
    {
        points = points + (price * quantity) / 100 * 5;
    }
    else if (type == 3)
    {
        points = points + (price * quantity) / 100 * 10;
    }

    cout << points << endl;
    cout << stock << endl;
    M.Customer_Updation(4, customer_id, to_string(points));
    M.Item_Updation(4, item_id, to_string(stock));
    M.Customer_Updation(5, customer_id, to_string(current_date));

    fstream Points_Records;

    Points_Records.open("1000 points list.txt", ios::app);

    if (points > 1000)
    {
        Points_Records << customer_id << endl;
    }

    Points_Records.close();
}
int Customer_Functions ::See_Points(int id)
{
    int points;
    Manager_Functions M;
    string points_string;
    points_string = M.Read_From_Customer_DB(4, id);
    points = stoi(points_string);
    return points;
}
void Customer_Functions ::Update_Address(int id, string new_address)
{
    Manager_Functions M;
    M.Customer_Updation(3, id, new_address);
    cout << "Updated" << endl;
}

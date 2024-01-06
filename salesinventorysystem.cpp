#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<ctime>
#include<chrono>
#include <iomanip>
#include <sstream>
#include <vector>
#include<algorithm>
using namespace std;

class Item
{
private:
    string SKU;
    string description;
    string price;
    string quantity;
    //Sales sale;
    vector<string> items;
public:
    Item()
    {
        SKU = " ";
        description = " ";
        price = " ";
        quantity = " ";
    }
    Item(string SKU, string description, string price, string quantity)
    {
        this->SKU = SKU;
        this->description = description;
        this->price = price;
        this->quantity = quantity;
    }

    void setSKU(string s) { SKU = s; }
    string getSKU() { return SKU; }

    void setDescription(string d) { description = d; }
    string getDescription() { return description; }

    void setPrice(int p) { price = p; }
    string getPrice() { return price; }

    void setQuantity(int q) { quantity = q; }
    string getQuantity() { return quantity; }

    void additem()
    {
        cout << "\nEnter item SKU: ";
        cin >> SKU;

        cout << "Enter item description: ";
        cin.ignore();
        getline(cin, description);

        cout << "Enter item price: ";
        cin >> price;

        cout << "Enter item quantity: ";
        cin >> quantity;

        cout << "\ndo you want to save this item information? (y/n): ";
        char confirm;
        cin >> confirm;

        items.push_back(SKU);
        items.push_back(description);
        items.push_back(price);
        items.push_back(quantity);

        if (confirm == 'Y' || confirm == 'y') {
            // Save the Item information
            ofstream file;
            file.open("items.txt", ios_base::app);
            file << items[0] << "\t" << items[1] << "\t" << items[2] << "\t" << items[3] << endl;
            file.close();

            cout << "\nItem information successfully saved.\n";
        }
        else if (confirm == 'N' || confirm == 'n')
        {
            cout << "\nItem information not saved.\n";
        }
        items.clear();
    }

    void displayItem(const Item& item)
    {
        cout << "Item_SKU" << "\tDescription" << "\tPrice" << "\tQuantity" << endl;
        cout << item.SKU << "\t" << item.description << "\t" << item.price << "\t" << item.quantity << endl;
        //cout << "Creation Date: " << item.creation_date << endl;
    }


    void updateitem()
    {
        cout << "\nUpdate item details\n";
        int op;
        string item_sku, Description, quant, pr, temp_sku, temp_description, temp_quantity, temp_price;

        cout << "Enter item SKU: ";
        cin.ignore();
        getline(cin, item_sku);

        fstream myfile("items.txt");
        string line;
        int flag = 1;
        while (getline(myfile, line)) 
        {
            istringstream iss(line);
            if (iss)
            {
                iss >> temp_sku >> temp_description >> temp_price >> temp_quantity;
                if (item_sku == temp_sku)
                {
                    break;
                }
            }
        }

        if (item_sku == temp_sku)
        {
            cout << "\nItem Found" << endl;
            cout << "Item Description: " << temp_description << endl;
            cout << "Item Quantity: " << temp_quantity << endl;
            cout << "Item Price: " << temp_price << endl;
            cout << "\nPress 1 to change description. 2 for quantity. 3 for price" << endl;
            cin >> op;

            if (op == 1)
            {
                cout << "Enter new description: ";
                cin.ignore();
                getline(cin, temp_description);
                removeitem(item_sku);
                fstream file;
                file.open("items.txt", ios_base::app);
                file << temp_sku << "\t" << temp_description << "\t" << temp_price << "\t" << temp_quantity << endl;
                file.close();
            }
            else if (op == 2)
            {
                cout << "Enter new QUANTITY: ";
                cin.ignore();
                getline(cin, temp_quantity);
                removeitem(item_sku);
                fstream file;
                file.open("items.txt", ios_base::app);
                file << temp_sku << "\t" << temp_description << "\t" << temp_price << "\t" << temp_quantity << endl;
                file.close();
            }
            else if (op == 3)
            {
                cout << "Enter new PRICE: ";
                cin.ignore();
                getline(cin, temp_price);
                removeitem(item_sku);
                fstream file;
                file.open("items.txt", ios_base::app);
                file << temp_sku << "\t" << temp_description << "\t" << temp_price << "\t" << temp_quantity << endl;
                file.close();
            }
            else
            {
                cout << "invalid input" << endl;
            }
        }
        else
        {
            cout << "item not found" << endl;
        }
    }

    void finditem()
    {
        string sku, desc, price_str, quantity_str, temp_sku, temp_description, temp_quantity, temp_price;
        
        cout << "Please specify at least one of the following to find the item. Leave all fields blank to return to Customers" << endl;

        cout << "Item_SKU: ";
        cin.ignore();
        getline(cin, sku);

        cout << "Description: ";
        getline(cin, desc);

        cout << "Price: ";
        getline(cin, price_str);

        cout << "Quantity: ";
        getline(cin, quantity_str);

        fstream myfile("items.txt");
        string line;
        int flag = 1;
        while (getline(myfile, line)) 
        {
            istringstream iss(line);
            if (iss)
            {
                iss >> temp_sku >> temp_description >> temp_price >> temp_quantity;
                if (sku == temp_sku)
                {
                    cout << "\nItem Found" << endl;
                    cout << "\nItem Details" << endl;
                    cout << "Description: " << temp_description << endl;
                    cout << "Quantity: " << temp_quantity << endl;
                    cout << "Price: " << temp_price << endl;
                    flag = 1;
                    break;
                }
                else if (desc == temp_description)
                {
                    cout << "\nItem Found" << endl;
                    cout << "\nItem Details" << endl;
                    cout << "SKU: " << temp_sku << endl;
                    cout << "Quantity: " << temp_quantity << endl;
                    cout << "Price: " << temp_price << endl;
                    flag = 1;
                    break;
                }
                else if (price_str == temp_price)
                {
                    cout << "\nItem Found" << endl;
                    cout << "\nItem Details" << endl;
                    cout << "SKU: " << temp_sku << endl;
                    cout << "Quantity: " << temp_quantity << endl;
                    cout << "Description: " << temp_description << endl;
                    flag = 1;
                    break;
                }
                else if (quantity_str == temp_quantity)
                {
                    cout << "\nItem Found" << endl;
                    cout << "\nItem Details" << endl;
                    cout << "SKU: " << temp_sku << endl;
                    cout << "Price: " << temp_price << endl;
                    cout << "Description: " << temp_description << endl;
                    flag = 1;
                    break;
                }
                else
                {
                    flag = 0;
                }
            }
        }
        if (flag == 0) {
            cout << "item not found" << endl;
        }
    }

    void removeitem(string temp) 
    {
        string n;
        if (temp == " ") {
            cout << "enter item sku to be removed: ";
            cin >> n;
        }
        else {
            n = temp;
        }
        ifstream inputFile("items.txt");
        vector<string> lines;
        string line;
        while (getline(inputFile, line)) {
            istringstream iss(line);
            string sku;
            getline(iss, sku, '\t');

            if (sku != n)
                lines.push_back(line);
        }

        inputFile.close();

        ofstream outputFile("items.txt");
        if (!outputFile) {
            cerr << "Failed to open the output file." << endl;
            return;
        }
        for (const string& line : lines) {
            outputFile << line << endl;
        }

        outputFile.close();
        if (temp == " ") {
            cout << "Item with SKU " << n << " removed successfully." << endl;
        }
        else {
            cout << "Item with SKU " << n << " updated successfully." << endl;
        }
    }
};

class Customer
{
private:
    string cnic;
    string name;
    string address;
    string phone;
    string email;
    string type;
    string amountpayable;
    string saleslimit;

    vector<string> customers;
public:
    Customer()
    {
        cnic = " ";
        name = " ";
        address = " ";
        phone = " ";
        email = " ";
        type = " ";
        amountpayable = " ";
        saleslimit = " ";
    }
    Customer(string cnic, string name, string phone, string email, string type, string amountpayable, string saleslimit)
    {
        this->cnic = cnic;
        this->name = name;
        this->phone = phone;
        this->email = email;
        this->type = type;
        this->amountpayable = amountpayable;
        this->saleslimit = saleslimit;
    }

    // setter functions
    void setCNIC(string C) { cnic = C; }
    void setName(string n) { name = n; }
    void setAddress(string a) { address = a; }
    void setPhone(int p) { phone = p; }
    void setEmail(string e) { email = e; }
    void setType(string t) { type = t; }
    void setSalesLimit(string sl) { saleslimit = sl; }

    // getter functions
    string getCNIC() { return cnic; }
    string getName() { return name; }
    string getAddress() { return address; }
    string getPhone() { return phone; }
    string getEmail() { return email; }
    string getType() { return type; }

    string getSalesLimit()
    {
        return saleslimit;
    }

    void addCustomer()
    {
        cout << "\nenter the following information of the customer:" << endl;

        cout << "enter cnic: ";
        cin >> cnic;

        cout << "enter name: ";
        cin.ignore();
        getline(cin, name);

        cout << "enter phone number: ";
        cin >> phone;

        cout << "enter email: ";
        cin.ignore();
        getline(cin, email);

        cout << "enter type: ";
        cin.ignore();
        getline(cin, type);

        cout << "\ndo you want to save this item information? (y/n): ";
        char confirm;
        cin >> confirm;

        customers.push_back(cnic);           //0
        customers.push_back(name);          //1
        customers.push_back(phone);     //2
        customers.push_back(email);      //3
        customers.push_back(type);       //4
        //customers.push_back(amountpayable);    //5
        customers.push_back(saleslimit);      //6

        if (confirm == 'Y' || confirm == 'y')
        {
            // Save the Item information
            ofstream file2;
            file2.open("customer.txt", ios_base::app);
            file2 << customers[0] << "\t" << customers[1] << "\t" << customers[2] << "\t" << customers[3] << "\t" << customers[4] << "\t" << customers[5] << endl;
            file2.close();

            cout << "Customer Information successfully saved.\n";
        }
        else if (confirm == 'N' || confirm == 'n')
        {
            cout << "\nCustomer information not saved.\n";
        }
        customers.clear();
    }

    void updateCustomer()
    {
        cout << "\nUpdate Customer's details\n";
        int opt = 0;
        string CNIC, Name, Email, type, Phone, temp_name, temp_CNIC, temp_phone, temp_email, temp_type;

        cout << "\nEnter CNIC of customer to update: ";
        cin.ignore();
        getline(cin, CNIC);

        fstream myfile("customer.txt");
        string line;
        int flag = 1;
        while (getline(myfile, line)) 
        {
            istringstream iss(line);
            if (iss)
            {
                iss >> temp_name, temp_CNIC, temp_phone, temp_email, temp_type;
                if (CNIC == temp_CNIC)
                {
                    break;
                }
            }
        }
        if (CNIC == temp_CNIC)
        {
            cout << "\nCustomer Found" << endl;
            cout << "\nCustomer Details:" << endl;
            cout << "Name: " << temp_name << endl;
            cout << "Phone: " << temp_phone << endl;
            cout << "Email: " << temp_email << endl;
            cout << "Type: " << temp_type << endl;
            cout << "\nPress 1 to change Name. 2 for Phone Number. 3 for Email. 4 for Type" << endl;
            cin >> opt;

            if (opt == 1)
            {
                cout << "Enter new Name: ";
                cin.ignore();
                getline(cin, temp_name);

                removecustomer(CNIC);
                fstream file;
                file.open("customer.txt", ios_base::app);
                file << temp_CNIC << "\t" << temp_name << "\t" << temp_phone << "\t" << temp_email << "\t" << temp_type << endl;
                file.close();
            }
        }

        else if (opt == 2)
        {
            cout << "Enter new Phone Number: ";
            cin.ignore();
            getline(cin, temp_phone);

            removecustomer(CNIC);
            fstream file;
            file.open("customer.txt", ios_base::app);
            file << temp_CNIC << "\t" << temp_name << "\t" << temp_phone << "\t" << temp_email << "\t" << temp_type << endl;
            file.close();

            cout << "\nPhone number updated successfully" << endl;
        }
        else if (opt == 3)
        {
            cout << "Enter new Email: ";
            cin.ignore();
            getline(cin, temp_email);

            removecustomer(CNIC);
            fstream file;
            file.open("customer.txt", ios_base::app);
            file << temp_CNIC << "\t" << temp_name << "\t" << temp_phone << "\t" << temp_email << "\t" << temp_type << endl;
            file.close();

            cout << "\nEmail updated successfully" << endl;
        }

        else if (opt == 4)
        {
            cout << "Enter new Type: ";
            cin.ignore();
            getline(cin, temp_type);

            removecustomer(CNIC);
            fstream file;
            file.open("customer.txt", ios_base::app);
            file << temp_CNIC << "\t" << temp_name << "\t" << temp_phone << "\t" << temp_email << "\t" << temp_type << endl;
            file.close();

            cout << "\nType of customer updated successfully" << endl;
        }
    }

    void findCustomer()
    {
        string NAME, CNIC, PHONE, EMAIL, TYPE, temp_name, temp_cnic, temp_phone, temp_email, temp_type;

        cout << "Please specify at least one of the following to find the customer. Leave all fields blank to return to Customers Menu:" << endl;

        cout << "CNIC: ";
        cin.ignore();
        getline(cin, CNIC);

        cout << "Name: ";
        getline(cin, NAME);

        cout << "Phone: ";
        //cin.ignore();
        getline(cin, PHONE);

        cout << "Email: ";
        getline(cin, EMAIL);

        cout << "Type: ";
        getline(cin, TYPE);

        fstream myfile("customer.txt");
        string line;
        int flag = 1;
        while (getline(myfile, line)) 
        {
            istringstream iss(line);
            if (iss)
            {
                iss >> temp_name, temp_cnic, temp_phone, temp_email, temp_type;

                // search for the customer
                if (NAME == temp_name)
                {
                    cout << "\nCustomer Found" << endl;
                    cout << "\nCustomer Details:" << endl;
                    cout << "CNIC: " << temp_cnic << endl;
                    cout << "Phone: " << temp_phone << endl;
                    cout << "Email: " << temp_email << endl;
                    cout << "Type: " << temp_type << endl;
                    flag = 1;
                    break;
                }
                else if (CNIC == temp_cnic)
                {
                    cout << "\nCustomer Found" << endl;
                    cout << "\nCustomer Details:" << endl;
                    cout << "Name: " << temp_name << endl;
                    cout << "Phone: " << temp_phone << endl;
                    cout << "Email: " << temp_email << endl;
                    cout << "Type: " << temp_type << endl;
                    flag = 1;
                    break;
                }
                else if (PHONE == temp_phone)
                {
                    cout << "\nCustomer Found" << endl;
                    cout << "\nCustomer Details:" << endl;
                    cout << "Name: " << temp_name << endl;
                    cout << "CNIC: " << temp_cnic << endl;
                    cout << "Email: " << temp_email << endl;
                    cout << "Type: " << temp_type << endl;
                    flag = 1;
                    break;
                }
                else if (EMAIL == temp_email)
                {
                    cout << "\nCustomer Found" << endl;
                    cout << "\nCustomer Details:" << endl;
                    cout << "Name: " << temp_name << endl;
                    cout << "CNIC: " << temp_cnic << endl;
                    cout << "Phone: " << temp_phone << endl;
                    cout << "Type: " << temp_type << endl;
                    flag = 1;
                    break;
                }
                else if (TYPE == temp_type)
                {
                    cout << "\nCustomer Found" << endl;
                    cout << "\nCustomer Details:" << endl;
                    cout << "Name: " << temp_name << endl;
                    cout << "CNIC: " << temp_cnic << endl;
                    cout << "Phone: " << temp_phone << endl;
                    cout << "Email: " << temp_email << endl;
                    flag = 1;
                    break;
                }
                else
                    flag = 0;
            }
        }
        if (flag == 0) {
            cout << "Customer not found" << endl;
        }
    }

    void removecustomer(string temp)
    {
        string CNIC;

        if (temp == " ")
        {
            cout << "Enter the CNIC of the customer to be removed: ";
            cin >> CNIC;
        }
        else
        {
            CNIC = temp;
        }

        ifstream inputFile("customer.txt");
        vector<string> lines;
        string line;

        while (getline(inputFile, line))
        {
            istringstream iss(line);
            string cnic;
            getline(iss, cnic, '\t');

            if (cnic != CNIC)
                lines.push_back(line);
        }

        inputFile.close();

        ofstream outputFile("customer.txt");
        if (!outputFile)
        {
            cerr << "Failed to open the output file." << endl;
            return;
        }
        for (const string& line : lines)
        {
            outputFile << line << endl;
        }

        outputFile.close();
        if (temp == " ")
        {
            cout << "Customer removed successfully." << endl;
        }
        else
        {
            cout << "Customer updated successfully." << endl;
        }
    }
};

class SilverCustomers : public Customer
{
public:
    SilverCustomers(string cnic, string name, string phone, string email, string type, string amountpayable, string saleslimit) : Customer(cnic, name, phone, email, "Silver", "0", "40000")
    {
        setSalesLimit("40000");
        getSalesLimit();
    }
};

class GoldCustomers : public Customer
{
private:
    double Discount;

public:
    GoldCustomers(string cnic, string name, string phone, string email, string type, string amountpayable, string saleslimit) : Customer(cnic, name, phone, email, "Gold", "0", "100000")
    {
        setSalesLimit("100000");
        getSalesLimit();
        Discount = 0.03;
    }

    double getDiscount()
    {
        getSalesLimit();
        return Discount;
    }
};

class PlatinumCustomers : public Customer
{
private:
    double Discount;
public:
    PlatinumCustomers(string cnic, string name, string phone, string email, string type, string amountpayable, string saleslimit) : Customer(cnic, name, phone, email, "Platinum", "0", "250000")
    {
        setSalesLimit("250000");
        getSalesLimit();
        Discount = 0.05;
    }

    double getDiscount()
    {
        return Discount;
    }
};


class Sales;
class Receipt;
class SalesLineItem : public Item
{
private:

    int lineno;
    int quantity;
    Sales* sal;
    Item it;


public:
    SalesLineItem()
    {
    }

    SalesLineItem(int lno, int quan, Sales* s, Item i)
    {
        lineno = lno;
        quantity = quan;
        sal = s;
        it = i;
    }

};

class Sales
{
private:
    int saleID;
    string date;
    SalesLineItem salit;
    Receipt* rec;
    Customer cus;
    char status;
    vector<string> sold;
public:
    vector<int> sales_cust;
    Sales()
    {
        saleID = 1;
    }
    int get_saleid() {
        return saleID;
    }
    string get_date() {
        return date;
    }

    Sales(int id, string d, SalesLineItem sli, Receipt* r, Customer cu, char st)     //parameterisedconstructor

    {
        saleID = id;
        date = d;
        salit = sli;
        rec = r;
        cus = cu;
        status = st;
    }
    vector<int> get_sales_cust() {
        return sales_cust;
    }
    /*void makenewsale ()
    {
        auto now= chrono::system_clock::now();
        time_t t=chrono::system_clock::to_time_t(now);
        string date= ctime(&t);
        saleID= saleID+1;
        cout<<"Sale ID is: "<<saleID<<endl;
        cout<<date<<endl;
        int n;
        cin>>n;
        cus.set_cnic(n);
    }
*/


    void makenewsale()
    {

        vector<string> v;
        auto now = chrono::system_clock::now();
        time_t t = chrono::system_clock::to_time_t(now);
        tm* ptm = localtime(&t);
        stringstream ss;
        ss << put_time(ptm, "%Y-%m-%d %H:%M:%S");
        date = ss.str();
        cout << "Sale ID is: " << saleID << endl;
        cout << date << endl;
        string n;
        string s;
        if (!sales_cust.empty()) 
        {
            for (int i = 0; i < (saleID * 3); i = i + 3) {
                if (sales_cust[i] != saleID) {
                    cout << "Enter CNIC: ";
                    cin >> n;
                    cus.setCNIC(n);
                    sales_cust[0] = saleID;
                    sales_cust.push_back(stoi(cus.getCNIC()));
                    sales_cust.push_back(0);
                }
            }
        }
        else {
            cout << "Enter CNIC: ";
            cin >> n;
            cus.setCNIC(n);
            sales_cust.push_back(saleID);
            sales_cust.push_back(stoi(cus.getCNIC()));
            sales_cust.push_back(0);
        }
        cout << endl;
        cout << "Enter Item-SKU: ";
        cin >> s;
        salit.getSKU();
        fstream myfile("items.txt");
        string line;
        int flag = 0;
        int q, st;
        while (getline(myfile, line))
        {
            stringstream ss(line);
            string word;
            while (ss >> word)
            {
                v.push_back(word);

            }

            if (v[0] == s)
            {
                cout << "Description: " << v[1] << endl;
                cout << "Price: " << v[2] << endl;
                flag = 1;
                break;

            }
            else
            {
                v.clear();
            }
        }
        if (flag == 0)
        {
            cout << "Item not found." << endl;
        }
        else
        {
            cout << "Enter Quantity: ";
            cin >> q;
            if (q > stoi(v[3]))
            {
                cout << "Insufficient Quantity. " << endl;
            }

            else
            {
                st = q * stoi(v[2]);
                cout << "Total Price: Rs" << st << endl;
            }
        }
        sold.push_back(s);
        sold.push_back(v[1]);
        sold.push_back(to_string(q));
        sold.push_back(to_string(st));
    }
    int endsale()
    {
        int finprice = 0;

        cout << endl;
        cout << "Sales ID: " << saleID << "\t\t\t\t\t" << "CNIC: " << cus.getCNIC() << endl;
        cout << "Date & Time: " << date << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
        cout << "Item SKU" << "\t\t" << "Description" << "\t\t" << "Quantity" << "\t\t" << "Price" << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
        int i = 0, k = 4;
        for (int j = 0; j < (sold.size() / 4); j++) {
            for (i; i < k; ++i)
            {
                cout << sold[i] << "\t\t\t";
            }
            k = k + 4;
            cout << endl;
        }
        cout << endl;
        for (int i = 3; i < sold.size(); i = i + 4)
        {
            finprice = finprice + stoi(sold[i]);
        }
        cout << "---------------------------------------------------------------------------------" << endl;
        cout << "        " << "\t\t" << "           " << "\t\t" << "        " << " Total Price: Rs" << finprice << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
        sales_cust[saleID * 2] = finprice;
        saleID = saleID + 1;
        sold.clear();
        return 1;
    }
    void removeitem()
    {
        int rem;
        vector<string>::iterator ind;
        cout << "please enter item_sku to be removed: ";
        cin >> rem;
        int flag = 0;
        for (ind = sold.begin(); ind != sold.end(); ind = ind + 4) {
            if (rem == stoi(*ind))
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            cout << "item not found..." << endl;
            return;
        }
        else
        {
            sold.erase(ind, ind + 4);
            cout << "item removed..." << endl;
        }

    }
    void cancelsale() {
        sold.clear();
        cout << "sale cancelled" << endl;
    }
    virtual void payment() {}
};


class Receipt : public Sales
{
private:
    float amount;
    int receiptno;
    string receiptdate;

public:
    Receipt()
    {
    }

    Receipt(float amt, int recno, string recdate)
    {
        amount = amt;
        receiptno = recno;
        receiptdate = recdate;
    }
    void makereceipt(int amt, int id, int cnic, int tot, int rem) {
        cout << endl;
        cout << endl;
        cout << " ----------------------------------------" << endl;
        cout << "| SalesID: " << id << "                            |" << endl;
        cout << "|                                       |" << endl;
        cout << "| CNIC:     " << cnic << "                           |" << endl;
        cout << "|                                       |" << endl;
        cout << "| Ammount Pending: " << tot << "                |" << endl;
        cout << "|                                       |" << endl;
        cout << "| Paid: " << amt << "                            |" << endl;
        cout << "|                                       |" << endl;
        cout << "| Remaining balance: " << rem << "              |" << endl;
        cout << "-----------------------------------------" << endl;
        cout << endl;
        cout << endl;
    }

};

class POS :public Sales
{
private:
    Item it;
    Customer cus;
    Receipt rec;

public:
    POS() {
    }
    POS(Item i, Customer cu, Receipt r)
    {
        it = i;
        cus = cu;
        rec = r;
    }
    void payment() override {
        int id;
        int i = 0;
        int paid;
        int flag = 0;
        int rem;
        int CN;
        int tot;
        cout << "enter SalesID: ";
        cin >> id;
        for (i; i < sales_cust.size(); i = i + 3) {
            if (id == sales_cust[i]) {
                CN = sales_cust[i + 1];
                tot = sales_cust[i + 2];
                flag = 1;
                break;
            }
            else if (i == (sales_cust.size() - 1)) {
                break;
            }
        }

        if (flag == 0) {
            cout << "SalesID not found...." << endl;
            return;
        }
        else {
            cout << "customer Payment: ";
            cin >> paid;
            rem = sales_cust[i + 2] - paid;
            sales_cust[i + 2] = rem;
            rec.makereceipt(paid, id, CN, tot, rem);
        }
    }

};



int main()
{
    int option, subOption;
    Sales* sal = new POS();
    int op;

    do {
        cout << "\nMain Menu\n"
            << "1- Manage Items\n"
            << "2- Manage Customers\n"
            << "3- Make New Sale\n"
            << "4- Make Payment\n"
            << "5- Exit\n"
            << "Press 1 to 5 to select an option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            do {
                cout << "\nItems Menu\n"
                    << "1- Add new Item\n"
                    << "2- Update Item details\n"
                    << "3- Find Items\n"
                    << "4- Remove Existing Item\n"
                    << "5- Back to Main Menu\n"
                    << "Press 1 to 5 to select an option: ";
                cin >> subOption;

                Item item;

                switch (subOption)
                {
                case 1:
                {
                    item.additem();
                    break;
                }
                case 2:
                    cout << "\nUpdate Item details\n";
                    item.updateitem();
                    break;
                case 3:
                    cout << "\nFind Items\n";
                    item.finditem();
                    break;
                case 4:
                    cout << "\nRemove Existing Item\n";
                    item.removeitem(" ");
                    break;
                case 5:
                    break;
                default:
                    cout << "\nInvalid option!\n";
                }
            } while (subOption != 5);
            break;

        case 2:
            do {
                cout << "\nCustomers Menu\n"
                    << "1- Add new Customer\n"
                    << "2- Update Customer details\n"
                    << "3- Find Customer\n"
                    << "4- Remove Existing Customer\n"
                    << "5- Back to Main Menu\n"
                    << "Press 1 to 5 to select an option: ";
                cin >> subOption;

                cin.ignore();

                Customer customer;

                switch (subOption)
                {
                case 1:
                    cout << "Add new Customer\n";
                    customer.addCustomer();
                    break;
                case 2:
                    cout << "Update Customer details\n";
                    customer.updateCustomer();
                    break;
                case 3:
                    cout << "Find Customer\n";
                    customer.findCustomer();
                    break;
                case 4:
                    cout << "Remove Existing Customer\n";
                    customer.removecustomer(" ");
                    break;
                case 5:
                    break;
                default:
                    cout << "Invalid option!\n";
                }
            } while (subOption != 5);
            break;

        case 3:
            do
            {
                cout << "Make New Sale\n";

                cout << "Press 1 to Enter New Item\n"
                    << "Press 2 to End Sale\n"
                    << "Press 3 to Remove an existing Item from the current sale\n"
                    << "Press 4 to Cancel Sale\n";
                cin >> subOption;
                switch (subOption)
                {
                case 1:

                    cout << " Enter New Item\n";
                    sal->makenewsale();

                    break;

                case 2:
                    cout << "End Sale\n";
                    op = sal->endsale();
                    if (op == 1) {
                        subOption = 4;
                    }
                    break;

                case 3:
                    cout << "Remove an existing Item from the current sale\n";
                    sal->removeitem();
                    break;
                case 4:
                    cout << "Cancel Sale\n";
                    sal->cancelsale();
                    break;
                default:
                    cout << "Invalid option!\n";
                }

            } while (subOption != 4);
            break;

        case 4:
            cout << "Make Payment\n";
            sal->payment();
            break;

        case 5:
            cout << "Exiting\n";
            break;

        default:
            cout << "Invalid option!\n";
        }
    } while (option != 5);

    return 0;
}
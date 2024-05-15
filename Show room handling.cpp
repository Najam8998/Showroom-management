//Group Memebers : Najam -- Mudasir -- Warisha -- Maheera -- Umaima
//Project Title  : Showroom System 
//------------------------------------------------------------------


//**** Included file to project location*********

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <windows.h>
#include <unordered_map>

using namespace std;

// User structure to store username and password
struct User {
    string username;
    string password;
};

// Map to store users (username -> User)
unordered_map<string,User>userDatabase;

// Function to handle user signup
void signup() {
    User newUser;
    cout << "Enter a username: ";
    cin >> newUser.username;

    // Check if the username already exists
    if (userDatabase.find(newUser.username) != userDatabase.end()) {
        cout << "Username already exists. Please choose a different one.\n";
        return; // Return without completing the signup
    }

    cout << "Enter a password: ";
    cin >> newUser.password;

    // Add the new user to the database
    userDatabase[newUser.username] = newUser;
    cout << "Sign up successful!\n";
}

// Function to handle user login
void login() {
    string enteredUsername, enteredPassword;
    cout << "Enter username: ";
    cin >> enteredUsername;

    // Check if the entered username exists
    auto userIt = userDatabase.find(enteredUsername);
    if (userIt == userDatabase.end()) {
        cout << "Username not found. Please sign up.\n";
        return; // Return without attempting to login
    }

    cout << "Enter password: ";
    cin >> enteredPassword;

    // Check if the entered password is correct
    if (enteredPassword == userIt->second.password) {
        cout << "Login successful!\n";
    } else {
        cout << "Login failed. Incorrect password.\n";
    }
}

// Struct to represent car model 
struct CarModel {
    string name;
    string company;
    string price;
};

// Function prototypes
void displayMenu();
void registerCustomer();
void displayModels();
void displaySpecifications(int modelIndex);
void sellCar();

// File names
const string registrationFileName = "registration.txt";
const string chequeFileName = "Cheque.txt";

int main() {
	
	//Adding Colors to text for better visual presentation
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
   


	
    cout << "\n\t\t\t\t---------------Hi there!------------------\n\n";
    cout << "\t\t\t\t---------- Welcome to Auto Haven ----------\n\n";
    cout << "\t\t\t\t---------- Signup for your account----------\n\n";
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        	
        	
        	case 1: 
			    signup();
        	break;
        	case 2:
        		login();
        		break;
        	case 3:
                displayModels();
                break;
            case 4:
                registerCustomer();
                break;
			case 5:
                sellCar();
                break;
            case 6:
                cout << "\nExiting the showroom system. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 6);
    
    
    //Color Return to total program
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
    
    return 0;
}

void displayMenu() {
	cout << "\n\n1- Signup";
	cout << "\n\n2- Login";
    cout << "\n\n3- Display Models";
    cout << "\n\n4- Registeration form.";
    cout << "\n\n5- Buy Car";
    cout << "\n\n6- Exit\n";
}

void registerCustomer() {
    ofstream registrationFile(registrationFileName, ios::app);

    if (!registrationFile.is_open()) {
        cerr << "Error opening registration file.\n";
        return;
    }

    string name, contactNumber, id_num, car_purchased, car_price;

    cout << "Enter customer name: ";
    cin.ignore();
    getline(cin, name); 

    cout << "Enter contact number: ";
    getline(cin, contactNumber);

    cout << "Enter Id card number: ";
    getline(cin, id_num);

    cout << "Enter purchased car: ";
    getline(cin, car_purchased);

    cout << "Enter purchase year: ";
    getline(cin, car_price);

    registrationFile <<"Name :-"<< name << "\nNumber :-" << contactNumber << "\nId card number :-" << id_num << "\nPurchased car :-" << car_purchased << "\nPurchase year :-" << car_price << "\n";

    cout << "\n\nCustomer registered successfully!\n";

    registrationFile.close();
}

void displayModels() {
    // Modify this section to include your specific companies, models, specifications, and prices
    CarModel models[] = {
        {},
        {"Tesla model 3", "Tesla", "27000000pkr"},
        {"Tesla model X", "Tesla", "28000000pkr"},
        {"Tesla model Y", "Tesla", "28000000pkr"},
        {"Honda Accord 23", "Honda", "4500000pkr"},
        {"Honda CR-V 23", "Honda", "5000000pkr"},
        {"Honda Civic 23", "Honda", "6000000pkr"},
        {"Mercedes Benz GLC", "Mercedes", "50000000pkr"},
        // ... Add more models with their specifications and prices
    };

    const int columnWidth = 30;

    // Display header
    cout << left << setw(columnWidth) << "[Index]" << setw(columnWidth) << "[Company]" << setw(columnWidth) << "[Model]" << setw(columnWidth) << "[Price]" << "\n";

    for (int i = 1; i < sizeof(models) / sizeof(models[0]); ++i) {
        cout << left << setw(columnWidth) << i << setw(columnWidth) << models[i].company << setw(columnWidth) << models[i].name << setw(columnWidth) << models[i].price << "\n";
    }

    int modelIndex;
    cout << "\nEnter model index to view specifications (1-7): ";
    cin >> modelIndex;

    if (modelIndex >= 1 && modelIndex <= sizeof(models) / sizeof(models[0]) - 1) {
        displaySpecifications(modelIndex);
    } else {
        cout << "\n\nInvalid model index.\n";
    }
}

void displaySpecifications(int modelIndex) {
    // Modify this section to include specifications for each model
    string specifications[] = {
        "\n\nPerformance: 0-60 mph times vary by trim, with the Performance model being the quickest.\n\nRange: Varies by model year and configuration, typically over 250 miles per charge.\n\nAutopilot: Advanced driver-assistance features available.\n\nSeating Capacity: 5-7 passengers, depending on configuration.",
        "\n\nPerformance: 0-60 mph in as low as 1.98 seconds (Plaid model).\n\nRange: Varies by model year and configuration, but typically over 300 miles per charge.\n\nAutopilot: Advanced driver-assistance features available.\n\nSeating Capacity: 5-7 passengers, depending on configuration.",
        "\n\nPerformance: 0-60 mph in as low as 1.98 seconds (Plaid model).\n\nRange: Varies by model year and configuration, typically over 300 miles per charge.\n\nAutopilot: Advanced driver-assistance features available.\n\nSeating Capacity: 5-7 passengers, depending on configuration.",
        "\n\nEngine Options: Typically comes with a variety of engines, including turbocharged four-cylinders and hybrid options.\n\nTransmission: Continuously Variable Transmission (CVT) or available manual transmission.\n\nFeatures: Advanced safety features, infotainment system, spacious interior.",
        "\n\nTypically comes with a variety of engines, including turbocharged four-cylinders and hybrid options.\n\nTransmission: Continuously Variable Transmission (CVT) or available manual transmission.\n\nFeatures: Advanced safety features, infotainment system, spacious interior.",
        "\n\nEngine Options: Various options, including turbocharged four-cylinders.\n\nTransmission: Manual or Continuously Variable Transmission (CVT).\n\nBody Styles: Sedan, coupe, and hatchback options.\n\nFeatures: Efficient and reliable, modern styling, advanced safety features.",
        "\n\nEngine Options: Various engine options, including turbocharged inline-4 and V6 options.\n\nTransmission: 9-speed automatic transmission.\n\nDrivetrain: Rear-wheel drive (RWD) or 4MATIC all-wheel drive.\n\nBody Styles: Sedan, Coupe, Cabriolet.\n\nFeatures: Advanced safety features, luxurious interior, advanced infotainment system.\n\nSeating Capacity: 5-7 passengers, depending on configuration."
        
    };

    cout << "\nSpecifications for the selected model:\n";
    cout << specifications[modelIndex - 1] << "\n";
}

void sellCar() {
	
	cout<<"--------------------------------------------------------------------------"<<endl;
	cout<<"Our Company give cars in cheque and through loan\n\nChoose what suits you...";
	cout<<"\n--------------------------------------------------------------------------"<<endl;
	
	int a;
	cout<<"1 => For Cheque :- \n\n";
	cout<<"2 => For Loan\n\n";
	cout<<"Plz select :-";
	cin>>a;

	
	//Validating paymemt methods
	
	if(a==1)
	 
	 { 
	 
	cout<<"\n\nFill the form kindly..\n\n";
	   ofstream chequeFile(chequeFileName, ios::app);

    if (!chequeFile.is_open()) {
        cerr << "Error opening registration file.\n";
        return;
    }

    string name, contactNumber, Iban_number, id_num, car_purchased, car_price;

    cout << "Enter customer name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter contact number: ";
    getline(cin, contactNumber);

    cout << "Enter Id card number: ";
    getline(cin, id_num);
    
    cout << "Enter Iban number: ";
    getline(cin, Iban_number);

    cout << "Enter purchased car: ";
    getline(cin, car_purchased);

    cout << "Enter car price: ";
    getline(cin, car_price);

    chequeFile <<"Name :-"<< name << "\nNumber :-" << contactNumber << "\nId card number :-" << id_num << "\nIban number :-" << Iban_number <<"\nPurchased car :-" << car_purchased << "Car price :-" << car_price << "\n";


    chequeFile.close();
    
    cout <<"\n---------------------";
    cout <<"\nPayment done.";
    cout <<"Enjoy your Car sir!\n";
    cout <<"\n-----------------------";
    
}else if(a==2){
	
  // Constants
    const double annualInterestRate = 0.05; // 5% annual interest rate
    const int monthsInYear = 12;

    // Variables to store user input
    double loanAmount, totalAmount, monthlyPayment;
    int loanDuration;

    // Get user input
    cout<<"-----------------------------------\n";
    cout << "Enter car price in numbers : pkr";
    cin >> loanAmount;

    cout << "\n\nEnter loan duration in years: ";
    cin >> loanDuration;
    

    // Calculate total amount to be repaid
    totalAmount = loanAmount * (1 + annualInterestRate * loanDuration);

    // Calculate monthly interest rate and total number of payments
    double monthlyInterestRate = annualInterestRate / monthsInYear;
    int totalPayments = loanDuration * monthsInYear;

    // Calculate monthly payment using the formula
    monthlyPayment = (loanAmount * monthlyInterestRate) /
    (1 - pow(1 + monthlyInterestRate, -totalPayments));

    // Display the loan details
    cout <<"\n-------------------------------------"; 
    cout << "\nLoan Details:\n\n";
    cout << "\nLoan Amount: pkr" << loanAmount << endl;
    cout << "\nAnnual Interest Rate: " << (annualInterestRate * 100) << "%\n";
    cout << "\nLoan Duration: " << loanDuration << " years\n";
    cout << "\nTotal Amount to be Repaid: pkr" << totalAmount << endl;
    cout << "\nMonthly Installment: pkr" << monthlyPayment << endl;
    cout <<"\n------------------------------------";
    
    cout <<"\nEnjoy your Car sir!\n";
    cout<<"---------------------------------------";
	}else
	{
	cout<<"\n\nOther Payment's not accepted. Thanks.";
	}
}
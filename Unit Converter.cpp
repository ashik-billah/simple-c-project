#include <iostream>
using namespace std;

// Function declarations
void lengthConverter();
void weightConverter();
void temperatureConverter();
void menu();

int main() {
    menu();
    return 0;
}

// Main menu
void menu() {
    int choice;

    do {
        cout << "\n=== Unit Converter ===\n";
        cout << "1. Length Converter\n";
        cout << "2. Weight Converter\n";
        cout << "3. Temperature Converter\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch(choice) {
            case 1: lengthConverter(); break;
            case 2: weightConverter(); break;
            case 3: temperatureConverter(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 4);
}

// Length Converter
void lengthConverter() {
    int option;
    double value;

    cout << "\n--- Length Converter ---\n";
    cout << "1. Meters to Kilometers\n";
    cout << "2. Kilometers to Miles\n";
    cout << "3. Miles to Meters\n";
    cout << "Choose an option: ";
    cin >> option;

    cout << "Enter value: ";
    cin >> value;

    switch(option) {
        case 1: cout << value << " meters = " << value / 1000 << " kilometers\n"; break;
        case 2: cout << value << " kilometers = " << value * 0.621371 << " miles\n"; break;
        case 3: cout << value << " miles = " << value * 1609.34 << " meters\n"; break;
        default: cout << "Invalid option!\n";
    }
}

// Weight Converter
void weightConverter() {
    int option;
    double value;

    cout << "\n--- Weight Converter ---\n";
    cout << "1. Grams to Kilograms\n";
    cout << "2. Kilograms to Pounds\n";
    cout << "3. Pounds to Grams\n";
    cout << "Choose an option: ";
    cin >> option;

    cout << "Enter value: ";
    cin >> value;

    switch(option) {
        case 1: cout << value << " grams = " << value / 1000 << " kilograms\n"; break;
        case 2: cout << value << " kilograms = " << value * 2.20462 << " pounds\n"; break;
        case 3: cout << value << " pounds = " << value * 453.592 << " grams\n"; break;
        default: cout << "Invalid option!\n";
    }
}

// Temperature Converter
void temperatureConverter() {
    int option;
    double temp;

    cout << "\n--- Temperature Converter ---\n";
    cout << "1. Celsius to Fahrenheit\n";
    cout << "2. Fahrenheit to Kelvin\n";
    cout << "3. Kelvin to Celsius\n";
    cout << "Choose an option: ";
    cin >> option;

    cout << "Enter temperature: ";
    cin >> temp;

    switch(option) {
        case 1: cout << temp << "°C = " << (temp * 9/5) + 32 << "°F\n"; break;
        case 2: cout << temp << "°F = " << ((temp - 32) * 5/9) + 273.15 << " K\n"; break;
        case 3: cout << temp << " K = " << temp - 273.15 << "°C\n"; break;
        default: cout << "Invalid option!\n";
    }
}

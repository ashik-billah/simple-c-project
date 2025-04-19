#include <iostream>
#include <ctime>

using namespace std;

int main() {
    int birthYear, birthMonth, birthDay;

    cout << "===== Age Calculator =====\n";
    cout << "Enter your birth year (e.g., 2000): ";
    cin >> birthYear;
    cout << "Enter your birth month (1-12): ";
    cin >> birthMonth;
    cout << "Enter your birth day (1-31): ";
    cin >> birthDay;

    // Get current date
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int currentYear = 1900 + ltm->tm_year;
    int currentMonth = 1 + ltm->tm_mon;
    int currentDay = ltm->tm_mday;

    int ageYears = currentYear - birthYear;
    int ageMonths = currentMonth - birthMonth;
    int ageDays = currentDay - birthDay;

    if (ageDays < 0) {
        ageDays += 30;
        ageMonths--;
    }
    if (ageMonths < 0) {
        ageMonths += 12;
        ageYears--;
    }

    cout << "\nYou are " << ageYears << " years, " << ageMonths << " months, and " << ageDays << " days old.\n";

    return 0;
}

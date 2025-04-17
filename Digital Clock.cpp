#include <iostream>
#include <iomanip>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

void showClock() {
    while (true) {
        // Get current time
        time_t now = time(0);
        tm* currentTime = localtime(&now);

        // Clear the console screen
        system("CLS");

        // Display the time in HH:MM:SS format
        cout << setw(2) << setfill('0') << currentTime->tm_hour << ":"
             << setw(2) << setfill('0') << currentTime->tm_min << ":"
             << setw(2) << setfill('0') << currentTime->tm_sec << endl;

        // Wait for 1 second
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main() {
    showClock();
    return 0;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Train {
private:
    string trainNumber;
    int totalSeats;
    vector<bool> seats;

public:
    Train(string number, int seats) : trainNumber(number), totalSeats(seats) {
        // Initialize all seats as available (false)
        this->seats = vector<bool>(seats, false);
    }

    string getTrainNumber() {
        return trainNumber;
    }

    int getTotalSeats() {
        return totalSeats;
    }

    int getAvailableSeats() {
        int count = 0;
        for (bool seat : seats) {
            if (!seat)
                count++;
        }
        return count;
    }

    bool reserveSeat(int seatNumber) {
        if (seatNumber < 1 || seatNumber > totalSeats) {
            cout << "Invalid seat number!" << endl;
            return false;
        }

        if (seats[seatNumber - 1]) {
            cout << "Seat " << seatNumber << " is already reserved." << endl;
            return false;
        }

        seats[seatNumber - 1] = true;
        cout << "Seat " << seatNumber << " reserved successfully." << endl;
        return true;
    }
};

int main() {
    Train train("12345", 50);
    int choice, seatNumber;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Check available seats" << endl;
        cout << "2. Reserve a seat" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Available seats: " << train.getAvailableSeats() << endl;
                break;
            case 2:
                cout << "Enter seat number: ";
                cin >> seatNumber;
                train.reserveSeat(seatNumber);
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }

        cout << endl;
    }

    return 0;
}
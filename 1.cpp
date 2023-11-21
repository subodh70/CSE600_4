#include <bits/stdc++.h>

class Vehicle {
public:
    std::string vehicleName;
    std::string vehicleNumber;
    std::string firstName;
    std::string lastName;
    int age;
    char gender;
    std::string address;

    Vehicle(const std::string& name, const std::string& number, const std::string& first, const std::string& last, int a, char g, const std::string& addr)
        : vehicleName(name), vehicleNumber(number), firstName(first), lastName(last), age(a), gender(g), address(addr) {}

    void display() const {
        std::cout << "Vehicle Name: " << vehicleName << "\n"
                  << "Vehicle Number: " << vehicleNumber << "\n"
                  << "Owner: " << firstName << " " << lastName << "\n"
                  << "Age: " << age << "\n"
                  << "Gender: " << gender << "\n"
                  << "Address: " << address << "\n\n";
    }
};

class VehicleList {
public:
    std::vector<Vehicle> vehicles;

    void addVehicle(const Vehicle& vehicle) {
        vehicles.push_back(vehicle);
    }

    void deleteVehicle(const std::string& vehicleNumber) {
    vehicles.erase(
        std::remove_if(vehicles.begin(), vehicles.end(), [&vehicleNumber](const Vehicle& v) {
            return v.vehicleNumber == vehicleNumber;
        }),
        vehicles.end()
    );
}


    void displayAllVehicles() const {
        for (const auto& vehicle : vehicles) {
            vehicle.display();
        }
    }

    void readFromCSV(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;

        while (std::getline(file, line)) {
            std::istringstream ss(line);
            std::string name, number, first, last, address;
            int age;
            char gender;

            std::getline(ss, name, ',');
            std::getline(ss, number, ',');
            std::getline(ss, first, ',');
            std::getline(ss, last, ',');
            ss >> age;
            ss.ignore(); // Ignore the comma
            ss >> gender;
            ss.ignore(); // Ignore the comma

            // Explicitly remove the newline character from the gender column
            if (ss.peek() == '\r') ss.ignore();
            if (ss.peek() == '\n') ss.ignore();

            // Read the address column
            std::getline(ss, address);

            Vehicle vehicle(name, number, first, last, age, gender, address);
            addVehicle(vehicle);
        }
    }
};

void printMenu() {
    std::cout << "1. Add Entry\n"
              << "2. Delete Entry\n"
              << "3. Display All Entries\n"
              << "4. Quit\n";
}

int main() {
    VehicleList vehicleList;

    // Replace "1.csv" with the actual filename
    vehicleList.readFromCSV("1.csv");

    int choice;
    std::string vehicleNumber;

    do {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Consume the newline character

        switch (choice) {
            case 1: {
                // Add Entry
                std::string name, number, first, last, address;
                int age;
                char gender;

                std::cout << "Enter Vehicle Name: ";
                std::getline(std::cin, name);

                std::cout << "Enter Vehicle Number: ";
                std::getline(std::cin, number);

                std::cout << "Enter Owner's First Name: ";
                std::getline(std::cin, first);

                std::cout << "Enter Owner's Last Name: ";
                std::getline(std::cin, last);

                std::cout << "Enter Owner's Age: ";
                std::cin >> age;
                std::cout << "Enter Owner's Gender (M/F): ";
                std::cin >> gender;
                std::cin.ignore(); // Consume the newline character

                std::cout << "Enter Owner's Address: ";
                std::getline(std::cin, address);

                Vehicle newVehicle(name, number, first, last, age, gender, address);
                vehicleList.addVehicle(newVehicle);
                std::cout << "Entry added successfully.\n";
                break;
            }
            case 2: {
                // Delete Entry
                std::cout << "Enter Vehicle Number to delete: ";
                std::getline(std::cin, vehicleNumber);
                vehicleList.deleteVehicle(vehicleNumber);
                std::cout << "Entry deleted successfully.\n";
                break;
            }
            case 3:
                // Display All Entries
                std::cout << "List of Vehicles:\n";
                vehicleList.displayAllVehicles();
                break;
            case 4:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 4);

    return 0;
}

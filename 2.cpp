#include <bits/stdc++.h>

class TrafficViolation {
private:
    std::string carNumber;
    std::string reportType;
    std::string reportLocation;

public:
    TrafficViolation(const std::string& carNumber, const std::string& reportType, const std::string& reportLocation)
        : carNumber(carNumber), reportType(reportType), reportLocation(reportLocation) {}

    // Getters
    std::string getCarNumber() const { return carNumber; }
    std::string getReportType() const { return reportType; }
    std::string getReportLocation() const { return reportLocation; }

    // Setters
    void setCarNumber(const std::string& newCarNumber) { carNumber = newCarNumber; }
    void setReportType(const std::string& newReportType) { reportType = newReportType; }
    void setReportLocation(const std::string& newReportLocation) { reportLocation = newReportLocation; }

    // Display violation data
    void displayViolation() const {
        std::cout << "Car Number: " << carNumber << "\nReport Type: " << reportType << "\nReport Location: " << reportLocation << "\n";
    }
};

class TrafficViolationDatabase {
private:
    std::vector<TrafficViolation> violations;

public:
    // Read data from CSV file
    void readCSV(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << "\n";
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string carNumber, reportType, reportLocation;
            std::getline(iss, carNumber, ',');
            std::getline(iss, reportType, ',');
            std::getline(iss, reportLocation);

            violations.emplace_back(carNumber, reportType, reportLocation);
        }

        file.close();
    }

    // Display all violations
    void displayAllViolations() const {
        for (const auto& violation : violations) {
            violation.displayViolation();
            std::cout << "------------------------\n";
        }
    }

    // Add a new violation
    void addViolation(const TrafficViolation& newViolation) {
        violations.push_back(newViolation);
    }

    // Delete a violation based on car number
    void deleteViolation(const std::string& carNumber) {
        violations.erase(std::remove_if(violations.begin(), violations.end(),
            [carNumber](const TrafficViolation& violation) { return violation.getCarNumber() == carNumber; }),
            violations.end());
    }

    // Edit a violation based on car number
    void editViolation(const std::string& carNumber, const TrafficViolation& editedViolation) {
        for (auto& violation : violations) {
            if (violation.getCarNumber() == carNumber) {
                violation = editedViolation;
                break;
            }
        }
    }
};

int main() {
    TrafficViolationDatabase database;

    // Read initial data from CSV
    database.readCSV("2.csv");

    int choice;
    do {
        std::cout << "Menu:\n1. Display Violations data\n2. Add new Violation\n3. Delete Violation\n4. Edit Violation\n5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            database.displayAllViolations();
            break;
        case 2: {
            std::string carNumber, reportType, reportLocation;
            std::cout << "Enter Car Number (format DJ,597493): ";
            std::cin.ignore();  // Ignore newline character from previous input
            std::getline(std::cin, carNumber);
            std::cout << "Enter Report Type: ";
            std::getline(std::cin, reportType);
            std::cout << "Enter Report Location: ";
            std::getline(std::cin, reportLocation);

            database.addViolation(TrafficViolation(carNumber, reportType, reportLocation));
            break;
        }
        case 3: {
            std::string carNumber;
            std::cout << "Enter Car Number to delete: ";
            std::cin >> carNumber;

            database.deleteViolation(carNumber);
            break;
        }
        case 4: {
            std::string carNumber, newCarNumber, reportType, reportLocation;
            std::cout << "Enter Car Number to edit: ";
            std::cin >> carNumber;

            std::cout << "Enter new Car Number (format DJ,597493): ";
            std::cin.ignore();  // Ignore newline character from previous input
            std::getline(std::cin, newCarNumber);
            std::cout << "Enter new Report Type: ";
            std::getline(std::cin, reportType);
            std::cout << "Enter new Report Location: ";
            std::getline(std::cin, reportLocation);

            database.editViolation(carNumber, TrafficViolation(newCarNumber, reportType, reportLocation));
            break;
        }
        case 5:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }

    } while (choice != 5);

    return 0;
}

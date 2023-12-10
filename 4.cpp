#include <iostream>
#include <vector>

// Forward declaration of ViolatorRecord
class ViolatorRecord;

class Person {
public:
    std::string firstName;
    std::string lastName;
    int age;
    std::string gender;
    std::string address;

    // Additional member functions or data as needed
};

class Violation {
public:
    std::string violationDetails;
    // Additional member functions or data as needed
};

class Witness {
public:
    std::string witnessName;
    std::string witnessContact;
    // Additional member functions or data as needed
};

class ChallengeResponse {
public:
    std::string responseText;
    std::vector<ViolatorRecord> priorRecords; // Using the forward declaration

    // Additional member functions or data as needed
};

class ViolatorRecord {
public:
    Person violator;
    std::vector<Witness> witnesses;
    Violation violationDetails;
    ChallengeResponse challengeResponse;

    // Additional member functions or data as needed

    // Member function to display the data
    void display() const {
        std::cout << "Violator: " << violator.firstName << " " << violator.lastName << "\n";
        std::cout << "Age: " << violator.age << "\n";
        std::cout << "Gender: " << violator.gender << "\n";
        std::cout << "Address: " << violator.address << "\n";

        std::cout << "Violation Details: " << violationDetails.violationDetails << "\n";

        std::cout << "Witnesses:\n";
        for (const auto& witness : witnesses) {
            std::cout << "Name: " << witness.witnessName << ", Contact: " << witness.witnessContact << "\n";
        }

        std::cout << "Challenge Response: " << challengeResponse.responseText << "\n";

        std::cout << "Prior Records:\n";
        for (const auto& priorRecord : challengeResponse.priorRecords) {
            priorRecord.display(); // Assuming ViolatorRecord has a display member function
        }

        std::cout << "\n";
    }
};

// Usage example
int main() {
    // Create an instance of ViolatorRecord
    ViolatorRecord violatorRecord;

    // Populate the data
    violatorRecord.violator.firstName = "John";
    violatorRecord.violator.lastName = "Doe";
    violatorRecord.violator.age = 30;
    violatorRecord.violator.gender = "Male";
    violatorRecord.violator.address = "123 Main St.";

    violatorRecord.violationDetails.violationDetails = "Speeding";

    Witness witness1;
    witness1.witnessName = "Alice";
    witness1.witnessContact = "123-456-7890";

    Witness witness2;
    witness2.witnessName = "Bob";
    witness2.witnessContact = "987-654-3210";

    violatorRecord.witnesses.push_back(witness1);
    violatorRecord.witnesses.push_back(witness2);

    ChallengeResponse response;
    response.responseText = "Challenging the violation.";

    // Assume you have a prior record stored in another ViolatorRecord instance
    ViolatorRecord priorRecord;
    // Populate priorRecord data

    response.priorRecords.push_back(priorRecord);

    violatorRecord.challengeResponse = response;

    // Display the data
    violatorRecord.display();

    return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Person {
    string firstName;
    string lastName;
    int age;
    string gender;
    string address;
};

int main() {
    vector<Person> people;

    ifstream file("3.csv");
    if (!file.is_open()) {
        cerr << "Error while opening file\n";
        return 1; // Exit with an error code
    }

    string line;
    getline(file, line); // Skip header line
    while (getline(file, line)) {
        Person person;
        stringstream ss(line);
        getline(ss, person.firstName, ',');
        getline(ss, person.lastName, ',');
        ss >> person.age;  // Assuming age is directly followed by a comma
        getline(ss, person.gender, ',');
        getline(ss, person.address, ',');

        people.push_back(person);
    }

    file.close();

    cout << "Displaying the data:\n";
    for (const auto& person : people) {
        cout << "First Name: " << person.firstName << "\n"
             << "Last Name: " << person.lastName << "\n"
             << "Age: " << person.age << "\n"
             << "Gender: " << person.gender << "\n"
             << "Address: " << person.address << "\n\n";
    }

    return 0;
}

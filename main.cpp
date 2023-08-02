#include <iostream>
#include <fstream>
#include <sstream>
#include "Bplus_tree.cpp"
#include "Hash_table.cpp"
#include "Person.cpp"

using namespace std;



int main() {
    vector<Person> people;
    void LoadData(vector<Person>& people);
    LoadData(people);
    for(int i = 0; i < people.size(); i++){
        people[i].PrintInfo();
    }

    return 0;
}

void LoadData(vector<Person>& output){
    ifstream csv("temp_data.csv");
        if (csv.is_open()) {
            string line;
            getline(csv, line);// Get rid of the header line.
            while (getline(csv, line)) {
                istringstream stream(line);
                Person person;
                person.Deserialize(stream);
                output.push_back(person);
            }
        }
        else {
            cout << "Error! File couldn't open.";
        }
}

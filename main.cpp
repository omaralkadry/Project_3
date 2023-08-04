#include <iostream>
#include <fstream>
#include <sstream>
#include "Bplus_tree.cpp"
#include "Hash_table.cpp"
using namespace std;

void LoadData(string& file, BPlusTree& tree, HashTable& table);

int main() {

    string filename = "temp_data.csv";
    BPlusTree Tree;
    HashTable Table;

    LoadData(filename, Tree, Table);

    string input = "0";

    while (input != "3") {
        cout << "Menu:" << endl;
        cout << "1. Search by zipcode" << endl;
        cout << "2. Empty Option" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter selection: (1,2 or 3)" << endl;
        cin >> input;

        if (input == "1") {
            int zipcode;
            cout << "Enter zipcode to search for: " << endl;
            cin >> zipcode;
            Tree.search(zipcode);
        }
        else if (input == "2") {
            cout << "Empty Option" << endl;
        }
        else if (input == "3") {
            cout << "Thank you for using the Meghan's Law Program" << endl;
        }
        else {
            cout << "Invalid Selection" << endl;
        }

    }
    return 0;
}

void LoadData(string& file, BPlusTree& tree, HashTable& table)
{
    ifstream inFile(file);
    if (inFile.is_open()) {

        string line;
        getline(inFile, line); // Get rid of the header line.
        while(getline(inFile, line)) {
            istringstream stream_line(line);
            string name;
            string address;
            string city;
            string state;
            string zipcode;
            string county;

            getline(stream_line, name, ',');
            getline(stream_line, address, ',');
            getline(stream_line, city, ',');
            getline(stream_line, state, ',');
            getline(stream_line, zipcode, ',');
            getline(stream_line, county, ',');

            tree.insert(stoi(zipcode), name, address);
            table.insert(stoi(zipcode), name, address);
        }
    }
    else {
        cout << "Error! File couldn't open.";
    }
}
/*
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
 */
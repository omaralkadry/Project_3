#include <iostream>
#include <fstream>
#include <sstream>
#include "Bplus_tree.cpp"
//#include "Hash_table.cpp"
using namespace std;

void LoadData(string& file, BPlusTree& tree);

int main() {

    string filename = "temp_data.csv";
    BPlusTree Tree;

    LoadData(filename,Tree);

    Tree.search(32244);

    return 0;
}

void LoadData(string& file, BPlusTree& tree)
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

            tree.insert(stoi(zipcode),name,address);
            // insert into hash table here
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
#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>

using namespace std;

class Person {
    vector<string> names;  //Do not use
    vector<string> addresses;   //Do not use
    vector <pair<string,string>> data;
    string name;
    string address;
    string city;
    string state;
    int zipcode;
    string county;
public:
    Person();
    Person(int zipcode);
    vector<string> Get_names();
    vector<string> Get_addresses();
    int Get_zipcode();
    void Add_offender(const string& name,const string& address);
    void Deserialize(istringstream& stream);
    void PrintInfo();
};
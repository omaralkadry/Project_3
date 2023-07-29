//
// Created by omara on 7/29/2023.
//
using namespace std;

class Offender {
public:
    string name;
    string address;
    int zipcode;
    Offender(string name, string address, int zipcode);
    string Get_name() const;
    string Get_address() const;
    int Get_zipcode() const;
};

Offender::Offender(string name, string address, int zipcode)
{
    this->name = name;
    this->address = address;
    this->zipcode = zipcode;
}

string Offender::Get_name() const
{
    return this->name;
}

string Offender::Get_address() const
{
    return this->address;
}

int Offender::Get_zipcode() const
{
    return this->zipcode;
}

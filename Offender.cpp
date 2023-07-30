//
// Created by omar on 7/29/2023.
//
using namespace std;

class Offender {
    vector<string> names;
    vector<string> addresses;
    int zipcode;
public:
    Offender();
    Offender(int zipcode);
    vector<string> Get_names() const;
    vector<string> Get_addresses() const;
    int Get_zipcode() const;
    void Add_offender(const string& name, const string& address);
};

Offender::Offender()
{
    this->zipcode = -1;
}

Offender::Offender(int zipcode)
{
    this->zipcode = zipcode;
}

vector<string> Offender::Get_names() const
{
    return this->names;
}

vector<string> Offender::Get_addresses() const
{
    return this->addresses;
}

int Offender::Get_zipcode() const
{
    return this->zipcode;
}

void Offender::Add_offender(const string &name, const string &address)
{
    this->names.push_back(name);
    this->addresses.push_back(address);
}

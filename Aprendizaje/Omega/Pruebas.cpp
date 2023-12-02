
#include <iostream>

using namespace std;


class personType {
private:
    string firstName;
    string lastName;

public:
    void print() const;
    void setName(string first , string last);
    string getFirstName() const;
    string getLastName() const;
    personType();
    personType(string first, string last);
};

void personType::print() const{
	cout << "Name: " << firstName << " " << lastName << endl;
}

void personType::setName(string first, string last){
    firstName = first;
    lastName = last;
}

string personType::getFirstName() const{
    return firstName;
}

string personType::getLastName() const{
    return lastName;
}

personType::personType() {

    firstName = "";
	lastName = "";
}

personType::personType(string first, string last){
    setName(first,last);

}

int main() {
    personType person1;
    person1.setName("Angela", "Castillo");
    person1.print();


    personType person2("Josue", "Lopez");
    person2.print();

    return 0;
}

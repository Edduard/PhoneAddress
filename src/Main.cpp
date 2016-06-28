#include"AddressBook.h"
#include"Entry.h"
#include<iostream>
using namespace std;

int main(){
    AddressBook a;
    Entry e1("Alexander", "0787878787");
    Entry e2;
    Entry e3("George", "0747474747");

    e2.setName("John");
    e2.setPhoneNumber("0727272727");

    a.addEntry(&e1);
    a.addEntry(&e2);
    a.removeEntry(&e2);
    a.displayPhoneBook();
    a.addEntry(&e2);
    a.addEntry(&e3);
    cout<<"\nBefore ordering\n";
    a.displayPhoneBook();
    cout<<"\nAfter ordering\n";
    a.sortAddressBook();

    return 0;
}

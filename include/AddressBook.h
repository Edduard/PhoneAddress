#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include "Entry.h"

class AddressBook
{
    Entry* lastEntry;
    Entry* firstEntry;
    int length;

    public:
        AddressBook();
        virtual ~AddressBook();

        Entry* getLastEntry();
        Entry* getFirstEntry();

        void setLength(int);
        int getLength();

        void addEntry(Entry*);
        void removeEntry(Entry*);
        Entry* retrieveEntry(Entry*);

        void sortAddressBook();

        void displayPhoneBook();

    protected:

    private:
};

#endif // ADDRESSBOOK_H

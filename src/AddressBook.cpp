#include "AddressBook.h"
#include <cstddef>
#include <iostream>
using namespace std;

AddressBook::AddressBook()
{
    this->length = 0;
    this->firstEntry = NULL;
    this->lastEntry = NULL;
}

Entry* AddressBook::getLastEntry(){
    return this->lastEntry;
}

Entry* AddressBook::getFirstEntry(){
    return this->firstEntry;
}

int AddressBook::getLength(){
    return this->length;
}

void AddressBook::setLength(int newLength){
    this->length = newLength;
}

void AddressBook::addEntry(Entry* newEntry){
    // If I have a populated list
    if (this->lastEntry != NULL){
        this->lastEntry->setNextEntry(newEntry);
        this->lastEntry = newEntry;
    }
    // If my list is empty
    else{
        this->lastEntry = newEntry;
        this->firstEntry = newEntry;
    }
    this->setLength(this->getLength()+1);
}

void AddressBook::removeEntry(Entry* entry){
    if( this-> getLength() > 1 ) {
        Entry* tempEntry = this->getFirstEntry();
        while(tempEntry->getNextEntry()->getNextEntry() != NULL ){                  // While I'm not -,-,- ... -,t,-
            if ((strcmp(tempEntry->getNextEntry()->getName(), entry->getName())==0)
                && (strcmp(tempEntry->getNextEntry()->getPhoneNumber(), entry->getPhoneNumber())==0)){   // When I find the entry I'm looking for
                tempEntry->setNextEntry(tempEntry->getNextEntry()->getNextEntry());  // Put the next entry as the next next one
                this->setLength(this->getLength()-1);
                entry->setNextEntry(NULL);
            }
            tempEntry = tempEntry->getNextEntry();
        }
     // If I am here -,-,-, ... -,t,-
        if (strcmp(tempEntry->getNextEntry()->getName(), entry->getName())==0){
                tempEntry->setNextEntry(NULL);
                this->setLength(this->getLength()-1);
                entry->setNextEntry(NULL);
                this->lastEntry = tempEntry;
            }
    // If I want to remove the first element
        if (strcmp(entry->getName(), this->getFirstEntry()->getName())==0){
            this->firstEntry = this->firstEntry->getNextEntry();
            this->setLength(this->getLength()-1);
            entry->setNextEntry(NULL);
        }
    }
    else
    // If I only have 1 element left
        if (this->getLength() == 1){
            entry->setNextEntry(NULL);
            this->firstEntry = NULL;
            this->lastEntry = NULL;
            this->setLength(0);
        }
    // If the list is empty
        else
            cout<<"Phone Book is empty!\n";

}

void AddressBook::displayPhoneBook(){
    if(this->getLength() == 0 )
        cout<<"\nThe phone book is empty!";
    else{
        Entry* tempEntry = this->firstEntry;
        while(tempEntry->getNextEntry() != NULL ){
            tempEntry->displayEntry();
            tempEntry = tempEntry->getNextEntry();
        }
        /// For the last element
        tempEntry->displayEntry();
    }
}

Entry* AddressBook::retrieveEntry(Entry* entry){
    Entry* tempEntry = this->getFirstEntry();
    while(tempEntry->getNextEntry() != NULL ){                    // Until the last element
        if ((strcmp(tempEntry->getNextEntry()->getName(), entry->getName())==0)
                && (strcmp(tempEntry->getNextEntry()->getPhoneNumber(), entry->getPhoneNumber())==0)) {   // When I find the entry I'm looking for
            return tempEntry;
        }
        tempEntry = tempEntry->getNextEntry();
    }
    if ((strcmp(tempEntry->getName(), entry->getName())==0)                             // For the last element
                && (strcmp(tempEntry->getPhoneNumber(), entry->getPhoneNumber())==0))
        return tempEntry;
    return NULL;
}

void AddressBook::sortAddressBook(){
    Entry *tempEntry1, *tempEntry2, auxEntry;
    bool sorted = 0;
    while (sorted == 0){
            tempEntry1 = this->firstEntry;
            sorted = 1;
        if(this->getLength() > 3){
            while( tempEntry1->getNextEntry()->getNextEntry()->getNextEntry() != NULL){
                // For the first 2 items
                if( (tempEntry1 == firstEntry) && (strcmp(tempEntry1->getName(), tempEntry1->getNextEntry()->getName()) > 0)){
                    auxEntry = *tempEntry1->getNextEntry()->getNextEntry();
                    this->firstEntry = tempEntry1->getNextEntry();
                    this->firstEntry->setNextEntry(tempEntry1);
                    tempEntry1->setNextEntry(&auxEntry);
                    sorted = 0;
                }
                    /// if temp3.val < temp2.val
                if(strcmp(tempEntry1->getNextEntry()->getNextEntry()->getName(),
                tempEntry1->getNextEntry()->getName()) < 0){
                        auxEntry = *tempEntry1->getNextEntry()->getNextEntry()->getNextEntry();
                        tempEntry1->getNextEntry()->getNextEntry()->setNextEntry(tempEntry1->getNextEntry());
                        tempEntry1->setNextEntry(tempEntry1->getNextEntry()->getNextEntry());
                        tempEntry1->getNextEntry()->getNextEntry()->setNextEntry(&auxEntry);
                        sorted = 0;
                }
                tempEntry1->setNextEntry(tempEntry1->getNextEntry());
            }
        }
        tempEntry1 = this->firstEntry;
        ///if   t1.next.next.next == null & t3<t2
        if ( this->getLength() == 3
            && tempEntry1->getNextEntry()->getNextEntry()->getNextEntry() == NULL) {
                // For the first 2 items
                if( strcmp(tempEntry1->getName(), tempEntry1->getNextEntry()->getName()) > 0){
                    auxEntry = *tempEntry1->getNextEntry()->getNextEntry();
                    this->firstEntry = tempEntry1->getNextEntry();
                    this->firstEntry->setNextEntry(tempEntry1);
                    tempEntry1->setNextEntry(&auxEntry);
                    sorted = 0;
                }
                tempEntry1 = this->firstEntry;
                if (strcmp(tempEntry1->getNextEntry()->getName(), tempEntry1->getNextEntry()->getNextEntry()->getName()) > 0){
                    tempEntry1->getNextEntry()->getNextEntry()->setNextEntry(tempEntry1->getNextEntry());
                    tempEntry1->setNextEntry(tempEntry1->getNextEntry()->getNextEntry());
                    tempEntry1->getNextEntry()->getNextEntry()->setNextEntry(NULL);
                    this->lastEntry = tempEntry1->getNextEntry();
                    this->firstEntry = tempEntry1;
                    sorted = 0;
                    }
                }

        tempEntry1 = this->firstEntry;

        if ( this->getLength() == 2
            && tempEntry1->getNextEntry()->getNextEntry() == NULL
            && (strcmp(tempEntry1->getNextEntry()->getName(),
            tempEntry1->getName() ) >= 1) ){
                tempEntry1->getNextEntry()->setNextEntry(tempEntry1);
                this->firstEntry = tempEntry1->getNextEntry();
                tempEntry1->setNextEntry(NULL);
                this->lastEntry = this->firstEntry->getNextEntry();
                sorted = 0;
            }
    }
    firstEntry->displayEntry();
    firstEntry->getNextEntry()->displayEntry();
    firstEntry->getNextEntry()->getNextEntry()->displayEntry();
    cout<<"\nThe Address Book has been sorted!";
}

AddressBook::~AddressBook()
{
    //dtor
}

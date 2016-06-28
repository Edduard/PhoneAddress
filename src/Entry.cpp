#include "Entry.h"
#include <iostream>
using namespace std;

Entry::Entry(){
    this->name = new char[1];
    this->phoneNumber = new char[1];
    strcpy(this->name, "-");
    strcpy(this->phoneNumber, "-");
    this->nextEntry = NULL;
}

Entry::Entry(char* newName, char* newPhoneNumber){
    this->name = new char[strlen(newName)];
    this->phoneNumber = new char[strlen(newPhoneNumber)];
    strcpy(this->name, newName);
    strcpy(this->phoneNumber, newPhoneNumber);
    this->nextEntry = NULL;
    }

Entry::Entry(char* newName, char* newPhoneNumber, Entry* newNextEntry){
    this->name = new char[strlen(newName)];
    strcpy(this->name, newName);
    strcpy(this->phoneNumber, newPhoneNumber);
    this->nextEntry = newNextEntry;
    }

char* Entry::getPhoneNumber(){
    return this->phoneNumber;
    }

void Entry::setPhoneNumber(char* newPhoneNumber){
    this->phoneNumber = new char[strlen(newPhoneNumber)];
    strcpy(this->phoneNumber, newPhoneNumber);
    }

char* Entry::getName(){
    return this->name;
    }

void Entry::setName(char* newName){
    this->name = new char[strlen(newName)];
    strcpy(this->name, newName);
    }

void Entry::displayEntry(){
    cout<<"\nName: "<<this->name<<", "<<"Phone number: "<<this->phoneNumber<<".";
    }

bool Entry::compareEntry(Entry* entry1, Entry* entry2){
    if (strcmp(entry1->getName(), entry2->getName()) > 0) return 1;
    else return 0;
}

Entry* Entry::getNextEntry(){
    return this->nextEntry;
}

void Entry::setNextEntry(Entry* newNextEntry){
    this->nextEntry = newNextEntry;
}

Entry::~Entry(){




    //dtor
}

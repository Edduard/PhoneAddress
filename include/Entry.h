#ifndef PHONEADDRESS_H
#define PHONEADDRESS_H

class Entry
{
    char *name ;
    char *phoneNumber;
    Entry* nextEntry;

    public:
        Entry();
        Entry(char*, char*);
        Entry(char*, char*, Entry*);
        char* getPhoneNumber();
        void setPhoneNumber(char*);
        char* getName();
        void setName(char*);
        Entry* getNextEntry();
        void setNextEntry(Entry*);

        bool compareEntry(Entry*, Entry*); // returns 1 if first entry "bigger" than second and 0 if not

        void displayEntry();
        virtual ~Entry();

    protected:

    private:
};

#endif // PHONEADDRESS_H

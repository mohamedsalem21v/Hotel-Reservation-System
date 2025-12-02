#ifndef PERSON_FILE
#define PERSON_FILE


#include <bits/stdc++.h>
#include "ID.h"
#include "Date.h"
#include "Name.h"
#include "Utils.h"
#include "Contact_Info.h"
using namespace std;


class Person : public ID, public Contact_Information
{
    private :
        
        const int SSN;
        const int age;
        const Name name;
        string Password;
        string aa ;
    public :

        Person ( int SSN , int age , Name name , Object type ) 
            : SSN ( SSN ) 
            , age ( age ) 
            , name ( name ) 
            , ID ( type )
            , Password ( "Not setted" )
        {}
        Person ( int SSN , int age , Name name , Object type, string address, string email, string phone ) 
            : SSN ( SSN ) 
            , age ( age ) 
            , name ( name ) 
            , ID ( type )
        {
            Contact_Information( address, email, phone ) ;
        }

        
    int getSSN() const { return SSN;}
    int getAge() const { return age;}
    Name getName() const { return name;}
    string getPassword() const { return Password; }

    void changePassword(string value) { Password = Utils::hashString( value ) ; }

    friend ostream& operator<< ( ostream& out , Person obj )
    {
        out << obj.name << "\n" ;
        out << static_cast<const ID&>(obj) << "\n" ;
        out << "National ID : " << obj.SSN << "\n" ;
        out << "Password : " << obj.Password << "\n" ;
        out << obj.age << "\n" ;

        return out ;
    }
};

#endif
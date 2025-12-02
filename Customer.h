#ifndef CUSTOMER_FILE
#define CUSTOMER_FILE

#include <bits/stdc++.h>
#include "Person.h"
#include "Utils.h"
#include "Hotel.h"
#include "Date.h"

using namespace std;

class Customer : public Person
{
    private :

        class::Room *Booked_Room ;
        vector<class::Room> Completed_Rooms ;
        bool Current_Room ;
        bool Old_Rooms ;

    public :

        Customer ( int SSN , int age , Name name , Object type ) 
            : Person( SSN , age , name , Object::Customer )
            , Current_Room(0)
            , Old_Rooms(0)
            {} ;

        void Book_Room( RoomType type, Date CheckIn, int duration )
        {
            class::Room *room = Hotel::find_room_to_book( type ) ;
            if ( room == nullptr )
            {
                cout << "There are no available rooms of this type\n" ;
                return ;
            }
            room->setRoomStatus( Booked ) ;
            Date CheckOut = CheckIn + duration ;
            room->setCheckIn( CheckIn ) ;
            room->setCheckOut( CheckOut ) ;
            Booked_Room = room ;
            Current_Room = 1 ;
            cout << "You have booked a room with the following details: \n" ;
            cout << room ;
        }
        void Leave_Room( Date CheckOut )
        {
            if ( Current_Room == 0 )
            {
                cout << "You don't have a current room \n" ;
                return ;
            }
            Current_Room = 0 ;
            Old_Rooms = 1 ; 
            class::Room Leaving = *Booked_Room ;
            Leaving.setCheckOut( CheckOut ) ;
            Completed_Rooms.push_back(Leaving ) ;
            Booked_Room = nullptr ;
        }
        void AddDays( int days )
        {
            if ( Current_Room == 0 )
            {
                cout << "You don't have a current room \n" ;
                return ;
            }
            Booked_Room->setCheckOut( Booked_Room->getCheckOut() + days ) ;
        }
        friend ostream& operator<<(ostream& out, const Customer& obj) 
        {
            out << static_cast<const Person&>(obj);  

            if ( obj.Current_Room )
            {
                out << "-- Current Room -- \n"
                    << "Room number: " << obj.Booked_Room->getRoomNumber() << '\n'
                    << "Room type: " << obj.Booked_Room->getRoomType() << '\n'
                    << " --------------------- \n" ;
            }
            else
            {
                out << "This customer has no current room \n"
                    << " --------------------- \n" ;
            }
            
            if ( obj.Old_Rooms )
            {
                out << "-- Completed room/rooms -- \n" ;
                for ( class::Room room : obj.Completed_Rooms )
                {
                    out << "Room number: " << obj.Booked_Room->getRoomNumber() << '\n'
                        << "Room type: " << obj.Booked_Room->getRoomType() << '\n'
                        << " --------------------- \n" ;
                }
            }
            else
            {
                out << "This customer has no completed rooms \n"
                    << " --------------------- \n" ;
            }
            return out;
        }

};


#endif
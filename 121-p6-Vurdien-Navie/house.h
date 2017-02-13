// House Class
// by C. Siska 2015

#ifndef HOUSE_H
#define HOUSE_H

// Includes
#include <iostream>
using namespace std;

// Includes, Local.
#include "dout.h"
#include "perr.h"
#include "token_reader.h"
#include "room.h" // For Room class.

// ================================================== class Room_parser ====
// House with rooms.
class House
{ public : // For Dev.

  int m_room_cnt;
  // NB, once added, rooms are never removed.
  static const int KAROOMS_SIZE = 99;
  Room * m_arooms[ KAROOMS_SIZE ];
  public : // For Rel.
  //---- Ctors ----
  House( ) : m_room_cnt( 0 ) { }
  //---- Supt Mds ----
  void add_room( Room * rproom ); // Add a room object to the house.
  Room * find_room( int rroom_id ); // Find a house room obj by it's ID.
  void show( );
};


#endif // HOUSE_H

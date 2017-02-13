// Room Class
// by C. Siska 2015

#ifndef ROOM_H
#define ROOM_H

// Includes
#include <iostream>
#include <string>
using namespace std;

// Includes, Local.
#include "dout.h"

// ================================================== class Room_parser ====
// Room with rooms.
class Room
{ public : // For Dev.

  int m_id; // Room ID, simpler than name string. (unrelated to slot index).
  string m_name; // Name is a short word or phrase.
  string m_desc; // Long Description of the room.
  int m_exit_cnt; // Number of ways out of the room.
  static const int KAEXITS_SIZE = 10; // Max # of exits.
  Room * m_aexits[ KAEXITS_SIZE ]; // Exit array, indexed according to Direction.
  public : // For Rel.
  //---- Class Static Mds ----
  // Conversion between direction like "NW" and its fixed array slot index.
  static  int cvt_exit_dir_to_index( string rdir );
  static string cvt_exit_index_to_dir( int rdir_index );
  //---- Ctors ----
  Room( ) : m_id( 0 ), m_name( "" ), m_desc( "" ), m_exit_cnt( 0 )
    { rip_exits( ); }
  Room( int rid, string rname, string rdesc );
  //---- Supt Mds ----
  // Add an exit from our room to the given room.
  void set_exit( string rdir, Room * rproom );
  // Zero out all the room's exit pointers (to other rooms).
  void rip_exits( );
  void show( );
};

#endif // ROOM_H

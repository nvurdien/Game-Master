// House Parser
// by C. Siska 2015

#ifndef HOUSE_PARSER_H
#define HOUSE_PARSER_H

// Notes:
// The grammar Rules are simple regular expressions (regexes).

// Includes
#include <iostream>
#include <string>
using namespace std;

// Includes, Local.
#include "dout.h" // For DOUT.
#include "perr.h" // For perr( ).
#include "token_reader.h" // For Token_reader class.
#include "room.h" // For Room class.
#include "house.h" // For House class.

// ================================================= class House_parser ====
// For parsing a House description file.
class House_parser
{ public : // For Dev.
  int m_more; // More to parse?
  int m_err; // Input malformed?
  Token_reader m_tr; // Machine to read a token at a time from file stream.
  House * m_phouse; // Ptr to house we'll build.

  // public : // For Rel.
  //---- Ctors ----
  House_parser( ) : m_phouse( 0 ), m_err( 0 ) { }
  //---- Conversation Mds ----
  void cleanup( );
  void conversation( );
  int  endchk( );
  void hello( );
  void listen( ); // Get/open file to parse.
  void respond( ); // Build house by parsing file.
  void setup( );
  //---- Parser Mds ----
  void parse_connections( );// Connections grammar structure.
  void parse_exit( Room * rproom_from ); // Exit grammar structure.
  void parse_exit_list( int rroom_id ); // Exit_list grammar structure.
  void parse_file( ); // House grammar description file.
  void parse_house( ); // House grammar structure.
  double parse_keyval_double( string rstr, int & rerr ); // key + double val.
  int    parse_keyval_int( string rstr, int & rerr ); // key + int val.
  string parse_keyval_string( string rstr, int & rerr ); // key + string val.
  void parse_room_exits( ); // Rooms_exits grammar structure.
  Room *  parse_room( ); // Room grammar structure.
 //---- Supt Mds ----
  House * get_house( ) { return m_phouse; } // Return the built house's ptr.
  int next_is_token( string rtoken ); // Is next token as given?
  int parse_lits( string rs1, string rs2 ); // Test next 2 strings as given.
};

#endif // HOUSE_PARSER_H

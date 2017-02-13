// Token Reader
// by C. Siska 2015

#ifndef TOKEN_READER_H
#define TOKEN_READER_H

// Includes, System.
#include <iostream>
#include <fstream> // For ifstream.
using namespace std;

// Includes, Local.
#include "dout.h"
#include "perr.h"  // For perr().

// ================================================== class Token_reader ====
// Read tokens from a file, with 1-token backup.
class Token_reader
{
  public : // For Dev.
  int m_open; // Did the file open?
  ifstream m_fin; // Current open file stream.
  string m_next_token; // File token to retry.
  // public : // For Rel.
  Token_reader( ) { reset( ); } // Default Ctor.
  void close_file_from_user( );
  int open_file_from_user( );
  string peekat_token( );
  int ptoken( string rexp );
  double read_double( );
  int read_int( );
  string read_string( );
  void read_string_tail( string & rsraw, char cx );
  string read_token( );
  void reset( ) { m_next_token = ""; }
};
#endif // TOKEN_READER_H

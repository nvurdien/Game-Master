// DOUT -- CPP Debugging tools.
// by C. Siska 2015

#ifndef DOUT_H
#define DOUT_H

// Sample use:
//   DOUT << "Connection:" DZ( m_id ) DZ( rdir ) DZ( rproom->m_id ) ENDLDOUT;

// CPP Debugging tools.
#define DOUT cout << "  DBG:"
#define ENDLDOUT << endl
#define DZ( zzelt ) << " " #zzelt "= " << (zzelt) << " "

#endif // DOUT_H

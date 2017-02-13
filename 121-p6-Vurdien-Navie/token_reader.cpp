#include "stdafx.h"
#include "token_reader.h"
using namespace std;



// =============================================== close_file_from_user ====
// Close the file that we opened for the user.
// Line count: 1
void Token_reader::close_file_from_user()
{
	//DOUT << "close_file_from_user." ENDL//DOUT;
	m_fin.close();
}

// ================================================ open_file_from_user ====
// Open the file that the user indicates.
// Return false if it failed to open, else true.
// Line count: 4
int Token_reader::open_file_from_user()
{
	//cout << "Enter input file name, or q to quit> ";
	//string fname;
	//cin >> fname; // Get the user's filename.
	string fname = "house-sample.txt";
	m_open = ("q" != fname);
	//*DBG*/ cout << "m_more=" << m_more << endl;
	if (m_open)
	{
		m_fin.open(fname.c_str()); // Open into global var file stream.
		if (!m_fin) perr("file open"); // Handle errors.
	}
	//DOUT DZ( m_open ) ENDL//DOUT;
	return m_open;
}

// ================================================== peekat_token ====
// Look at next token, but leave it to be parsed next.
// Typically used to check if next token will be a delimiter.
// Line count: 2
string Token_reader::peekat_token()
{
	//DOUT << "peekat_token." ENDL//DOUT;
	string stoken;
	m_fin >> stoken; // Get next token from file.
	m_next_token = stoken; // Prepare peeked token to be next actually parsed.
	//*DBG*/ cout << "peekat= " << stoken << endl;
	return stoken;
}

// ================================================== ptoken ====
// Check if next token is the given (expected) string.
// Output a parse error if it isn't.
// Return 1 if token found, else 0.
// Line count: 5
int Token_reader::ptoken(string rexp)
{
	//DOUT << "ptoken." ENDL//DOUT;
	string stoken = m_next_token; // Get prepared token, if any.
	if ("" == stoken) m_fin >> stoken; // Input file tok if no prep'd tok.
	else m_next_token = ""; // Clear prep'd tok var.

	//*DBG*/ cout << "stoken='" << stoken << endl;
	if (rexp != stoken) perr(rexp, stoken); // Handle unexpected tok error.
	//DOUT DZ( stoken ) ENDL//DOUT;
	return (rexp == stoken); // Tell caller if expected token was found.
}

// =============================================== read_double ====
// Read an doubleeger from the file.
// Line count: 1
double Token_reader::read_double()
{
	//DOUT << "read_double." ENDL//DOUT;
	double dx;
	m_fin >> dx;
	return dx;
}

// =============================================== read_int ====
// Read an integer from the file.
// Line count: 1
int Token_reader::read_int()
{
	//DOUT << "read_int." ENDL//DOUT;
	int ix;
	m_fin >> ix;
	return ix;
}

// =============================================== read_string_tail ====
// Read/append tail of a string, from the file.
// Specail note: this loop was split from read_string to reduce Line Count.
// Line count: 7
void Token_reader::read_string_tail(string & rsraw, char rcx)
{
	int it = 100; // "Too many tokens" control val, to avoid runaway loop.
	while ('"' != rcx) // Till we see the '"' at end of string...
	{
		string xraw;
		m_fin >> xraw; // Get next string token.
		////DOUT DZ( xraw ) ENDL//DOUT;  
		rsraw += " " + xraw; // Append the token with a space.
		int sraw_len = rsraw.length(); // Update string length.
		rcx = rsraw[sraw_len - 1]; // Update last string char.
		////DOUT DZ( rsraw ) DZ( sraw_len ) DZ( rcx ) ENDL//DOUT;
		if (!--it) { cout << "Error: string: too many words.\n"; break; }
	}
}

// =============================================== read_string ====
// Read a string from the file.
// Line count: 7
string Token_reader::read_string()
{
	//DOUT << "read_string." ENDL//DOUT;
	string sraw = read_token(); // Get string's starting token.
	////DOUT DZ( sraw ) ENDL//DOUT;    
	if ('"' != sraw[0]) perr(sraw, "\""); // Didn't start with '"'?
	// Push on anyway, if error.  (Wouldn't hurt.  Parse already busted.)
	int sraw_len = sraw.length(); // Init string length.
	////DOUT DZ( sraw_len ) ENDL//DOUT;
	char cx = sraw[sraw_len - 1]; // Get last string char.
	read_string_tail(sraw, cx); // Sets sraw.
	string sx = sraw.substr(1, sraw_len - 2); // Get string w/out dbquotes.
	////DOUT DZ( sx ) ENDL//DOUT;
	return sx;
}

// =============================================== read_token ====
// Read a token from the file.
// Line count: 3
string Token_reader::read_token()
{
	//DOUT << "read_token." ENDL//DOUT;
	string stoken = m_next_token; // Get prepared token, if any.
	if ("" == stoken) m_fin >> stoken; // Input file tok if no prep'd tok.
	else m_next_token = ""; // Clear prep'd tok var.
	////DOUT DZ( stoken ) ENDL//DOUT;
	return stoken;
}

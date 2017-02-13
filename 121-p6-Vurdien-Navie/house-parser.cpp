// House Parser Test Main
// by C. Siska 2015

// Includes
#include "stdafx.h"

// Includes, Local.
#include "house_parser.h"

// ================================================== main ====
// Line count = 3
//int main( )
//{
  //House_parser hp; // Get a house parser.
  //hp.conversation( ); // Build a house from a file description.
  //House * ph = hp.get_house( ); // Get the newly built house.
  //if (ph) ph->show( ); // Display the house.
  //return 0;
//}

//@@---- Conversation Mds ----
// ==================================================== cleanup ====
// Announce that the program is done.
// Line count = 0
void House_parser::cleanup()
{
	//DOUT << "cleanup." ENDLDOUT;
}

// ==================================================== conversation ====
// Have a conversation with the user.
// Line count: 6
void House_parser::conversation()
{
	//DOUT << "conversation." ENDLDOUT;
	setup();  // Setup to run.
	//hello();  // Say Hi.
	do {  // Loop till done.
		listen(); // Listen to user.
		respond(); // Respond to user's input.
	} while (endchk()); // Till user is done.
	cleanup(); // Clean up after user is done.
}

// ==================================================== endchk ====
// Return whether the User still wants to talk.
// Line count = 0
int House_parser::endchk()
{
	//DOUT << "endchk." ENDLDOUT;
	return 0;
}

// ==================================================== hello ====
// Announce the program to the User.
// Line count = 0
void House_parser::hello()
{
	//DOUT << "hello." ENDLDOUT;
	cout << "Hello.  This is the House description parser.\n";
}

// ==================================================== listen ====
// Get/open User's house file.
// Line count = 1
void House_parser::listen()
{
	//DOUT << "listen." ENDLDOUT;
	m_more = m_tr.open_file_from_user(); // Get/open a user file choice.
}

// ==================================================== respond ====
// Respond to user.
// Line count: 4
void House_parser::respond()
{
	//DOUT << "respond." ENDLDOUT;
	if (m_more) // File opened?
	{ // Parse scene file sections.
		parse_file(); // Parse/build the house from file description.
		m_tr.close_file_from_user(); // Close the file.
	}
	else if (m_more) cout << "Can't parse the file.";
}

// ==================================================== setup ====
// Announce that the program is done.
// Line count = 0
void House_parser::setup()
{
	//DOUT << "setup." ENDLDOUT;
}

//@@---- Parser Mds ----
// ================================================ parse_connections ====
// Parse a Connections grammar structure.
// Rule: Connections = "connections" Room_exits*
// Each Room_exits structure begins with a '('.
// Line count: 4
void House_parser::parse_connections()
{
	//DOUT << "parse_connections." ENDLDOUT;
	do { // Once.
		if (!m_tr.ptoken("connections")) break;
		while (next_is_token("(")) // Is another room exits list...
		{
			parse_room_exits();
		}
	} while (0); // Once.
}

// ==================================================== parse_exit ====
// Parse an Exit grammar structure.
// Rule: Exit = Direction Room_id
// Line count: 5
void House_parser::parse_exit(Room * rproom_from)
{
	//DOUT << "parse_exit." ENDLDOUT;
	do { // Once.
		string dir = m_tr.read_token(); // Get exit direction.
		//DOUT DZ(dir) ENDLDOUT;
		int room_id_to = m_tr.read_int(); // Get target room id.
		// Get target room ptr.
		Room * proom_to = m_phouse->find_room(room_id_to);
		if (!proom_to)
		{
			cout << "Couldn't find room_id=" << room_id_to << endl;; break;
		}
		// Connect our 'from' room to target room
		rproom_from->set_exit(dir, proom_to);
	} while (0); // Once.
}

// ==================================================== parse_exit_list ====
// Parse an Exit_list grammar structure.
// Rule: Exit_list = Exit*
// Token after last Exit_list is a ')'.
// Line count: 4
void House_parser::parse_exit_list(int rroom_id)
{
	//DOUT << "parse_exit_list." ENDLDOUT;
	Room * proom_from = m_phouse->find_room(rroom_id);
	do { // Once.
		if (!proom_from)
		{
			cout << "Couldn't find room_id=" << rroom_id << endl;; break;
		}
		//DOUT << "Connecting from: " DZ(rroom_id) ENDLDOUT;
		while (!next_is_token(")")) // Is another exit...
		{
			parse_exit(proom_from); // Read the Exit structure.
		}
	} while (0); // Once.
}

// ==================================================== parse_file ====
// Parse a House grammar description file.
// Line count: 2
void House_parser::parse_file()
{
	//DOUT << "parse_file." ENDLDOUT;
	m_tr.reset(); // Reset the token reader for another file.
	parse_house(); // Read/build House description from the file.
}

// ==================================================== parse_house ====
// Parse a House grammar structure.
// House = '(' "house" Room* Connections ')'
// The "connections" token follows the last house room grammar structure.
// Special Note: parse_lits() was created to keep our Line Count down.
// Line count: 8
void House_parser::parse_house()
{
	//DOUT << "parse_house." ENDLDOUT;
	House * phouse = new House; // Make a new empty house obj.
	do { // Once.
		if (!phouse) { perr("new House"); break; } // No house made?
		m_phouse = phouse; // Save house ptr for use by all parse fcns.
		if (!parse_lits("(", "house")) break; // Check start of House.
		while (!next_is_token("connections")) // Is another room...
		{
			phouse->add_room(parse_room()); // Read/Add the Room structure.
		};
	} while (0); // Once.
	parse_connections(); // Read Connections description from the file.
	m_tr.ptoken(")"); // Ends with ')'.
}

// ============================================== parse_keyval_double ====
// Parse a key-val pair: a name and it's double value.
// Return the double value, or 0.
// Sets caller's rerr on parse error (passed by reference).
// Line count: 3
double House_parser::parse_keyval_double(string rstr, int & rerr)
{
	//DOUT << "parse_keyval_double." ENDLDOUT;
	double  retval = 0;
	// If the key is found first, read the value else set error.
	if (m_tr.ptoken(rstr)) retval = m_tr.read_double();
	else rerr = 1;
	return retval;
}

// ============================================== parse_keyval_int ====
// Parse a key-val pair: a name and it's int value.
// Return the int value, or 0.
// Sets caller's rerr on parse error (passed by reference).
// Line count: 3
int House_parser::parse_keyval_int(string rstr, int & rerr)
{
	//DOUT << "parse_keyval_int." ENDLDOUT;
	int  retval = 0;
	// If the key is found first, read the value else set error.
	if (m_tr.ptoken(rstr)) retval = m_tr.read_int();
	else rerr = 1;
	return retval;
}

// ============================================== parse_keyval_string ====
// Parse a key-val pair: a name and it's string value.
// Return the string value, or "".
// Sets caller's rerr on parse error (passed by reference).
// Line count: 3
string House_parser::parse_keyval_string(string rstr, int & rerr)
{
	//DOUT << "parse_keyval_string." ENDLDOUT;
	string  retval = "";
	// If the key is found first, read the value else set error.
	if (m_tr.ptoken(rstr)) retval = m_tr.read_string();
	else rerr = 1;
	return retval;
}

// ==================================================== parse_room ====
// Parse a Room grammar structure.
// Room = '(' "room" Room_int "name:" Id_str "desc:" string ')'
// Line count: 7
Room * House_parser::parse_room()
{
	//DOUT << "parse_room." ENDLDOUT;
	Room * proom = 0;
	int err = 0; // Default to no parse error.
	do { // Once.
		if (!m_tr.ptoken("(")) break; // Room starts with '('.
		// Read each of the room parts.
		int room_id = parse_keyval_int("room-id:", err); // "room" Room_int.
		//DOUT DZ(room_id) ENDLDOUT;
		string room_name = parse_keyval_string("name:", err);
		//DOUT DZ(room_name) ENDLDOUT;
		string room_desc = parse_keyval_string("desc:", err);
		//DOUT DZ(room_desc) ENDLDOUT;
		if (err || !m_tr.ptoken(")")) break; // Ends with ')'
		proom = new Room(room_id, room_name, room_desc); // Create the room obj.
	} while (0); // Once.
	return proom;
}

// ================================================== parse_room_exits ====
// Parse a Rooms_exits grammar structure.
// Rule: Rooms_exits = '(' "room-id:" int exits: Exit_list ')'
// Line count: 6
void House_parser::parse_room_exits()
{
	//DOUT << "parse_rooms_exits." ENDLDOUT;
	int err = 0; // Default to no parse error.
	do { // Once.
		if (!m_tr.ptoken("(")) break; // Starts with '('.
		// Read each of the room parts.
		int room_id = parse_keyval_int("room-id:", err);
		//DOUT DZ(room_id) ENDLDOUT;
		if (!m_tr.ptoken("exits:")) break; // 
		parse_exit_list(room_id); // Read the room's exit_list structure.
		if (!m_tr.ptoken(")")) break; // Ends with ')'.
	} while (0); // Once.
}

//@@---- Supt Mds ----
// ==================================================== next_is_token ====
// Return whether the next token will as given.
// Leaves it at front of input stream.
// Line count: 3
int House_parser::next_is_token(string rtoken)
{
	//DOUT << "next_is_token." ENDLDOUT;
	string stoken = m_tr.peekat_token(); // Look at next token.
	int scmp = (rtoken == stoken); // returns 0 on a match.
	//DOUT DZ(stoken) DZ(scmp) ENDLDOUT;
	return scmp; // Returns 1 if close, else 0;
}

// ==================================================== parse_lits ====
// Parse two literal strings from input.
// Return 1 if tokens found, else 0.
// Line count: 1
int House_parser::parse_lits(string rs1, string rs2)
{
	//DOUT << "parse_lits." ENDLDOUT;
	// Did we see both literal strings?
	return (m_tr.ptoken(rs1) && m_tr.ptoken(rs2));
}

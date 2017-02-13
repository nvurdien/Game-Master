#include "stdafx.h"
#include "room.h"
using namespace std;

// ================================================== Room 3-Arg Ctor ====
// Ctor: build room with it's data (less exits).
// Line count: 2
Room::Room(int rid, string rname, string rdesc)
	: m_id(rid), m_name(rname), m_desc(rdesc), m_exit_cnt(0)
{
	rip_exits(); // By default, the room has no exits.
	//show();
}

// ================================================== set_exit ====
// Add an exit from our room to the given room.
// Uses North if given an illegal direction.
// Redirects the exit if it was already set to another room.
// Line count: 5
void Room::set_exit(string rdir, Room * rproom)
{
	int exit_index = cvt_exit_dir_to_index(rdir); // Direction -> index.
	Room * pr_old = m_aexits[exit_index]; // Get old exit ptr to room.
	m_aexits[exit_index] = rproom; // Connect indexed exit to that room.
	if (rproom) ++m_exit_cnt; // Increment for the new exit.
	if (pr_old) --m_exit_cnt; // Decrement if an old exit was overwritten.
	//DOUT << "Connection:" DZ(m_id) DZ(rdir) DZ(rproom->m_id) ENDLDOUT;
}

// ============================================== cvt_exit_dir_to_index ====
// Convert an exit direction string to an exit array index. 
// Returns exit for North, "N", if illegal direction.
// Line count: 13 (waiver, for data all alike)
int Room::cvt_exit_dir_to_index(string rdir)
{
	int index = 0;
	if ("N" == rdir) index = 0;////////////
	else if ("NE" == rdir) index = 1;
	else if ("E" == rdir) index = 2;/////////////
	else if ("SE" == rdir) index = 3;
	else if ("S" == rdir) index = 4;///////
	else if ("SW" == rdir) index = 5;
	else if ("W" == rdir) index = 6;/////////////////
	else if ("NW" == rdir) index = 7;
	else if ("UP" == rdir) index = 8;
	else if ("DOWN" == rdir) index = 9;

	// Here we ensure we don't return an out-of-bounds array index.
	if (index >= KAEXITS_SIZE) index = KAEXITS_SIZE - 1;
	return index;
}

// ============================================== cvt_exit_dir_to_index ====
// Convert an exit direction string to an exit array index. 
// Returns exit for North, "N", if illegal direction.
// Line count: 13 (waiver, for data all alike)
string Room::cvt_exit_index_to_dir(int rdir_index)
{
	string dir_string = "Unknown"; // Default for bad index.
	switch (rdir_index)
	{
	case 0: dir_string = "N"; break;
	case 1: dir_string = "NE"; break;
	case 2: dir_string = "E"; break;
	case 3: dir_string = "SE"; break;
	case 4: dir_string = "S"; break;
	case 5: dir_string = "SW"; break;
	case 6: dir_string = "W"; break;
	case 7: dir_string = "NW"; break;
	case 8: dir_string = "UP"; break;
	case 9: dir_string = "DOWN"; break;
	}
	return dir_string;
}

// ==============================================  rip_exits  ====
// Zero out all the room's exit pointers (to other rooms).
// Line count: 2
void Room::rip_exits()
{
	for (int ix = 0; ix < KAEXITS_SIZE; ++ix)
	{
		m_aexits[ix] = 0;
	}
}

// ==============================================  show  ====
// Show the room data.
// Line count: 4
void Room::show()
{
	cout << "(Room " DZ(m_id) DZ(m_name) DZ(m_exit_cnt) DZ(m_desc) << endl;
	string sdir;
	for (int ix = 0; ix < KAEXITS_SIZE; ++ix)
	{
		Room * proom_to = m_aexits[ix];
		if (proom_to)
		{
			sdir = Room::cvt_exit_index_to_dir(ix);
			cout << "    " << sdir << ": to " << proom_to->m_id << endl;
		}
	}
	cout << ")\n";
}
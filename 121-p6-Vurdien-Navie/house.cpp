#include "stdafx.h"
#include "house.h"
using namespace std;

// ================================================== add_room ====
// Add a room to the house.
// Ignores if the house is full of rooms.
// Note: room_cnt is also index to next available open slot.
// Line count: 2
void House::add_room(Room * rproom)
{
	if (KAROOMS_SIZE > m_room_cnt) // Room for another room in house?
	{
		m_arooms[m_room_cnt] = rproom; // Add room ptr to next open slot.
		++m_room_cnt; // Count it.
	}
}

// ================================================== find_room ====
// Return room in the house with the given id, else 0.
// Line count: 3
Room * House::find_room(int rroom_id)
{
	Room * pret_room = 0;
	for (int ix = 0; ix < m_room_cnt; ++ix)
	{
		Room * proom = m_arooms[ix];
		if (rroom_id == proom->m_id) pret_room = proom; // If ID match, set ptr.
	}
	return pret_room;
}
// ================================================== shoe ====
// Show the house data.
// Line count: 2
void House::show()
{
	cout << "(House " DZ(m_room_cnt) << endl;
	for (int ix = 0; ix < m_room_cnt; ++ix) // Each room.
	{
		cout << "\n  #" << ix << ": ";
		m_arooms[ix]->show(); // Show that room.
	}
	cout << ")\n";
}
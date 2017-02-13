#include "stdafx.h"
#include "perr.h"
#include <iostream>
using namespace std;


// ================================================== perr ====
// Output an error msg.
// Line count: 1
void perr(string rerr, string rexp)
{
	cout << "\nParse Error: Bad " << rerr;
	if (0 < rexp.length()) cout << ", saw " << rexp;
	cout << endl;
}

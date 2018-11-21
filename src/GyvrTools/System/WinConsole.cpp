#include "GyvrTools/System/WinConsole.h"

#include <iostream>
#include <string>

void GyvrTools::System::WinConsole::MoveCursorTo(SHORT p_x, SHORT p_y)
{
	COORD pos = { p_x, p_y };
	MoveCursorTo(pos);
}

void GyvrTools::System::WinConsole::MoveCursorTo(COORD p_coordinates)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, p_coordinates);
}

COORD GyvrTools::System::WinConsole::GetConsoleCursorPosition()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	if (GetConsoleScreenBufferInfo(hConsole, &cbsi))
	{
		return cbsi.dwCursorPosition;
	}
	else
	{
		COORD invalid = { 0, 0 };
		return invalid;
	}
}

COORD GyvrTools::System::WinConsole::GetConsoleSize()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	SHORT columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	return COORD{ columns, rows };
}

void GyvrTools::System::WinConsole::ClearScreen(SHORT p_topMargin, SHORT p_bottomMargin, bool p_keepCursorPosition)
{
	/* Start position of the clear */
	COORD coordScreen = { 0, p_topMargin };
	COORD cursorStartupPosition = GetConsoleCursorPosition();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	/* Get the number of character cells in the current buffer */
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * (csbi.dwSize.Y - p_bottomMargin - p_topMargin);

	/* Fill the entire screen with blanks */
	FillConsoleOutputCharacter(hConsole, (TCHAR) ' ', dwConSize, coordScreen, &cCharsWritten);

	/* Get the current text attribute */
	GetConsoleScreenBufferInfo(hConsole, &csbi);

	/* Now set the buffer's attributes accordingly */
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);

	if (p_keepCursorPosition)
	{
		/* Reset the cursor to his previous position*/
		SetConsoleCursorPosition(hConsole, GetConsoleCursorPosition());
	}
	else
	{
		/* put the cursor at (0, 0) */
		SetConsoleCursorPosition(hConsole, coordScreen);
	}
}
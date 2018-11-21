/**
* Project GyvrTools
* @author Adrien Givry
* @version 1.0
*/

#pragma once
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__) /* Make This class only available for Windows OS */
#ifndef _GYVRTOOLS_WINCONSOLE_H
#define _GYVRTOOLS_WINCONSOLE_H

#include <windows.h>

#include "GyvrTools/API/Export.h"

namespace GyvrTools::System
{
	/**
	* Some console tools specific to Windows OS
	*/
	class API_GYVRTOOLS WinConsole final
	{
	public:
		/* Desactivate the constructor (Un-instanciable static class) */
		WinConsole() = delete;

		/**
		* Move the console cursor to the given position
		* @param p_x
		* @param p_y
		*
		* WINDOWS ONLY
		*/
		static void MoveCursorTo(SHORT p_x, SHORT p_y);

		/**
		* Move the console cursor to the given position
		* @param p_coordinates
		*
		* WINDOWS ONLY
		*/
		static void MoveCursorTo(COORD p_coordinates);

		/**
		* Return the current cursor position
		*/
		static COORD GetConsoleCursorPosition();

		/**
		* Return the width and height of the console
		*/
		static COORD GetConsoleSize();

		/**
		* Clear the screen with margins (Where to start and where to end)
		* @param p_topMargin
		* @param p_bottomMargin
		* @param p_keepCursorPosition
		*/
		static void ClearScreen(SHORT p_topMargin = 0, SHORT p_bottomMargin = 0, bool p_keepCursorPosition = false);
	};
}

#endif // _GYVRTOOLS_WINCONSOLE_H
#endif // Windows only condition
/**
* Project GyvrTools
* @author Adrien Givry
* @version 1.0
*/

#pragma once
#ifndef _GYVRTOOLS_CONSOLEINPUT_H
#define _GYVRTOOLS_CONSOLEINPUT_H

#include <string>

#include "GyvrTools/API/Export.h"

namespace GyvrTools::System
{
	/**
	* Some console input tools
	*/
	class API_GYVRTOOLS ConsoleInput final
	{
	public:
		/* Desactivate the constructor (Un-instanciable static class) */
		ConsoleInput() = delete;

		/**
		* Ask the user to answer Yes or No
		* @param p_message
		*/
		static bool AskYesOrNoToTheUser(const std::string& p_message);

		/**
		* Ask the user to type a string
		* @param p_message
		*/
		static std::string AskForString(const std::string& p_message);

		/**
		* Ask the user to type a number
		* @param p_message
		*/
		static int AskForInt(const std::string& p_message);

		/**
		* Ask the user to type a float
		* @param p_message
		*/
		static float AskForFloat(const std::string& p_message);
	};
}

#endif // _GYVRTOOLS_CONSOLEINPUT_H
/**
* Project GyvrTools
* @author Adrien Givry
* @version 1.0
*/

#pragma once
#ifndef _GYVRTOOLS_DEBUG_H
#define _GYVRTOOLS_DEBUG_H

#include <iostream>
#include <string>

#include "GyvrTools/API/Export.h"

/**
* Holds file info such as file and line number
*/
#define __GYVR_FILE_INFO__ __FILE__, __LINE__

namespace GyvrTools::System
{
	/**
	* Contains static methods to write on the standard output and use assertions
	*/
	class API_GYVRTOOLS Debug final
	{
	public:
		/* Desactivate the constructor (Un-instanciable static class) */
		Debug() = delete;

		/**
		* Verify the condition and abort the process if the condition is false
		* @param p_condition
		*/
		static void Assert(bool p_condition);

		/**
		* Verify the condition and abort the process if the condition is false
		* @param p_condition
		* @param p_message
		*/
		static void Assert(bool p_condition, const std::string& p_message);

		/**
		* Verify the condition and abort the process if the condition is false
		* @param p_condition
		* @param p_file
		* @param p_line
		* @important p_file and p_line should get replaced by the __GYVR_FILE_INFO__ macro
		*/
		static void Assert(bool p_condition, const char* p_file, int p_line);

		/**
		* Verify the condition and abort the process if the condition is false
		* @param p_condition
		* @param p_message
		* @param p_file
		* @param p_line
		* @important p_file and p_line should get replaced by the __GYVR_FILE_INFO__ macro
		*/
		static void Assert(bool p_condition, const std::string& p_message, const char* p_file, int p_line);

		/**
		* Log a message to the standard output as an information
		* @param p_message
		*/
		static void Log(const std::string& p_message);

		/**
		* Log a message to the standard output as a warning
		* @param p_message
		*/
		static void LogWaring(const std::string& p_message);

		/**
		* Log a message to the standard output as an error
		* @param p_message
		*/
		static void LogError(const std::string& p_message);

	private:
		static const std::string __INFO_HEADER;
		static const std::string __WARNING_HEADER;
		static const std::string __ERROR_HEADER;
	};
}

#endif // _GYVRTOOLS_DEBUG_H
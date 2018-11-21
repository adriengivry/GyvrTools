/**
* Project GyvrTools
* @author Adrien Givry
* @version 1.0
*/

#pragma once
#ifndef _GYVRTOOLS_INILOADER_H
#define _GYVRTOOLS_INILOADER_H

#include <string>
#include <unordered_map>

#include "GyvrTools/API/Export.h"
#include "GyvrTools/System/ErrorHandler.h"

namespace GyvrTools::Files
{
	/**
	* Ini system that store config files data and give access to them at any time using static methods
	*/
	class API_GYVRTOOLS IniLoader final
	{
	public:
		/**
		* Typedef for a set of attributes, orderered by files
		*/
		using ConfigurationList = std::unordered_map<std::string, std::unordered_map<std::string, std::string>>;

		/* Desactivate the constructor (Un-instanciable static class) */
		IniLoader() = delete;

		/**
		* Static method get an integer from a config file
		* @param p_file
		* @param p_attribute
		*/
		static int GetInt(const std::string& p_file, const std::string& p_attribute);

		/**
		* Static method get a float from a config file
		* @param p_file
		* @param p_attribute
		*/
		static float GetFloat(const std::string& p_file, const std::string& p_attribute);

		/**
		* Static method get a string from a config file
		* @param p_file
		* @param p_attribute
		*/
		static std::string GetString(const std::string& p_file, const std::string& p_attribute);

		/**
		* Static method get a boolean from a config file
		* @param p_file
		* @param p_attribute
		*/
		static bool GetBool(const std::string& p_file, const std::string& p_attribute);

		/**
		* Set the config folder path (Must be set before loadingFiles/calling get methods)
		* @param p_path
		*/
		static void SetConfigFolderPath(const std::string& p_path);

		/**
		* This ones load every config files. It is called when the first data is queried.
		* If you want to avoid any long computation time at runtime, you should call this
		* at the beginning of your program. You should avoid multiple calls of this method
		*/
		static void LoadEveryFiles();

	private:
		static std::string GetData(const std::string& p_file, const std::string& p_attribute);
		static std::string GetAttributeLine(const std::string& p_confPath, const std::string& p_attribute);
		static std::string GetAttributeValue(std::string p_line);
		static std::string GetAttributeName(std::string p_line);
		
	private:
		static ConfigurationList	__DATA;
		static std::string			__CONFIG_FOLDER;
		static bool					__LOADED;
	};
}

#endif // _GYVRTOOLS_INILOADER_H
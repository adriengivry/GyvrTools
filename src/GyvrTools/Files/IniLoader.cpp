#include "GyvrTools/Files/IniLoader.h"

#include <sstream>
#include <fstream>
#include <filesystem>
#include <iostream>

GyvrTools::Files::IniLoader::ConfigurationList	GyvrTools::Files::IniLoader::__DATA;
std::string										GyvrTools::Files::IniLoader::__CONFIG_FOLDER = "config/";
bool											GyvrTools::Files::IniLoader::__LOADED = false;

int GyvrTools::Files::IniLoader::GetInt(const std::string& p_file, const std::string& p_attribute)
{
	if (!__LOADED)
		LoadEveryFiles();

	return std::stoi(GetData(p_file, p_attribute));
}

float GyvrTools::Files::IniLoader::GetFloat(const std::string& p_file, const std::string& p_attribute)
{
	if (!__LOADED)
		LoadEveryFiles();

	return std::stof(GetData(p_file, p_attribute));
}

std::string GyvrTools::Files::IniLoader::GetString(const std::string& p_file, const std::string& p_attribute)
{
	if (!__LOADED)
		LoadEveryFiles();

	return GetData(p_file, p_attribute);
}

bool GyvrTools::Files::IniLoader::GetBool(const std::string& p_file, const std::string& p_attribute)
{
	if (!__LOADED)
		LoadEveryFiles();

	const auto strValue = GetData(p_file, p_attribute);
	if (strValue == "true" || strValue == "1") return true;
	if (strValue == "false" || strValue == "0") return false;
	return false;
}

void GyvrTools::Files::IniLoader::SetConfigFolderPath(const std::string & p_path)
{
	__CONFIG_FOLDER = p_path;
}

std::string GyvrTools::Files::IniLoader::GetData(const std::string& p_file, const std::string& p_attribute)
{
	if (__DATA.find(p_file) != __DATA.end() && __DATA[p_file].find(p_attribute) != __DATA[p_file].end())
		return __DATA[p_file][p_attribute];
	else
	{
		GyvrTools::System::ErrorHandler::RegisterError("IniLoader: " + p_file + " = > " + p_attribute + " not found");
		return "0";
	}
}

std::string GyvrTools::Files::IniLoader::GetAttributeLine(const std::string& p_confPath, const std::string& p_attribute)
{
	std::string line;
	std::ifstream file;
	file.open(p_confPath, std::ofstream::out | std::ofstream::app);
	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			if (GetAttributeName(line) == p_attribute)
				return line;
		}

		file.close();
	}
	return line;
}

std::string GyvrTools::Files::IniLoader::GetAttributeValue(std::string p_line)
{
	std::string result;
	bool rightSide = false;

	for (auto c : p_line)
	{
		if (rightSide) result.push_back(c);
		if (c == '=') rightSide = true;
	}

	return result;
}

std::string GyvrTools::Files::IniLoader::GetAttributeName(std::string p_line)
{
	std::string result;

	for (auto c : p_line)
	{
		if (c == '=') return result;
		result.push_back(c);
	}

	return result;
}

void GyvrTools::Files::IniLoader::LoadEveryFiles()
{
	__DATA.clear();

	std::string line;
	std::ifstream file;

	for (std::experimental::filesystem::recursive_directory_iterator i(__CONFIG_FOLDER), end; i != end; ++i)
	{
		if (!is_directory(i->path()))
		{
			std::string filepath = i->path().string();
			std::string filename = i->path().filename().string();

			if (filepath.size() > 4)
			{
				file.open(filepath, std::ofstream::out | std::ofstream::app);
				if (file.is_open())
				{
					while (std::getline(file, line))
					{
						if (line[0] != '#')
						{
							std::string attribute = GetAttributeName(line);
							std::string value = GetAttributeValue(line);

							if (attribute != "" && value != "")
								__DATA[filename][attribute] = value;
						}
					}

					file.close();
				}
			}
		}
	}

	__LOADED = true;
}

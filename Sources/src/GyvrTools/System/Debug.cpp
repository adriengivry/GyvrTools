#include "GyvrTools/System/Debug.h"

std::string const GyvrTools::System::Debug::__INFO_HEADER		= "[INFO] ";
std::string const GyvrTools::System::Debug::__WARNING_HEADER	= "[WARNING] ";
std::string const GyvrTools::System::Debug::__ERROR_HEADER	= "[ERROR] ";

void GyvrTools::System::Debug::Assert(bool p_condition)
{
	Assert(p_condition, "");
}

void GyvrTools::System::Debug::Assert(bool p_condition, const std::string & p_message)
{
	#ifdef _DEBUG
	if (!p_condition)
	{
		LogError("Assertion failed" + p_message != "" ? ": " + p_message : "");
		abort();
	}
	#endif
}

void GyvrTools::System::Debug::Assert(bool p_condition, const char * p_file, int p_line)
{
	Assert(p_condition, "", p_file, p_line);
}

void GyvrTools::System::Debug::Assert(bool p_condition, const std::string & p_message, const char * p_file, int p_line)
{
	const std::string file(p_file);
	const std::string line(std::to_string(p_line));

	Assert(p_condition, p_message + "(File: " + file + " on line " + line + ")");
}

void GyvrTools::System::Debug::Log(const std::string & p_message)
{
	std::cout << __INFO_HEADER << p_message << std::endl;
}

void GyvrTools::System::Debug::LogWaring(const std::string & p_message)
{
	std::cout << __WARNING_HEADER << p_message << std::endl;
}

void GyvrTools::System::Debug::LogError(const std::string & p_message)
{
	std::cerr << __ERROR_HEADER << p_message << std::endl;
}



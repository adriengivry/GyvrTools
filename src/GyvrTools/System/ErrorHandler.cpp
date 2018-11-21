#include "GyvrTools/System/ErrorHandler.h"

std::string GyvrTools::System::ErrorHandler::__LAST_ERROR = "";

const std::string& GyvrTools::System::ErrorHandler::GetLastError()
{
	return __LAST_ERROR;
}

void GyvrTools::System::ErrorHandler::LogLastError()
{
	GyvrTools::System::Debug::Log(__LAST_ERROR);
}

void GyvrTools::System::ErrorHandler::ClearLastError()
{
	__LAST_ERROR = "";
}

bool GyvrTools::System::ErrorHandler::HasLastError()
{
	return __LAST_ERROR != "";
}

void GyvrTools::System::ErrorHandler::RegisterError(const std::string & p_error)
{
	__LAST_ERROR = p_error;
}

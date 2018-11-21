#include "GyvrTools/Utils/Date.h"

GyvrTools::Utils::Date::RawDateInfo GyvrTools::Utils::Date::GetDateRaw()
{
	RawDateInfo currentDate;

	tm localTime = GetLocalTime();

	currentDate.year	= static_cast<uint16_t>(1900	+ localTime.tm_year);
	currentDate.month	= static_cast<uint16_t>(1		+ localTime.tm_mon);
	currentDate.day		= static_cast<uint16_t>(localTime.tm_mday);
	currentDate.hours	= static_cast<uint16_t>(localTime.tm_hour);
	currentDate.minutes = static_cast<uint16_t>(localTime.tm_min);
	currentDate.seconds = static_cast<uint16_t>(localTime.tm_sec);

	return currentDate;
}

GyvrTools::Utils::Date::FormattedDateInfo GyvrTools::Utils::Date::GetDateFormated()
{
	FormattedDateInfo currentDate;

	RawDateInfo rawCurrentDate = GetDateRaw();

	/* Month, day, hours, minutes and seconds starts by '0' if they are only one digit */
	currentDate.year	= std::to_string(rawCurrentDate.year);
	currentDate.month	= (rawCurrentDate.month		< 10 ? "0" : "") + std::to_string(rawCurrentDate.month);
	currentDate.day		= (rawCurrentDate.day		< 10 ? "0" : "") + std::to_string(rawCurrentDate.day);
	currentDate.hours	= (rawCurrentDate.hours		< 10 ? "0" : "") + std::to_string(rawCurrentDate.hours);
	currentDate.minutes = (rawCurrentDate.minutes	< 10 ? "0" : "") + std::to_string(rawCurrentDate.minutes);
	currentDate.seconds = (rawCurrentDate.seconds	< 10 ? "0" : "") + std::to_string(rawCurrentDate.seconds);

	return currentDate;
}

tm GyvrTools::Utils::Date::GetLocalTime()
{
	const time_t now = time(nullptr);
	tm localTime;

	localtime_s(&localTime, &now);

	return localTime;
}

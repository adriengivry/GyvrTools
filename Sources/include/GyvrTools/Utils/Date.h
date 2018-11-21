/**
* Project GyvrTools
* @author Adrien Givry
* @version 1.0
*/

#pragma once
#ifndef _GYVRTOOLS_DATE_H
#define _GYVRTOOLS_DATE_H

#include <string>
#include <ctime>

#include "GyvrTools/API/Export.h"

namespace GyvrTools::Utils
{
	/*
	* Set if static methods to get information on the current date
	*/
	class API_GYVRTOOLS Date final
	{
		/**
		* Contain information on a date. It is a templated struct
		*/
		template <class T>
		struct DateInfo
		{
			T year;
			T month;
			T day;
			T hours;
			T minutes;
			T seconds;

			/**
			* Return the DateInfo as a string
			* @param p_dateSeparator		= '-'
			* @param p_dateTimeSeparator	= '_'
			* @param p_timeSeparator		= '-'
			*/
			virtual std::string ToString(char p_dateSeparator = '-', char p_dateTimeSeparator = '_', char p_timeSeparator = '-') const = 0;

			/**
			* Send the DateInfo as a string to an ostream
			*/
			friend std::ostream& operator<<(std::ostream& p_ostream, const DateInfo<T>& p_dateInfo)
			{
				p_ostream << p_dateInfo.ToString();
				return p_ostream;
			}
		};

	public:
		/* Desactivate the constructor (Un-instanciable static class) */
		Date() = delete;

		struct FormattedDateInfo final : DateInfo<std::string>
		{
			/**
			* Return the FormattedDateInfo as a string
			*/
			std::string ToString(char p_dateSeparator = '-', char p_dateTimeSeparator = '_', char p_timeSeparator = '-') const
			{
				return 
					/* DATE */	year + p_dateSeparator + month + p_dateSeparator + day
					/* SEP. */	+ p_dateTimeSeparator
					/* TIME */	+ hours + p_timeSeparator + minutes + p_timeSeparator + seconds;
			}
		};

		struct RawDateInfo final : DateInfo<uint16_t>
		{
			/**
			* Return the RawDateInfo as a string
			*/
			std::string ToString(char p_dateSeparator = '-', char p_dateTimeSeparator = '_', char p_timeSeparator = '-') const
			{
				return 
					/* DATE */	std::to_string(year) + p_dateSeparator + std::to_string(month) + p_dateSeparator + std::to_string(day)
					/* SEP. */	+ p_dateTimeSeparator + std::to_string(hours)
					/* TIME */	+ p_timeSeparator + std::to_string(minutes) + p_timeSeparator + std::to_string(seconds);
			}
		};

		/**
		* Return the standard local time as a tm structure 
		*/
		static tm GetLocalTime();

		/**
		* Return the current date as raw data (uint16_t)
		*/
		static RawDateInfo GetDateRaw();

		/**
		* Return the current date as formatted data (std::string).
		* Month, day, hours, minutes and seconds starts by '0' if they are only one digit
		*/
		static FormattedDateInfo GetDateFormated();
	};
}

#endif // _GYVRTOOLS_DATE_H
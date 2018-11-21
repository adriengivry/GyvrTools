/**
* Project GyvrTools
* @author Adrien Givry
* @version 1.0
*/

#ifndef _GYVRTOOLS_EXPORT_H
#define _GYVRTOOLS_EXPORT_H
#pragma once

#pragma warning(disable : 4251)
#pragma warning(disable : 4275)

#ifdef GYVRTOOLS_EXPORT
	#define API_GYVRTOOLS __declspec(dllexport)
#else
	#define API_GYVRTOOLS __declspec(dllimport)
#endif // GYVRTOOLS_EXPORT

#endif // _GYVRTOOLS_EXPORT_H
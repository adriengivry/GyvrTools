/**
* Project GyvrTools
* @author Adrien Givry
* @version 1.0
*/

#pragma once
#ifndef _GYVRTOOLS_MATH_H
#define _GYVRTOOLS_MATH_H

#include "GyvrTools/API/Export.h"

namespace GyvrTools::Utils
{
	/**
	* Contains some static mathematics functions
	*/
	class API_GYVRTOOLS Math final
	{
	public:
		/* Desactivate the constructor (Un-instanciable static class) */
		Math() = delete;

		/**
		* Linearly interpolates between two values
		* @param p_a
		* @param p_b
		* @param p_alpha
		*/
		static float Lerp(float p_a, float p_b, float p_alpha);
	};
}

#endif // _GYVRTOOLS_MATH_H
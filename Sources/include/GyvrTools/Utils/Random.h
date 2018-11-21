/**
* Project GyvrTools
* @author Adrien Givry
* @version 1.0
*/

#pragma once
#ifndef _GYVRTOOLS_RANDOM_H
#define _GYVRTOOLS_RANDOM_H

#include <random>
#include <ctime>

#include "GyvrTools/API/Export.h"

namespace GyvrTools::Utils
{
	/**
	* Provides some static random number generation
	*/
	class API_GYVRTOOLS Random final
	{
	public:
		/* Desactivate the constructor (Un-instanciable static class) */
		Random() = delete;

		/**
		* Generate an integer between two numbers (Closed interval)
		* @param p_min
		* @param p_max
		*/
		static int Generate(int p_min, int p_max);

		/**
		* Generate a float between two numbers (Closed interval)
		* @param p_min
		* @param p_max
		*/
		static float Generate(float p_min, float p_max);

		/**
		* Calculate the probabilities of the given biniomal law
		* @param p_n: Number of experiments
		* @param p_p: Success probability
		*/
		static int Binomial(int p_n, float p_p);

		/**
		* Roll a dice to check if the given percentage is satisfied
		* @param p_percentage
		*/
		static bool TryPercentage(float p_percentage);

	private:
		static std::default_random_engine __GENERATOR;
	};
}

#endif // _GYVRTOOLS_RANDOM_H
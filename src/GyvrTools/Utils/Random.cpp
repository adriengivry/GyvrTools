#include "GyvrTools/Utils/Random.h"

std::default_random_engine GyvrTools::Utils::Random::__GENERATOR = std::default_random_engine(static_cast<unsigned int>(time(0)));

int GyvrTools::Utils::Random::Generate(int p_min, int p_max)
{
	std::uniform_int_distribution<int> distribution(p_min, p_max);
	return distribution(__GENERATOR);
}

float GyvrTools::Utils::Random::Generate(float p_min, float p_max)
{
	std::uniform_real_distribution<float> distribution(p_min, p_max);
	return distribution(__GENERATOR);
}

int GyvrTools::Utils::Random::Binomial(int p_n, float p_p)
{
	std::binomial_distribution<int> distribution(p_n, p_p);
	return distribution(__GENERATOR);
}

bool GyvrTools::Utils::Random::TryPercentage(float p_percentage)
{
	std::uniform_real_distribution<float> distribution(0.0f, 100.0f);
	return distribution(__GENERATOR) <= p_percentage;
}

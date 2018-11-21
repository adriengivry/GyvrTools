#include "GyvrTools/Utils/Math.h"

float GyvrTools::Utils::Math::Lerp(float p_a, float p_b, float p_alpha)
{
	return p_a + (p_b - p_a) * p_alpha;
}

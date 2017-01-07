#include "MathHelper.h"

#define _USE_MATH_DEFINES
#include <cmath>

namespace CFH
{
	const float MathHelper::PI = (float)M_PI;
	const float MathHelper::PIOver2 = (float)M_PI_2;
	const float MathHelper::PIOver4 = (float)M_PI_4;

	float MathHelper::Sqrt(float value)
	{
		float result;
		Sqrt(value, result);
		return result;
	}
	void MathHelper::Sqrt(float value, float& result)
	{
		result = sqrtf(value);
	}

	float MathHelper::Sin(float value)
	{
		float result;
		Sin(value, result);
		return result;
	}
	void MathHelper::Sin(float value, float& result)
	{
		result = sinf(value);
	}
	float MathHelper::Cos(float value)
	{
		float result;
		Cos(value, result);
		return result;
	}
	void MathHelper::Cos(float value, float& result)
	{
		result = cosf(value);
	}
	float MathHelper::Tan(float value)
	{
		float result;
		Tan(value, result);
		return result;
	}
	void MathHelper::Tan(float value, float& result)
	{
		result = tanf(value);
	}
	
	float MathHelper::ASin(float value)
	{
		float result;
		ASin(value, result);
		return result;
	}
	void MathHelper::ASin(float value, float& result)
	{
		result = asinf(value);
	}
	float MathHelper::ACos(float value)
	{
		float result;
		ACos(value, result);
		return result;
	}
	void MathHelper::ACos(float value, float& result)
	{
		result = acosf(value);
	}
	float MathHelper::ATan(float value)
	{
		float result;
		ATan(value, result);
		return result;
	}
	void MathHelper::ATan(float value, float& result)
	{
		result = atanf(value);
	}
	float MathHelper::ATan2(float v1, float v2)
	{
		float result;
		ATan2(v1, v2, result);
		return result;
	}
	void MathHelper::ATan2(float v1, float v2, float& result)
	{
		result = atan2f(v1, v2);
	}

	float MathHelper::Max(float a, float b)
	{
		float result;
		Max(a, b, result);
		return result;
	}
	void MathHelper::Max(float a, float b, float& result)
	{
		result = (a > b ? b : a);
	}
	float MathHelper::Min(float a, float b)
	{
		float result;
		Min(a, b, result);
		return result;
	}
	void MathHelper::Min(float a, float b, float& result)
	{
		result = (a < b ? b : a);
	}

	float MathHelper::Clamp(float value, float min, float max)
	{
		float result;
		Clamp(value, min, max, result);
		return result;
	}
	void MathHelper::Clamp(float value, float min, float max, float& result)
	{
		if (value < min)
			result = min;
		else if (value > max)
			result = max;
		else
			result = value;
	}

	float MathHelper::Abs(float value)
	{
		float result;
		Abs(value, result);
		return result;
	}
	void MathHelper::Abs(float value, float& result)
	{
		result = (value < 0 ? -value : value);
	}
}
#include "MathHelper.h"

#define _USE_MATH_DEFINES
#include <cmath>

namespace CFH
{
	namespace Math
	{
		const float MathHelper::PI = (float)M_PI;
		const float MathHelper::PIOver2 = (float)M_PI_2;
		const float MathHelper::PIOver4 = (float)M_PI_4;

		float MathHelper::Sqrt(float value)
		{
			return sqrtf(value);
		}
		void MathHelper::Sqrt(float value, float& result)
		{
			result = sqrtf(value);
		}

		float MathHelper::Sin(float value)
		{
			return sinf(value);
		}
		void MathHelper::Sin(float value, float& result)
		{
			result = sinf(value);
		}
		float MathHelper::Cos(float value)
		{
			return cosf(value);
		}
		void MathHelper::Cos(float value, float& result)
		{
			result = cosf(value);
		}
		float MathHelper::Tan(float value)
		{
			return tanf(value);
		}
		void MathHelper::Tan(float value, float& result)
		{
			result = tanf(value);
		}

		float MathHelper::ASin(float value)
		{
			return asinf(value);
		}
		void MathHelper::ASin(float value, float& result)
		{
			result = asinf(value);
		}
		float MathHelper::ACos(float value)
		{
			return acosf(value);
		}
		void MathHelper::ACos(float value, float& result)
		{
			result = acosf(value);
		}
		float MathHelper::ATan(float value)
		{
			return atanf(value);
		}
		void MathHelper::ATan(float value, float& result)
		{
			result = atanf(value);
		}
		float MathHelper::ATan2(float v1, float v2)
		{
			return atan2f(v1, v2);
		}
		void MathHelper::ATan2(float v1, float v2, float& result)
		{
			result = atan2f(v1, v2);
		}

		int MathHelper::Max(int a, int b)
		{
			return (a > b ? b : a);
		}
		void MathHelper::Max(int a, int b, int& result)
		{
			result = (a > b ? b : a);
		}
		float MathHelper::Max(float a, float b)
		{
			return (a > b ? b : a);
		}
		void MathHelper::Max(float a, float b, float& result)
		{
			result = (a > b ? b : a);
		}
		int MathHelper::Min(int a, int b)
		{
			return (a < b ? b : a);
		}
		void MathHelper::Min(int a, int b, int& result)
		{
			result = (a < b ? b : a);
		}
		float MathHelper::Min(float a, float b)
		{
			return (a < b ? b : a);
		}
		void MathHelper::Min(float a, float b, float& result)
		{
			result = (a < b ? b : a);
		}

		int MathHelper::Clamp(int value, int min, int max)
		{
			if (value < min)
				return min;
			else if (value > max)
				return max;
			else
				return value;
		}
		void MathHelper::Clamp(int value, int min, int max, int& result)
		{
			if (value < min)
				result = min;
			else if (value > max)
				result = max;
			else
				result = value;
		}
		float MathHelper::Clamp(float value, float min, float max)
		{
			if (value < min)
				return min;
			else if (value > max)
				return max;
			else
				return value;
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

		int MathHelper::Abs(int value)
		{
			return abs(value);
		}
		void MathHelper::Abs(int value, int& result)
		{
			result = abs(value);
		}
		float MathHelper::Abs(float value)
		{
			return fabs(value);
		}
		void MathHelper::Abs(float value, float& result)
		{
			result = fabs(value);
		}

		float MathHelper::DegreesToRadians(float value)
		{
			return value * (PI / 180);
		}
		void MathHelper::DegreesToRadians(float value, float& result)
		{
			result = value * (PI / 180);
		}

		float MathHelper::RadiansToDegrees(float value)
		{
			return value * (180 / PI);
		}
		void MathHelper::RadiansToDegrees(float value, float& result)
		{
			result = value * (180 / PI);
		}
	}
}
#include "Color.h"
#include "Vector3.h"
#include "Vector4.h"
#include "MathHelper.h"

#include <limits>

namespace CFH
{
	namespace Math
	{
		const Color Color::AliceBlue = Color(240, 248, 255);
		const Color Color::AntiqueWhite = Color(250, 235, 215);
		const Color Color::Aqua = Color(0, 255, 255);
		const Color Color::Aquamarine = Color(127, 255, 212);
		const Color Color::Azure = Color(240, 255, 255);
		const Color Color::Beige = Color(245, 245, 220);
		const Color Color::Bisque = Color(255, 228, 196);
		const Color Color::Black = Color(0, 0, 0);
		const Color Color::BlanchedAlmond = Color(255, 255, 205);
		const Color Color::Blue = Color(0, 0, 255);
		const Color Color::BlueViolet = Color(138, 43, 226);
		const Color Color::Brown = Color(165, 42, 42);
		const Color Color::BurlyWood = Color(22, 184, 135);
		const Color Color::CadetBlue = Color(95, 158, 160);
		const Color Color::Chartreuse = Color(127, 255, 0);
		const Color Color::Chocolate = Color(210, 105, 30);
		const Color Color::Coral = Color(255, 127, 80);
		const Color Color::CornflowerBlue = Color(100, 149, 237);
		const Color Color::Cornsilk = Color(255, 248, 220);
		const Color Color::Crimson = Color(220, 20, 60);
		const Color Color::Cyan = Color(0, 255, 255);
		const Color Color::DarkBlue = Color(0, 0, 139);
		const Color Color::DarkCyan = Color(0, 139, 139);
		const Color Color::DarkGoldenrod = Color(184, 134, 11);
		const Color Color::DarkGray = Color(169, 169, 169);
		const Color Color::DarkGreen = Color(0, 100, 0);
		const Color Color::DarkKhaki = Color(189, 183, 107);
		const Color Color::DarkMagena = Color(139, 0, 139);
		const Color Color::DarkOliveGreen = Color(85, 107, 47);
		const Color Color::DarkOrange = Color(255, 140, 0);
		const Color Color::DarkOrchid = Color(153, 50, 204);
		const Color Color::DarkRed = Color(139, 0, 0);
		const Color Color::DarkSalmon = Color(233, 150, 122);
		const Color Color::DarkSeaGreen = Color(143, 188, 143);
		const Color Color::DarkSlateBlue = Color(72, 61, 139);
		const Color Color::DarkSlateGray = Color(40, 79, 79);
		const Color Color::DarkTurquoise = Color(0, 206, 209);
		const Color Color::DarkViolet = Color(148, 0, 211);
		const Color Color::DeepPink = Color(255, 20, 147);
		const Color Color::DeepSkyBlue = Color(0, 191, 255);
		const Color Color::DimGray = Color(105, 105, 105);
		const Color Color::DodgerBlue = Color(30, 144, 255);
		const Color Color::Firebrik = Color(178, 34, 34);
		const Color Color::FloralWhite = Color(255, 250, 240);
		const Color Color::ForestGreen = Color(34, 139, 34);
		const Color Color::Fuschia = Color(255, 0, 255);
		const Color Color::Gainsboro = Color(220, 220, 220);
		const Color Color::GhostWhite = Color(248, 248, 255);
		const Color Color::Gold = Color(255, 215, 0);
		const Color Color::Goldenrod = Color(218, 165, 32);
		const Color Color::Gray = Color(128, 128, 128);
		const Color Color::Green = Color(0, 128, 0);
		const Color Color::GreenYellow = Color(173, 255, 47);
		const Color Color::Honeydew = Color(240, 255, 240);
		const Color Color::HotPink = Color(255, 105, 180);
		const Color Color::IndianRed = Color(205, 92, 92);
		const Color Color::Indigo = Color(75, 0, 130);
		const Color Color::Ivory = Color(255, 240, 240);
		const Color Color::Khaki = Color(240, 230, 140);
		const Color Color::Lavender = Color(230, 230, 250);
		const Color Color::LavenderBlush = Color(255, 240, 245);
		const Color Color::LawnGreen = Color(124, 252, 0);
		const Color Color::LemonChiffon = Color(255, 250, 205);
		const Color Color::LightBlue = Color(173, 216, 230);
		const Color Color::LightCoral = Color(240, 128, 128);
		const Color Color::LightCyan = Color(224, 255, 255);
		const Color Color::LightGoldenrodYellow = Color(250, 250, 210);
		const Color Color::LightGreen = Color(144, 238, 144);
		const Color Color::LightGray = Color(211, 211, 211);
		const Color Color::LightPink = Color(255, 182, 193);
		const Color Color::LightSalmon = Color(255, 160, 122);
		const Color Color::LightSeaGreen = Color(32, 178, 170);
		const Color Color::LightSkyBlue = Color(135, 206, 250);
		const Color Color::LightSlateGray = Color(119, 136, 153);
		const Color Color::LightSteelBlue = Color(176, 196, 222);
		const Color Color::LightYellow = Color(255, 255, 224);
		const Color Color::Lime = Color(0, 255, 0);
		const Color Color::LimeGreen = Color(50, 205, 50);
		const Color Color::Linen = Color(250, 240, 230);
		const Color Color::Magenta = Color(255, 0, 255);
		const Color Color::Maroon = Color(128, 0, 0);
		const Color Color::MediumAquamarine = Color(102, 205, 170);
		const Color Color::MediumBlue = Color(0, 0, 205);
		const Color Color::MediumOrchid = Color(186, 85, 211);
		const Color Color::MediumPurple = Color(147, 112, 219);
		const Color Color::MediumSeaGreen = Color(60, 179, 113);
		const Color Color::MediumSlateBlue = Color(123, 104, 238);
		const Color Color::MediumSpringGreen = Color(0, 250, 154);
		const Color Color::MediumTurquoise = Color(72, 209, 204);
		const Color Color::MediumVioletRed = Color(199, 21, 112);
		const Color Color::MidnightBlue = Color(25, 25, 112);
		const Color Color::MintCream = Color(245, 255, 250);
		const Color Color::MistyRose = Color(255, 228, 225);
		const Color Color::Moccasin = Color(255, 228, 181);
		const Color Color::NavajoWhite = Color(255, 222, 173);
		const Color Color::Navy = Color(0, 0, 128);
		const Color Color::OldLace = Color(253, 245, 230);
		const Color Color::Olive = Color(128, 128, 0);
		const Color Color::OliveDrab = Color(107, 142, 45);
		const Color Color::Orange = Color(255, 165, 0);
		const Color Color::OrangeRed = Color(255, 69, 0);
		const Color Color::Orchid = Color(218, 112, 214);
		const Color Color::PaleGoldenrod = Color(238, 232, 170);
		const Color Color::PaleGreen = Color(152, 251, 152);
		const Color Color::PaleTurquoise = Color(175, 238, 238);
		const Color Color::PaleVioletRed = Color(219, 112, 147);
		const Color Color::PapayaWhip = Color(255, 239, 213);
		const Color Color::PeachPuff = Color(255, 218, 155);
		const Color Color::Peru = Color(205, 133, 63);
		const Color Color::Pink = Color(255, 192, 203);
		const Color Color::Plum = Color(221, 160, 221);
		const Color Color::PowderBlue = Color(176, 224, 230);
		const Color Color::Purple = Color(128, 0, 128);
		const Color Color::Red = Color(255, 0, 0);
		const Color Color::RosyBrown = Color(188, 143, 143);
		const Color Color::RoyalBlue = Color(65, 105, 225);
		const Color Color::SaddleBrown = Color(139, 69, 19);
		const Color Color::Salmon = Color(250, 128, 114);
		const Color Color::SandyBrown = Color(244, 164, 96);
		const Color Color::SeaGreen = Color(46, 139, 87);
		const Color Color::Seashell = Color(255, 245, 238);
		const Color Color::Sienna = Color(160, 82, 45);
		const Color Color::Silver = Color(192, 192, 192);
		const Color Color::SkyBlue = Color(135, 206, 235);
		const Color Color::SlateBlue = Color(106, 90, 205);
		const Color Color::SlateGray = Color(112, 128, 144);
		const Color Color::Snow = Color(255, 250, 250);
		const Color Color::SpringGreen = Color(0, 255, 127);
		const Color Color::SteelBlue = Color(70, 130, 180);
		const Color Color::Tan = Color(210, 180, 140);
		const Color Color::Teal = Color(0, 128, 128);
		const Color Color::Thistle = Color(216, 191, 216);
		const Color Color::Tomato = Color(253, 99, 71);
		const Color Color::Transparent = Color(0, 0, 0, 0);
		const Color Color::Turquoise = Color(64, 224, 208);
		const Color Color::Violet = Color(238, 130, 238);
		const Color Color::Wheat = Color(245, 222, 179);
		const Color Color::White = Color(255, 255, 255);
		const Color Color::WhiteSmoke = Color(245, 245, 245);
		const Color Color::Yellow = Color(255, 255, 0);
		const Color Color::YellowGreen = Color(154, 205, 50);


		Color::Color() :
			R(0), G(0), B(0), A(0)
		{
		}
		Color::Color(unsigned char r, unsigned char g, unsigned char b)
		{
			R = r;
			G = g;
			B = b;
			A = UCHAR_MAX;
		}
		Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
		{
			R = r;
			G = g;
			B = b;
			A = a;
		}
		Color::Color(int r, int g, int b)
		{
			R = (unsigned char)MathHelper::Clamp(r * UCHAR_MAX, 0, UCHAR_MAX);
			G = (unsigned char)MathHelper::Clamp(g * UCHAR_MAX, 0, UCHAR_MAX);
			B = (unsigned char)MathHelper::Clamp(b * UCHAR_MAX, 0, UCHAR_MAX);
			A = UCHAR_MAX;
		}
		Color::Color(int r, int g, int b, int a)
		{
			R = (unsigned char)MathHelper::Clamp(r * UCHAR_MAX, 0, UCHAR_MAX);
			G = (unsigned char)MathHelper::Clamp(g * UCHAR_MAX, 0, UCHAR_MAX);
			B = (unsigned char)MathHelper::Clamp(b * UCHAR_MAX, 0, UCHAR_MAX);
			A = (unsigned char)MathHelper::Clamp(a * UCHAR_MAX, 0, UCHAR_MAX);
		}
		Color::Color(float r, float g, float b)
		{
			R = (unsigned char)MathHelper::Clamp((int)(r * UCHAR_MAX), 0, UCHAR_MAX);
			G = (unsigned char)MathHelper::Clamp((int)(g * UCHAR_MAX), 0, UCHAR_MAX);
			B = (unsigned char)MathHelper::Clamp((int)(b * UCHAR_MAX), 0, UCHAR_MAX);
			A = UCHAR_MAX;
		}
		Color::Color(float r, float g, float b, float a)
		{
			R = (unsigned char)MathHelper::Clamp((int)(r * UCHAR_MAX), 0, UCHAR_MAX);
			G = (unsigned char)MathHelper::Clamp((int)(g * UCHAR_MAX), 0, UCHAR_MAX);
			B = (unsigned char)MathHelper::Clamp((int)(b * UCHAR_MAX), 0, UCHAR_MAX);
			A = (unsigned char)MathHelper::Clamp((int)(a * UCHAR_MAX), 0, UCHAR_MAX);
		}
		Color::Color(std::initializer_list<unsigned char> list)
		{
			auto it = list.begin();
			R = *(it++);
			G = *(it++);
			B = *(it++);
			A = *(it++);
		}
		Color::Color(std::initializer_list<int> list)
		{
			auto it = list.begin();
			R = (unsigned char)MathHelper::Clamp(*(it++) * UCHAR_MAX, 0, UCHAR_MAX);
			G = (unsigned char)MathHelper::Clamp(*(it++) * UCHAR_MAX, 0, UCHAR_MAX);
			B = (unsigned char)MathHelper::Clamp(*(it++) * UCHAR_MAX, 0, UCHAR_MAX);
			A = (unsigned char)MathHelper::Clamp(*(it++) * UCHAR_MAX, 0, UCHAR_MAX);
		}
		Color::Color(std::initializer_list<float> list)
		{
			auto it = list.begin();
			R = (unsigned char)MathHelper::Clamp((int)(*(it++) * UCHAR_MAX), 0, UCHAR_MAX);
			G = (unsigned char)MathHelper::Clamp((int)(*(it++) * UCHAR_MAX), 0, UCHAR_MAX);
			B = (unsigned char)MathHelper::Clamp((int)(*(it++) * UCHAR_MAX), 0, UCHAR_MAX);
			A = (unsigned char)MathHelper::Clamp((int)(*(it++) * UCHAR_MAX), 0, UCHAR_MAX);
		}
		Color::~Color()
		{
		}

		Color Color::operator*(float value)
		{
			Color result;
			Multiply(*this, value, result);
			return result;
		}
		bool Color::operator==(const Color& color) const
		{
			return this->R == color.R &&
				this->G == color.G &&
				this->B == color.B &&
				this->A == color.A;
		}
		bool Color::operator!=(const Color& color) const
		{
			return this->R != color.R ||
				this->G != color.G ||
				this->B != color.B ||
				this->A != color.A;
		}
		const Color& Color::operator=(const Color& color)
		{
			this->R = color.R;
			this->G = color.G;
			this->B = color.B;
			this->A = color.A;
			return *this;
		}

		Color Color::Lerp(const Color& colorA, const Color& colorB, float amount)
		{
			Color result;
			Lerp(colorA, colorB, amount, result);
			return result;
		}
		void Color::Lerp(const Color& colorA, const Color& colorB, float amount, Color& result)
		{
			result.R = (unsigned char)(colorA.R + (int)((colorB.R - colorA.R) * amount));
			result.G = (unsigned char)(colorA.G + (int)((colorB.G - colorA.G) * amount));
			result.B = (unsigned char)(colorA.B + (int)((colorB.B - colorA.B) * amount));
			result.A = (unsigned char)(colorA.A + (int)((colorB.A - colorA.A) * amount));
		}
		Color Color::Multiply(const Color& color, float value)
		{
			Color result;
			Multiply(color, value, result);
			return result;
		}
		void Color::Multiply(const Color& color, float value, Color& result)
		{
			result.R = (unsigned char)MathHelper::Clamp((int)(color.R * value), 0, UCHAR_MAX);
			result.G = (unsigned char)MathHelper::Clamp((int)(color.G * value), 0, UCHAR_MAX);
			result.B = (unsigned char)MathHelper::Clamp((int)(color.B * value), 0, UCHAR_MAX);
			result.A = (unsigned char)MathHelper::Clamp((int)(color.A * value), 0, UCHAR_MAX);
		}

		Vector3 Color::ToVector3() const
		{
			Vector3 result;
			ToVector3(result);
			return result;
		}
		void Color::ToVector3(Vector3& result) const
		{
			result.X = (float)this->R / UCHAR_MAX;
			result.Y = (float)this->G / UCHAR_MAX;
			result.Z = (float)this->B / UCHAR_MAX;
		}
		Vector4 Color::ToVector4() const
		{
			Vector4 result;
			ToVector4(result);
			return result;
		}
		void Color::ToVector4(Vector4& result) const
		{
			result.X = (float)this->R / UCHAR_MAX;
			result.Y = (float)this->G / UCHAR_MAX;
			result.Z = (float)this->B / UCHAR_MAX;
			result.W = (float)this->A / UCHAR_MAX;
		}
	}
}

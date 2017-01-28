#pragma once
#include <initializer_list>

namespace CFH
{
	namespace Math
	{
		struct Vector3;
		struct Vector4;

		struct Color final
		{
			static const Color AliceBlue;
			static const Color AntiqueWhite;
			static const Color Aqua;
			static const Color Aquamarine;
			static const Color Azure;
			static const Color Beige;
			static const Color Bisque;
			static const Color Black;
			static const Color BlanchedAlmond;
			static const Color Blue;
			static const Color BlueViolet;
			static const Color Brown;
			static const Color BurlyWood;
			static const Color CadetBlue;
			static const Color Chartreuse;
			static const Color Chocolate;
			static const Color Coral;
			static const Color CornflowerBlue;
			static const Color Cornsilk;
			static const Color Crimson;
			static const Color Cyan;
			static const Color DarkBlue;
			static const Color DarkCyan;
			static const Color DarkGoldenrod;
			static const Color DarkGray;
			static const Color DarkGreen;
			static const Color DarkKhaki;
			static const Color DarkMagena;
			static const Color DarkOliveGreen;
			static const Color DarkOrange;
			static const Color DarkOrchid;
			static const Color DarkRed;
			static const Color DarkSalmon;
			static const Color DarkSeaGreen;
			static const Color DarkSlateBlue;
			static const Color DarkSlateGray;
			static const Color DarkTurquoise;
			static const Color DarkViolet;
			static const Color DeepPink;
			static const Color DeepSkyBlue;
			static const Color DimGray;
			static const Color DodgerBlue;
			static const Color Firebrik;
			static const Color FloralWhite;
			static const Color ForestGreen;
			static const Color Fuschia;
			static const Color Gainsboro;
			static const Color GhostWhite;
			static const Color Gold;
			static const Color Goldenrod;
			static const Color Gray;
			static const Color Green;
			static const Color GreenYellow;
			static const Color Honeydew;
			static const Color HotPink;
			static const Color IndianRed;
			static const Color Indigo;
			static const Color Ivory;
			static const Color Khaki;
			static const Color Lavender;
			static const Color LavenderBlush;
			static const Color LawnGreen;
			static const Color LemonChiffon;
			static const Color LightBlue;
			static const Color LightCoral;
			static const Color LightCyan;
			static const Color LightGoldenrodYellow;
			static const Color LightGreen;
			static const Color LightGray;
			static const Color LightPink;
			static const Color LightSalmon;
			static const Color LightSeaGreen;
			static const Color LightSkyBlue;
			static const Color LightSlateGray;
			static const Color LightSteelBlue;
			static const Color LightYellow;
			static const Color Lime;
			static const Color LimeGreen;
			static const Color Linen;
			static const Color Magenta;
			static const Color Maroon;
			static const Color MediumAquamarine;
			static const Color MediumBlue;
			static const Color MediumOrchid;
			static const Color MediumPurple;
			static const Color MediumSeaGreen;
			static const Color MediumSlateBlue;
			static const Color MediumSpringGreen;
			static const Color MediumTurquoise;
			static const Color MediumVioletRed;
			static const Color MidnightBlue;
			static const Color MintCream;
			static const Color MistyRose;
			static const Color Moccasin;
			static const Color NavajoWhite;
			static const Color Navy;
			static const Color OldLace;
			static const Color Olive;
			static const Color OliveDrab;
			static const Color Orange;
			static const Color OrangeRed;
			static const Color Orchid;
			static const Color PaleGoldenrod;
			static const Color PaleGreen;
			static const Color PaleTurquoise;
			static const Color PaleVioletRed;
			static const Color PapayaWhip;
			static const Color PeachPuff;
			static const Color Peru;
			static const Color Pink;
			static const Color Plum;
			static const Color PowderBlue;
			static const Color Purple;
			static const Color Red;
			static const Color RosyBrown;
			static const Color RoyalBlue;
			static const Color SaddleBrown;
			static const Color Salmon;
			static const Color SandyBrown;
			static const Color SeaGreen;
			static const Color Seashell;
			static const Color Sienna;
			static const Color Silver;
			static const Color SkyBlue;
			static const Color SlateBlue;
			static const Color SlateGray;
			static const Color Snow;
			static const Color SpringGreen;
			static const Color SteelBlue;
			static const Color Tan;
			static const Color Teal;
			static const Color Thistle;
			static const Color Tomato;
			static const Color Transparent;
			static const Color Turquoise;
			static const Color Violet;
			static const Color Wheat;
			static const Color White;
			static const Color WhiteSmoke;
			static const Color Yellow;
			static const Color YellowGreen;

		public:
			unsigned char R, G, B, A;

			Color();
			Color(unsigned char r, unsigned char g, unsigned char b);
			Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
			Color(int r, int g, int b);
			Color(int r, int g, int b, int a); 
			Color(float r, float g, float b);
			Color(float r, float g, float b, float a);
			Color(std::initializer_list<unsigned char> list);
			Color(std::initializer_list<int> list);
			Color(std::initializer_list<float> list);
			~Color();

			Color operator*(float value);
			bool operator==(const Color& color) const;
			bool operator!=(const Color& color) const;
			const Color& operator=(const Color& color);

			static Color Lerp(const Color& colorA, const Color& colorB, float amount);
			static void Lerp(const Color& colorA, const Color& colorB, float amount, Color& result);
			static Color Multiply(const Color& color, float value);
			static void Multiply(const Color& color, float value, Color& result);

			Vector3 ToVector3() const;
			void ToVector3(Vector3& result) const;
			Vector4 ToVector4() const;
			void ToVector4(Vector4& result) const;
		};
	}
}


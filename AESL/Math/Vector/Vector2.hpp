#pragma once

namespace AESL { namespace Math {

	template<class MathType>
	class TVector2 {

		using TVec2 = TVector2<MathType>;

	public:

		union {

			MathType m_Data[2];
			MathType X, Y;

		};

		TVector2(MathType X, MathType Y) : m_Data{ X, Y}
		{}

		TVector2(MathType Scalar) : m_Data{ Scalar, Scalar }
		{}

		TVector2() : m_Data{ 0,0 }
		{}

		TVector2(const TVec2& Other) : m_Data{ Other.m_Data[0], Other.m_Data[1]}
		{}

		void operator = (const TVec2& Other) {
		    memcpy(&m_data, &Other.m_Data, sizeof(MathType) * 2);
		}

		~TVector3() {}

		TVec2& Add(const TVec2& Other) {
			this->X += Other.X;
			this->Y += Other.Y;
			return *this;
		}

		TVec2& Subtract(const TVec2& Other) {
			this->X -= Other.X;
			this->Y -= Other.Y;
			return *this;
		}

		TVec2& Multiply(const TVec2& Other) {
			this->X *= Other.X;
			this->Y *= Other.Y;
			return *this;
		}

		TVec2& Divide(const TVec2& Other) {
			this->X /= Other.X;
			this->Y /= Other.Y;
			return *this;
		}

		friend TVec2 operator+(TVec2 Left, const TVec2& Right) { return Left.Add(Right); }
		friend TVec2 operator-(TVec2 Left, const TVec2& Right) { return Left.Subtract(Right); }
		friend TVec2 operator*(TVec2 Left, const TVec2& Right) { return Left.Multiply(Right); }
		friend TVec2 operator/(TVec2 Left, const TVec2& Right) { return Left.Divide(Right); }

		TVec2& operator+=(const TVec2& Other) { return this->Add(Other); }
		TVec2& operator-=(const TVec2& Other) { return this->Subtract(Other); }
		TVec2& operator*=(const TVec2& Other) { return this->Multiply(Other); }
		TVec2& operator/=(const TVec2& Other) { return this->Divide(Other); }

		bool operator==(const TVec2& Other) { return (this->X == Other.X && this->Y == Other.Y); }
		bool operator!=(const TVec2& Other) { return !(*this == Other); }

		void operator++() { X++; Y++; }
		void operator--() { X--; Y--; }

	};

	template<class MathType>
	using TVec2 = TVector2<MathType>;

	using Vec2 = TVec2<float>;
	using Vector2 = Vec2;

} }
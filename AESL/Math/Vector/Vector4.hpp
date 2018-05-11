#pragma once

namespace AESL { namespace Math {

	template<class MathType>
	class TVector4 {

		using TVec4 = TVector4<MathType>;

	public:

		union {
			MathType m_Data[4];
			struct { MathType X, Y, Z, W; };
		};

        template<class... EXArgs>
        TVector4(MathType X, MathType Y, MathType Z, MathType W, EXArgs&&... Ex) : m_Data{ X, Y, Z, W }
		{}

		TVector4(MathType X, MathType Y, MathType Z, MathType W) : m_Data{ X, Y, Z, W }
		{}

        TVector4(MathType X, MathType Y, MathType Z) : m_Data{ X, Y, Z, 0 }
		{}

        TVector4(MathType X, MathType Y) : m_Data{ X, Y, 0, 0 }
		{}

		TVector4(MathType Scalar) : m_Data{ Scalar, Scalar, Scalar }
		{}

		TVector4() : m_Data{ 0, 0, 0, 0 }
		{}

		TVector4(const TVec4& Other) : m_Data{ Other.m_Data[0], Other.m_Data[1], Other.m_Data[2], Other.m_Data[3] }
		{}

		void operator = (const TVec4& Other) {
		    memcpy(&m_Data, &Other.m_Data, sizeof(MathType) * 4);
		}

		~TVector4() {}

		TVec4& Add(const TVec4& Other) {
			this->X += Other.X;
			this->Y += Other.Y;
			this->Z += Other.Z;
			this->W += Other.W;
			return *this;
		}

		TVec4& Subtract(const TVec4& Other) {
			this->X -= Other.X;
			this->Y -= Other.Y;
			this->Z -= Other.Y;
			this->W -= Other.W;
			return *this;
		}

		TVec4& Multiply(const TVec4& Other) {
			this->X *= Other.X;
			this->Y *= Other.Y;
			this->Z *= Other.Z;
			this->W *= Other.W;
			return *this;
		}

		TVec4& Divide(const TVec4& Other) {
			this->X /= Other.X;
			this->Y /= Other.Y;
			this->Z /= Other.Z;
			this->W /= Other.W;
			return *this;
		}

		friend TVec4 operator+(TVec4 Left, const TVec4& Right) { return Left.Add(Right); }
		friend TVec4 operator-(TVec4 Left, const TVec4& Right) { return Left.Subtract(Right); }
		friend TVec4 operator*(TVec4 Left, const TVec4& Right) { return Left.Multiply(Right); }
		friend TVec4 operator/(TVec4 Left, const TVec4& Right) { return Left.Divide(Right); }

		TVec4& operator+=(const TVec4& Other) { return this->Add(Other); }
		TVec4& operator-=(const TVec4& Other) { return this->Subtract(Other); }
		TVec4& operator*=(const TVec4& Other) { return this->Multiply(Other); }
		TVec4& operator/=(const TVec4& Other) { return this->Divide(Other); }

		bool operator==(const TVec4& Other) {
			return (this->X == Other.X
				 && this->Y == Other.Y
				 && this->Z == Other.Z
				 && this->W == Other.W
			);
		}
		bool operator!=(const TVec4& Other) { return !(*this == Other); }

		void operator++() { X++; Y++; Z++; W++; }
		void operator--() { X--; Y--; Z--; W--; }

	};

	template<class MathType>
	using TVec4 = TVector4<MathType>;

	using Vec4 = TVec4<float>;
	using Vector4 = Vec4;

} }

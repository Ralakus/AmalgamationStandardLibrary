#pragma once
namespace AESL { namespace Math {

	template<class MathType>
	class TVector3 {

		using TVec3 = TVector3<MathType>;

	public:

		union {

			MathType m_Data[3];
			MathType X, Y, Z;
			MathType Yaw, Pitch, Roll;

		};

		TVector3(MathType X, MathType Y, MathType Z) : m_Data{ X, Y, Z }
		{}

		TVector3(MathType Scalar) : m_Data{ Scalar, Scalar, Scalar }
		{}

		TVector3() : m_Data{ 0,0,0 }
		{}

		TVector3(const TVec3& Other) : m_Data{ Other.m_Data[0], Other.m_Data[1], Other.m_Data[2] }
		{}

		void operator = (const TVec3& Other) {
			memcpy(&m_data, &Other.m_Data, sizeof(MathType) * 3);
		}

		~TVector3() {}

		TVec3& Add(const TVec3& Other) {
			this->X += Other.X;
			this->Y += Other.Y;
			this->Z += Other.Z;
			return *this;
		}

		TVec3& Subtract(const TVec3& Other) {
			this->X -= Other.X;
			this->Y -= Other.Y;
			this->Z -= Other.Z;
			return *this;
		}

		TVec3& Multiply(const TVec3& Other) {
			this->X *= Other.X;
			this->Y *= Other.Y;
			this->Z *= Other.Z;
			return *this;
		}

		TVec3& Divide(const TVec3& Other) {
			this->X /= Other.X;
			this->Y /= Other.Y;
			this->Z /= Other.Z;
			return *this;
		}

		friend TVec3 operator+(TVec3 Left, const TVec3& Right) { return Left.Add(Right); }
		friend TVec3 operator-(TVec3 Left, const TVec3& Right) { return Left.Subtract(Right); }
		friend TVec3 operator*(TVec3 Left, const TVec3& Right) { return Left.Multiply(Right); }
		friend TVec3 operator/(TVec3 Left, const TVec3& Right) { return Left.Divide(Right); }

		TVec3& operator+=(const TVec3& Other) { return this->Add(Other); }
		TVec3& operator-=(const TVec3& Other) { return this->Subtract(Other); }
		TVec3& operator*=(const TVec3& Other) { return this->Multiply(Other); }
		TVec3& operator/=(const TVec3& Other) { return this->Divide(Other); }

		bool operator==(const TVec3& Other) { return (this->X == Other.X && this->Y == Other.Y && this->Z == Other.Z); }
		bool operator!=(const TVec3& Other) { return !(*this == Other); }

		void operator++() { X++; Y++; Z++; }
		void operator--() { X--; Y--; Z--; }

	};

	template<class MathType>
	using TVec3 = TVector3<MathType>;

	using Vec3    = TVec3<float>;
	using Vector3 =  Vec3;

} }

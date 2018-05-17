#pragma once

#include "../../Math/MathDefines.hpp"
#include "../TypeStruct.hpp"
#include "../../Platform/Typedef.hpp"

#include <cmath>

namespace AESL { namespace Math {

	union DataVec4 {
		TypeStruct<MATH_TYPE, 4> Data;
		struct { MATH_TYPE X, Y, Z, W; };
	};

	using DVector4 = DataVec4;

	//======================================================================
	// Simple Data Vector Math Operations
	//======================================================================
	FORCEINLINE DataVec4 operator + (const DataVec4& L, const DataVec4& R) {
		return DataVec4{
			L.X + R.X, L.Y + R.Y, L.Z + R.Z, L.W + R.W
		};
	}
	FORCEINLINE DataVec4 operator - (const DataVec4& L, const DataVec4& R) {
		return DataVec4{
			L.X - R.X, L.Y - R.Y, L.Z - R.Z, L.W - R.W
		};
	}
	FORCEINLINE DataVec4 operator * (const DataVec4& L, const DataVec4& R) {
		return DataVec4{
			L.X * R.X, L.Y * R.Y, L.Z * R.Z, L.W * R.W
		};
	}
	FORCEINLINE DataVec4 operator / (const DataVec4& L, const DataVec4& R) {
		return DataVec4{
			L.X / R.X, L.Y / R.Y, L.Z / R.Z, L.W / R.W
		};
	}

	//Scalar operations

	template<class T>
	FORCEINLINE DataVec4 operator + (const DataVec4& L, T Scalar) {
		return DataVec4{
			L.X + Scalar, L.Y + Scalar, L.Z + Scalar, L.W + Scalar
		};
	}
	template<class T>
	FORCEINLINE DataVec4 operator - (const DataVec4& L, T Scalar) {
		return DataVec4{
			L.X - Scalar, L.Y - Scalar, L.Z - Scalar, L.W - Scalar
		};
	}
	template<class T>
	FORCEINLINE DataVec4 operator * (const DataVec4& L, T Scalar) {
		return DataVec4{
			L.X * Scalar, L.Y * Scalar, L.Z * Scalar, L.W * Scalar
		};
	}
	template<class T>
	FORCEINLINE DataVec4 operator / (const DataVec4& L, T Scalar) {
		return DataVec4{
			L.X / Scalar, L.Y / Scalar, L.Z / Scalar, L.W / Scalar
		};
	}

	//======================================================================
	// Data Vector Data Modifying Math Operations
	//======================================================================
	FORCEINLINE DataVec4& operator += (DataVec4& L, const DataVec4& R) {
		L.X += R.X; L.Y += R.Y; L.Z += R.Z; L.W += R.W;
		return L;
	}
	FORCEINLINE DataVec4& operator -= (DataVec4& L, const DataVec4& R) {
		L.X -= R.X; L.Y -= R.Y; L.Z -= R.Z; L.W -= R.W;
		return L;
	}
	FORCEINLINE DataVec4& operator *= (DataVec4& L, const DataVec4& R) {
		L.X *= R.X; L.Y *= R.Y; L.Z *= R.Z; L.W *= R.W;
		return L;
	}
	FORCEINLINE DataVec4& operator /= (DataVec4& L, const DataVec4& R) {
		L.X /= R.X; L.Y /= R.Y; L.Z /= R.Z; L.W /= R.W;
		return L;
	}

	//Scalar operations

	template<class T>
	FORCEINLINE DataVec4& operator += (DataVec4& L, T Scalar) {
		L.X += Scalar; L.Y += Scalar; L.Z += Scalar; L.W += Scalar;
		return L;
	}
	template<class T>
	FORCEINLINE DataVec4& operator -= (DataVec4& L, T Scalar) {
		L.X -= Scalar; L.Y -= Scalar; L.Z -= Scalar; L.W -= Scalar;
		return L;
	}
	template<class T>
	FORCEINLINE DataVec4& operator *= (DataVec4& L, T Scalar) {
		L.X *= Scalar; L.Y *= Scalar; L.Z *= Scalar; L.W *= Scalar;
		return L;
	}
	template<class T>
	FORCEINLINE DataVec4& operator /= (DataVec4& L, T Scalar) {
		L.X /= Scalar; L.Y /= Scalar; L.Z /= Scalar; L.W /= Scalar;
		return L;
	}

	//======================================================================
	// Simple Data Vector Math Functions
	//======================================================================
	FORCEINLINE DataVec4 Dot(const DataVec4& L, const DataVec4& R) {
		return { L.X * R.X + L.Y * R.Y + L.Z * R.Z + L.W * R.W };
	}

	FORCEINLINE MATH_TYPE Length(const DataVec4& Vec) {
		return sqrt(Vec.X * Vec.X + Vec.Y * Vec.Y + Vec.Z * Vec.Z + Vec.W * Vec.W);
	}

	FORCEINLINE DataVec4 Normalize(DataVec4& Vec) {
		return { Vec /= Length(Vec) };
	}
} }
#pragma once

#include <Core/Math/Vector/Vector4.hpp>

namespace AESL { namespace Math {

	template<class MathType>
	class Matrix4x4 {

	private:

		TVector4<MathType> m_Data[4];

	};

} }

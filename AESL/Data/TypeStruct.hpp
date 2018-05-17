#pragma once

namespace AESL {

	template<class T, unsigned long Size>
	struct TypeStruct {
		T Data[Size];
	};

	template<class T, unsigned long Size>
	TypeStruct<T, Size> operator + (const TypeStruct<T, Size>& Left, const TypeStruct<T, Size>& Right) {
		TypeStruct<T, Size> R;
		for (unsigned long i = 0; i < Size; i++) {
			R.Data[i] = Left.Data[i] + Right.Data[i];
		}
		return R;
	}
	template<class T, unsigned long Size>
	TypeStruct<T, Size> operator - (const TypeStruct<T, Size>& Left, const TypeStruct<T, Size>& Right) {
		TypeStruct<T, Size> R;
		for (unsigned long i = 0; i < Size; i++) {
			R.Data[i] = Left.Data[i] - Right.Data[i];
		}
		return R;
	}
	template<class T, unsigned long Size>
	TypeStruct<T, Size> operator * (const TypeStruct<T, Size>& Left, const TypeStruct<T, Size>& Right) {
		TypeStruct<T, Size> R;
		for (unsigned long i = 0; i < Size; i++) {
			R.Data[i] = Left.Data[i] * Right.Data[i];
		}
		return R;
	}
	template<class T, unsigned long Size>
	TypeStruct<T, Size> operator / (const TypeStruct<T, Size>& Left, const TypeStruct<T, Size>& Right) {
		TypeStruct<T, Size> R;
		for (unsigned long i = 0; i < Size; i++) {
			R.Data[i] = Left.Data[i] / Right.Data[i];
		}
		return R;
	}
}

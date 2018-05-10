#pragma once

namespace AESL {

	class Noncopyable {
	private:
		Noncopyable(const Noncopyable& Other) = delete;
	public:
		Noncopyable() {}
		virtual ~Noncopyable() {}

	};

}

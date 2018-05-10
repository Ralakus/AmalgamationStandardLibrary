#pragma once

#include <Core/Lua/LuaState.hpp>
#include <chrono>

namespace AESL {

	class Time {

		std::chrono::system_clock::time_point m_Start;
		std::chrono::system_clock::time_point m_TP1;
		std::chrono::system_clock::time_point m_TP2;
		std::chrono::duration<float> m_DeltaTime;

		bool m_OnSecond = false;
		float m_Timer = 0.f;

		float m_Delta = 0.f;

		//FPS Averager

		unsigned int m_FIS = 0;       //Total frames in a second
		float m_FPSIS = 0.f;   //Total frames per second in second
		float m_AVGFPS = 0.f; //Average FPS

	public:

		Time() : m_Start(std::chrono::system_clock::now()), m_TP1(std::chrono::system_clock::now()), m_TP2(std::chrono::system_clock::now()), m_DeltaTime(m_TP2 - m_TP1) {}
		~Time() {}

		inline void Update() {
			m_TP2 = std::chrono::system_clock::now();
			m_DeltaTime = m_TP2 - m_TP1;
			m_TP1 = m_TP2;

			m_Delta = m_DeltaTime.count();

			m_OnSecond = false;

			m_Timer += m_Delta;
			m_FPSIS += 1 / m_Delta;
			m_FIS++;

			if (m_Timer >= 1.f) {
				m_AVGFPS = m_FPSIS / (float)m_FIS;
				m_Timer = 0.f;
				m_OnSecond = true;
			}

		}

		inline float GetDelta()   const { return m_Delta; }

		inline float GetElapsed() const { return ((float)(m_TP1 - m_Start).count() / 10000000); }

		inline bool  OnSecond()   const { return m_OnSecond; }

		inline float GetAvgFPS()  const { return m_AVGFPS; }

		inline float GetFPS()     const { return 1.f / m_DeltaTime.count(); }


		REGISTER_TO_LUA_STACK(
			LuaState::GetAENamespace().new_usertype<Time>( "Time",

				sol::constructors<Time()>(),
				"Update", &Time::Update,
				"GetDelta", &Time::GetDelta,
				"GetElapsed", &Time::GetElapsed,
				"OnSecond", &Time::OnSecond,
				"GetAvgFPS", &Time::GetAvgFPS,
				"GetFPS", &Time::GetFPS

			);
		);

	};
}
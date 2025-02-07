#pragma once
#include "CommonInclude.h"

namespace mj
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { m_name = name; }
		std::wstring& GetName() { return m_name; }
 
	private:
		std::wstring m_name;
	};
}


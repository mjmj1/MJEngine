#pragma once
#include "mjEntity.h"

namespace mj
{
	class Resource : public Entity // 추상 클래스
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0;
		
		const std::wstring& GetPath() { return m_path; }
		void SetPath(const std::wstring& path) { m_path = path; }

	private:
		const enums::eResourceType m_type;
		std::wstring m_path;
	};

	// class Texture : public Resource;
	// class AudioClip : public Resource;
}
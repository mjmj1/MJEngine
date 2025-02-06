#include "mjInput.h"

namespace mj
{
	std::vector<Input::Key> Input::m_keys = {};
	
	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
	};

	void Input::Initialize()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;
			
			m_keys.push_back(key);
		}
	}

	void Input::Update()
	{
		for (size_t i = 0; i < m_keys.size(); i++)
		{
			if (GetAsyncKeyState(ASCII[i]) & 0x8000) // 키가 눌림
			{
				if (m_keys[i].bPressed == true)
				{
					m_keys[i].state = eKeyState::Pressed;
				}
				else
				{
					m_keys[i].state = eKeyState::Down;
				}

				m_keys[i].bPressed = true;
			}
			else // 키가 안눌림
			{
				if (m_keys[i].bPressed == true)
				{
					m_keys[i].state = eKeyState::Up;
				}
				else
				{
					m_keys[i].state = eKeyState::None;
				}

				m_keys[i].bPressed = false;
			}
		}
	}
}

#pragma once
#include <map>
#include <string>

#include "Animation.h"

namespace HW
{
	class Sprite
	{
	public:
		Sprite( void );
		~Sprite( void );
		void Update(float deltaTime);
		void AddAnimation(Animation animation, std::string name);
		void PlayAnimation(std::string name);
	protected:
	private:
		std::map<std::string, Animation> _animations;
	};
}

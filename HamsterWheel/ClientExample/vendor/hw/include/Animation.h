#pragma once
#include "Texture.h"
#include <string>

namespace HW
{
	class Animation : public Texture
	{
	public:
		Animation(std::string path, float fps);
		~Animation();
	private:
		int			_frameWidth;
		int			_frameHeight;
		int			_nFrames;
		int			_currentFrame;
		float		_fps;
		bool		_isPlaying;

		void Update(float delta_time) override;
	};
}

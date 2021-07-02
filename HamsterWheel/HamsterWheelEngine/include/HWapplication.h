#pragma once

namespace HW
{	

	class HWapplication
	{
	public:
		void Render();
		virtual void OnRender() = 0;
		void Update();
		virtual void OnUpdate() = 0;
		void Init();
		virtual void OnInit() = 0;

		HWapplication();
	private:
		;
	};

	HWapplication* CreateApplication();
}

#pragma once

namespace HW
{	

	class HWapplication
	{
	public:
		void Render();
		virtual void OnRender();
		void Update();
		virtual void OnUpdate();
		void Init();
		virtual void OnInit();

		HWapplication();
	private:
	};

	HWapplication* CreateApplication();
}

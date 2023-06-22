#pragma once

class VisualElement{

	private:
		position pos;
		u32 color;
		bool filled;


	public:
		VisualElement();
		VisualElement(position pos, u32 color, bool filled);

		void setPosition(position pos);
		void setColor(u32 color);
		void setFilled(bool filled);

		position getPosition();
		u32 getColor();
		bool getFilled();

}

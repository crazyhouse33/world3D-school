
#include <GLFW/glfw3.h>
class Interface{
	public:	

		Interface(int width, int height);
		void getMousePosition(double* receiveX, double* receiveY);
		float getRatio();
		bool windowShouldClose();
		void refreshBuffer();
		void threatEvents();
		void quit();
	private:
		GLFWwindow* window;

		float ratio;
};

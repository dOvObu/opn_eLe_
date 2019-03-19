# opn_eLe_
shortcuts for glew, glfw and soil2

## getting started snippent
```cpp
int main ()
{
	opnWindow win ("hi", 800, 600);
	if (win.problems ()) { return 1; }
	opnFreeCamera cam;
	opnProfileCamera cam2;
	defaultSettings (win, &cam, &cam2);
	
	opnMat4 view, projection;
	win.setPerspective (projection);
	
	float t = 0.f;
	
	while (win.isOpen ())
	{
		currentCamera->dt = glfwGetTime () - t;
		t = static_cast<float>(glfwGetTime ());
		win.events ();
		opnInput::process (win);
		currentCamera->loadTo (view);

		win.clear (0.95f, 0.95f, 0.95f);
		win.swap ();
	}
	return 0;
}
```
  

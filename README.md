# opn_eLe_
shortcuts for glew, glfw and soil2

## getting started snippent
###### main.cpp
```cpp
#include "opn.h"
#include <cmath>

int main ()
{
	opnWindow win ("hi", 800, 600);
	if (win.problems ()) { return 1; }
	opnFreeCamera cam;
	opnProfileCamera cam2;
	defaultSettings (win, &cam, &cam2);
		
	opnShader shad ("core.vert", "core.frag");
	opnBox box (shad,"img2.png");
	
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

		box.tr.rotate (t, 0.5f+std::sinf(t), 1, -1);
		
		win.clear (0.95f, 0.95f, 0.95f);
		shad.use ();
		shad.viewAndProjection (view, projection);
		box.draw ();
		win.swap ();
	}
	return 0;
}
```

###### core.vert
```glsl
#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;

out vec2 TexCoord;

uniform mat4 transform;
uniform mat4 projection;
uniform mat4 view;

void main()
{
    gl_Position = projection * view * transform * vec4(position, 1.0f);
    TexCoord = vec2(texCoord.x, 1.0 - texCoord.y);
}
```

###### core.frag
```glsl
#version 330 core
in vec2 TexCoord;

out vec4 color;

uniform sampler2D ourTexture;

void main()
{
	color = texture(ourTexture, TexCoord);
}
```

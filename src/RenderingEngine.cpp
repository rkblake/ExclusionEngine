#include "RenderingEngine.h"

void RenderingEngine::ComputeMatrices() {
    int x_pos, y_pos;
    SDL_GetMouseState(&x_pos, &y_pos);

    if(isFocus) {
        SDL_WarpMouseInWindow(window.GetWindow(), _width/2, _height/2);
        horizontalAngle += mouseSpeed * (_width/2 - x_pos);
        verticalAngle += mouseSpeed * (_height/2 - y_pos);
    }

    if(camera_style == FREE_LOOK) {
        direction = glm::vec3(
    		cos(verticalAngle) * sin(horizontalAngle),
    		sin(verticalAngle),
    		cos(verticalAngle) * cos(horizontalAngle)
    	);

        right = glm::vec3(
    		sin(horizontalAngle - 3.14f/2.0f),
    		0,
    		cos(horizontalAngle - 3.14f/2.0f)
    	);

    	front = glm::vec3(
    		sin(horizontalAngle - 3.14f/2.0f),
    		0,
    		0);

        up = glm::vec3(0,1,0);

        projection_matrix = glm::perspective(fov, 4.0f / 3.0f, 0.1f, 100.0f);
    	view_matrix = glm::lookAt(position, position+direction, up);
    }
    else if(camera_style == FIRST_PERSON) {
        //direction = attached_entity->GetDirection();
        //float
        //right = glm::vec3()

    }
    else {

    }
}

Window* RenderingEngine::CreateWindow(const char* title, int width, int height) {
    //probably better to grab values from config script here than from inside main
    _width = width;
    _height = height;
    window = Window(title, width, height);
    return &window;
}

void RenderingEngine::Swap() {
    window.SwapBuffers();
}

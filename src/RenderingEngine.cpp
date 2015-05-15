//#include "Window.h"

#include "RenderingEngine.h"



void ComputeMatrices() {

}

glm::mat4 GetProjectionMatrix() {

}

glm::mat4 GetViewMatrix() {

}

void RenderingEngine::CreateWindow(const char* title, int width, int height) {
    window = Window(title, width, height);
}

void RenderingEngine::Swap() {
    window.SwapBuffers();
}

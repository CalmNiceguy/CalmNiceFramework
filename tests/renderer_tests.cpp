#include "catch.hpp"
#include "renderer.h"

TEST_CASE("Renderer Initialization", "[renderer]") {
    
    auto renderer = CNF::CreateRenderer(CNF::RendererType::DX12);


    int windowWidth = 800;
    int windowHeight = 600;
    void* windowHandle = nullptr;

    REQUIRE(renderer.Initialize(windowWidth, windowHeight, windowHandle));

    renderer.Shutdown();
}

TEST_CASE("Draw Triangle", "[renderer]") {
    CNF::Renderer renderer;
    int windowWidth = 800;
    int windowHeight = 600;
    void* windowHandle = nullptr;

    REQUIRE(renderer.Initialize(windowWidth, windowHeight, windowHandle));

    CNF::Vertex v1 = { 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
    CNF::Vertex v2 = { 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f };
    CNF::Vertex v3 = { 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f };

    CNF::Triangle triangle(v1, v2, v3);

    renderer.BeginFrame();

    // As in the Google Test example, this is hard to test in a unit test.
    renderer.DrawTriangle(triangle);

    renderer.EndFrame();

    renderer.Shutdown();
}
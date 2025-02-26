#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "Scene.h"
#include "TextComponent.h"
#include "TextureComponent.h"
#include "FPSComponent.h"
#include "GameObject.h"
#include "RotationComponent.h"


void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	// add textures
	auto go = std::make_shared<dae::GameObject>();
	auto texture1 = std::make_shared<dae::TextureComponent>(go,"background.tga");
	go->AddComponent(texture1);
	scene.Add(go);
	
	go = std::make_shared<dae::GameObject>();
	auto texture2 = std::make_shared<dae::TextureComponent>(go,"logo.tga");
	go->SetLocalPosition(glm::vec3{ 216, 180,0 });
	go->AddComponent(texture2);
	scene.Add(go);

	// add text
	go = std::make_shared<dae::GameObject>();
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto tc = std::make_shared<dae::TextComponent>(go,"Programming 4 Assignment", font);
	go->SetLocalPosition(glm::vec3{ 80, 20,0 });
	go->AddComponent(tc);
	scene.Add(go);

	// add FPS counter
	go = std::make_shared<dae::GameObject>();
	auto fpstc = std::make_shared<dae::TextComponent>(go,"FPS", font);
	go->AddComponent(fpstc);
	auto fps = std::make_shared<dae::FPSComponent>(go);
	go->AddComponent(fps);
	go->SetLocalPosition(glm::vec3{ 80, 60,0 });
	scene.Add(go);
	

	// SPRITES
	//--------

	// add bubblun 
	auto root = std::make_shared<dae::GameObject>();
	root->SetLocalPosition(glm::vec3{ 200, 200,0 });

	auto bubblun = std::make_shared<dae::GameObject>();
	auto bubblunTexture = std::make_shared<dae::TextureComponent>(bubblun, "Bubblun.png");
	bubblun->AddComponent(bubblunTexture);
	auto bubblunRotation = std::make_shared<dae::RotationComponent>(bubblun, -10.f, 10.f);
	bubblun->AddComponent(bubblunRotation);

	bubblun->SetParent(root.get(), false);


	// add bobblun 
	auto bobblun = std::make_shared<dae::GameObject>();
	auto bobblunTexture = std::make_shared<dae::TextureComponent>(bobblun, "Bobblun.png");
	bobblun->AddComponent(bobblunTexture);
	auto bobblunRotation = std::make_shared<dae::RotationComponent>(bobblun, 10.f, 30.f);
	bobblun->AddComponent(bobblunRotation);

	bobblun->SetParent(bubblun.get(), false);

	scene.Add(root);
	scene.Add(bubblun);
	scene.Add(bobblun);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}
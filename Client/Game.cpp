#include "pch.h"
#include "Game.h"
#include "Engine.h"

shared_ptr<Mesh> mesh = make_shared<Mesh>();
shared_ptr<Shader> shader = make_shared<Shader>();

void Game::Init(const WindowInfo& info)
{
	GEngine->Init(info);

	// 삼각형 만들기
	vector<Vertex> vec(3);
	vec[0].pos = Vec3(0.f, 0.5f, 0.5f);
	vec[0].color = Vec4(1.f, 0.f, 0.f, 1.f);
	vec[1].pos = Vec3(0.5f, -0.5f, 0.5f);
	vec[1].color = Vec4(0.f, 1.0f, 0.f, 1.f);
	vec[2].pos = Vec3(-0.5f, -0.5f, 0.5f);
	vec[2].color = Vec4(0.f, 0.f, 1.f, 1.f);
	mesh->Init(vec); // GPU에게 버퍼 생성 요청 -> view 생성

	shader->Init(L"..\\Resources\\Shader\\default.hlsli"); // 테스트용 경로 하드코딩

	GEngine->GetCmdQueue()->WaitSync();
}

void Game::Update()
{
	GEngine->RenderBegin();

	shader->Update();
	mesh->Render();

	GEngine->RenderEnd();
}

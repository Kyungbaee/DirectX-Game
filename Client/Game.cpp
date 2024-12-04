#include "pch.h"
#include "Game.h"
#include "Engine.h"

shared_ptr<Mesh> mesh = make_shared<Mesh>();
shared_ptr<Shader> shader = make_shared<Shader>();
shared_ptr<Texture> texture = make_shared<Texture>();


void Game::Init(const WindowInfo& info)
{
	GEngine->Init(info);

	// 사각형 만들기
	vector<Vertex> vec(4);
	vec[0].pos = Vec3(-0.5f, 0.5f, 0.5f);
	vec[0].color = Vec4(1.f, 0.f, 0.f, 1.f);
	vec[0].uv = Vec2(0.f, 0.f);
	vec[1].pos = Vec3(0.5f, 0.5f, 0.5f);
	vec[1].color = Vec4(0.f, 1.f, 0.f, 1.f);
	vec[1].uv = Vec2(1.f, 0.f);
	vec[2].pos = Vec3(0.5f, -0.5f, 0.5f);
	vec[2].color = Vec4(0.f, 0.f, 1.f, 1.f);
	vec[2].uv = Vec2(1.f, 1.f);
	vec[3].pos = Vec3(-0.5f, -0.5f, 0.5f);
	vec[3].color = Vec4(0.f, 1.f, 0.f, 1.f);
	vec[3].uv = Vec2(0.f, 1.f);

	vector<uint32> indexVec;
	{
		indexVec.push_back(0);
		indexVec.push_back(1);
		indexVec.push_back(2);
	}
	{
		indexVec.push_back(0);
		indexVec.push_back(2);
		indexVec.push_back(3);
	}

	mesh->Init(vec, indexVec); // GPU에게 버퍼 생성 요청 -> view 생성

	shader->Init(L"..\\Resources\\Shader\\default.hlsli"); // 테스트용 경로 하드코딩

	texture->Init(L"..\\Resources\\Texture\\happy.jpg"); // 테스트용 이미지

	GEngine->GetCmdQueue()->WaitSync();
}

void Game::Update()
{
	GEngine->RenderBegin();
	shader->Update();

	{
		Transform t;
		t.offset = Vec4(0.25f, 0.25f, 0.2f, 0.f);
		mesh->SetTransform(t);
		mesh->SetTexture(texture);
		mesh->Render();
	}

	{
		Transform t;
		t.offset = Vec4(0.f, 0.f, 0.3f, 0.f);
		mesh->SetTransform(t);
		mesh->SetTexture(texture);
		mesh->Render();
	}

	mesh->Render();

	GEngine->RenderEnd();
}

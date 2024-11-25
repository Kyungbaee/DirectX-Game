#pragma once


class Engine
{
public:

	void Init(const WindowInfo& info);
	void Render();

	void RenderBegin(); // CommandQueue에 일감을 쌓는 과정
	void RenderEnd(); // gpu에 뷰(요청서)를 외주를 맡기는 과정 

	void ResizeWindow(int32 width, int32 height);

private:
	// 그려질 화면 크기 관련
	WindowInfo _window;
	D3D12_VIEWPORT _viewport = {};
	D3D12_RECT _scissorRect = {};

	shared_ptr<class Device> _device;
	shared_ptr<class CommandQueue> _cmdQueue;
	shared_ptr<class SwapChain> _swapChain;
	shared_ptr<class DescriptorHeap> _descHeap;
};


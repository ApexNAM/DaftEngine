#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>

using std::cout;
using std::endl;

class DaftGame
{
public:
	DaftGame(); // 생성자
	~DaftGame(); // 소멸자

	// 처음 시작할때 실행되는 Init 함수
	void Init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);
	
	void HandleEvents(); // 입력 관련 이벤트 함수
	void Update(); // 업데이트 함수
	void Render(); // 렌더링 함수 
	void EndClear(); // 종료 함수

	// 엔진이 실행되고 있는가?
	bool RunningEngine() { return isRunning; }
private:
	int cnt = 0;
	bool isRunning; // 프로그램 실행 여부 
	SDL_Window* window; // 창 (윈도우) 
	SDL_Renderer* renderer; // 렌더러 
};


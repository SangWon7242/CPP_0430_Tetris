#include "Header.h"
#define INTERVAL 1.0/60.0


int main() {

	float prev = (float)clock() / CLOCKS_PER_SEC; // 프로그램 시작한 순간부터 몇초가 지났는지 알 수 있다.
	Display* display = new Display();
	GameEngine* gameEngine = new GameEngine();
	showConsoleCursor(false); // 윈도우에서 커서키가 보이지 않게 하는 것

	while (true) {
		float curr = (float)clock() / CLOCKS_PER_SEC;
		float dt = curr - prev; // 반복 될 때마다 발생하는 차이 

		if (dt < INTERVAL) continue; // 정해주는 1/60 보다 작다면 처음으로 돌아가게
		prev = curr;

		// printf("%.3f\n", curr);

		bool left = keyState('a');
		bool right = keyState('d');
		bool down = keyState('s');

		if (left) {
			// 왼쪽으로 블록 이동
			gameEngine->next(dt, 'a');
		}
		else if (right) {
			// 오른쪽으로 블록 이동
			gameEngine->next(dt, 'd');
		}
		else if (down) {
			// 아래쪽으로 블록 이동
			gameEngine->next(dt, 's');
		}
		else {
			// 그냥 블록 떨어짐
			gameEngine->next(dt, 0); // 다음 연산시 꼭 델타 타입을 넣어줘야함.
		}

		// 화면 출력
		gameEngine->makeDisplayData();
		display->draw();
		// 게임상테 판별
	}

	return 0;
}


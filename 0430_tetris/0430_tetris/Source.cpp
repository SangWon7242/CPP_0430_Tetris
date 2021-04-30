#include "Header.h"
#define INTERVAL 1.0/60.0


int main() {

	float prev = (float)clock() / CLOCKS_PER_SEC; // ���α׷� ������ �������� ���ʰ� �������� �� �� �ִ�.
	Display* display = new Display();
	GameEngine* gameEngine = new GameEngine();
	showConsoleCursor(false); // �����쿡�� Ŀ��Ű�� ������ �ʰ� �ϴ� ��

	while (true) {
		float curr = (float)clock() / CLOCKS_PER_SEC;
		float dt = curr - prev; // �ݺ� �� ������ �߻��ϴ� ���� 

		if (dt < INTERVAL) continue; // �����ִ� 1/60 ���� �۴ٸ� ó������ ���ư���
		prev = curr;

		// printf("%.3f\n", curr);

		bool left = keyState('a');
		bool right = keyState('d');
		bool down = keyState('s');

		if (left) {
			// �������� ��� �̵�
			gameEngine->next(dt, 'a');
		}
		else if (right) {
			// ���������� ��� �̵�
			gameEngine->next(dt, 'd');
		}
		else if (down) {
			// �Ʒ������� ��� �̵�
			gameEngine->next(dt, 's');
		}
		else {
			// �׳� ��� ������
			gameEngine->next(dt, 0); // ���� ����� �� ��Ÿ Ÿ���� �־������.
		}

		// ȭ�� ���
		gameEngine->makeDisplayData();
		display->draw();
		// ���ӻ��� �Ǻ�
	}

	return 0;
}


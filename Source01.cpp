#include "DxLib.h"

// �v���O������ WinMain ����n�܂�܂�
int Key[256];

int GetHitKeyStateAll_2(int GetHitKeyStateAll_InputKey[]) {
	char GetHitKeyStateAll_Key[256];
	GetHitKeyStateAll(GetHitKeyStateAll_Key);
	for (int i = 0; i<256; i++) {
		if (GetHitKeyStateAll_Key[i] == 1) GetHitKeyStateAll_InputKey[i]++;
		else                            GetHitKeyStateAll_InputKey[i] = 0;
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	int RefreshTime;

	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) return -1;

	SetDrawScreen(DX_SCREEN_BACK);                  //����ʂ��g�p����B

	while (ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll_2(Key) == 0 && Key[KEY_INPUT_ESCAPE] == 0) {
		//��ү���ޏ���       �@  ����ʂ�ر    �@�@�@    �����͏�Ԃ�ۑ��@�@�@�@�@�@�@��ESC��������Ă��Ȃ�
		RefreshTime = GetNowCount();               //���̎��Ԃ��擾

		ScreenFlip();                             //����ʃf�[�^��\��ʂ֔��f

		while (GetNowCount() - RefreshTime < 17);   //1���̏�����17�~���b�ɂȂ�܂ő҂�
	}

	DxLib_End();
	return 0;
}
#include "DxLib.h"

// プログラムは WinMain から始まります
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

	SetDrawScreen(DX_SCREEN_BACK);                  //裏画面を使用する。

	while (ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll_2(Key) == 0 && Key[KEY_INPUT_ESCAPE] == 0) {
		//↑ﾒｯｾｰｼﾞ処理       　  ↑画面をｸﾘｱ    　　　    ↑入力状態を保存　　　　　　　↑ESCが押されていない
		RefreshTime = GetNowCount();               //今の時間を取得

		ScreenFlip();                             //裏画面データを表画面へ反映

		while (GetNowCount() - RefreshTime < 17);   //1周の処理が17ミリ秒になるまで待つ
	}

	DxLib_End();
	return 0;
}
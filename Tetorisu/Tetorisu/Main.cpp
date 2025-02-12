#include "Dxlib.h"
#include "Date.h"
#include "Draw.h"
#include "BoxAdmin.h"

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevinstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(800, 800, 32);			//ウィンドウサイズとカラービット数の指定
	ChangeWindowMode(TRUE);				//ウィンドウモードをON
	if (DxLib_Init() == -1) return -1;	//DXライブラリの初期化、エラーで終了
	SetDrawScreen(DX_SCREEN_BACK);		//裏画面へ描画（ダブルバッファ）
	//初期化処理



	//ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		
		ClearDrawScreen();	//画面をクリアする
		//縦22*横10
		//ブロックを落下させる関数、上から数えると一瞬でした目で行く→下から数える→if文がおかしくてバグる
		//if文を改良して正しいものに改良する(それができれば落下の処理は完成)

	
		char keyBuf[256];

		GetHitKeyStateAll(keyBuf);		//キーの入力状態の取得


		
		//マス関連
		for (int i = WidthSize+1; -1 < i; i--)
		{
			for (int j = HeightSize; 0 < j; j--)
			{
			
				//落下しきってからブロックを消したい
				
			
				DrawGame(j, i);
				
				DropBox(j, i);
				

				//checkBoxClear();
			}
		}
		

		if (Dropflg == false)//ブロックが地面に設置されているなら
		{
			checkBoxClear();
		}
		Dropflg = false;

		if (keyBuf[KEY_INPUT_RIGHT] == 1&& px < 10)
		{
			px += 1;
			map[py][px] = 1;
			map[py + 1][px] = 1;
			map[py][px-1] = 0;
			map[py + 1][px-1] = 0;
		}
		if (keyBuf[KEY_INPUT_LEFT] == 1&& px > 1)
		{
			px -= 1;
			map[py][px] = 1;
			map[py + 1][px] = 1;
				map[py][px + 1] = 0;
			map[py + 1][px + 1] = 0;
		}
		
		if (keyBuf[KEY_INPUT_SPACE] == 1)
		{
			//checkBoxClear();
			if (PurBotonflg == false)
			{
				map[py][px] = 1;
				map[py+1][px] = 1;
				
				PurBotonflg = true;
			}
		}
		else
		{
			PurBotonflg = false;
		}

				
	
		ScreenFlip();			//裏画面の内容を表画面に反映
		WaitTimer(50);			//一定時間待つ　※これがないと一瞬で描画されてしまう
	}
	DxLib_End();	//DXライブラリの終了処理
	return 0;		//終了
}

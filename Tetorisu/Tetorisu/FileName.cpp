#include "Dxlib.h"
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevinstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(800, 600, 32);			//ウィンドウサイズとカラービット数の指定
	ChangeWindowMode(TRUE);				//ウィンドウモードをON
	if (DxLib_Init() == -1) return -1;	//DXライブラリの初期化、エラーで終了
	SetDrawScreen(DX_SCREEN_BACK);		//裏画面へ描画（ダブルバッファ）
	//初期化処理
	float px, py = 500; 		//自機のxy座標
	float pw = 64, ph = 64;	//自機の幅、高さ
	float bx, by;				//弾のxy座標
	float bvx = 3, bvy = -10;	//弾の速度ベクトル
	float bw = 64, bh = 64;	//弾のxy座標、幅、高さ
	bool bflag = FALSE;			//弾のフラグ
	//ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		ClearDrawScreen();	//画面をクリアする

		//続く
		//続き
		//入力チェック・状態の更新
		int tmpx, tmpy;
		GetMousePoint(&tmpx, &tmpy);	//マウス座標の取得※ポインタ渡し
		px = tmpx;						//マウス座標のうちx座標のみ自機のx座標へ
		//弾の移動処理
		if (bflag == TRUE)
		{
			bx = bx + bvx;		//x成分の移動処理
			by = by + bvy;		//y成分の移動処理
			if (by < 0 - bh)	 	//画面外に出たら(yが0未満)
			{
				bflag = FALSE;	//弾を非表示
			}
		}
		//弾の発射判定
		if (bflag == FALSE && GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			bflag = TRUE;
			bx = px;
			by = py;
		}

		//続く
		//続き

		//描画処理
		DrawBox(px, py, px + pw, py + ph, 0x0000ff, TRUE);		//自機の描画　※敵の後⇒敵の上に描画
		if (bflag == TRUE) {
			DrawBox(bx, by, bx + bw, by + bh, 0x00ffff, TRUE);	//弾の描画 ※自機の後⇒自機の上に描画
		}
		ScreenFlip();			//裏画面の内容を表画面に反映
		WaitTimer(33);			//一定時間待つ　※これがないと一瞬で描画されてしまう
	}
	DxLib_End();	//DXライブラリの終了処理
	return 0;		//終了
}

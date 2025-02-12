#include "Dxlib.h"
#include "Date.h"
#include "Draw.h"
#include "BoxAdmin.h"
#include "Score.h"


int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevinstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(800, 800, 32);			//ウィンドウサイズとカラービット数の指定
	ChangeWindowMode(TRUE);				//ウィンドウモードをON
	if (DxLib_Init() == -1) return -1;	//DXライブラリの初期化、エラーで終了
	SetDrawScreen(DX_SCREEN_BACK);		//裏画面へ描画（ダブルバッファ）
	//初期化処理

	LoadDivGraph("puyo.png", 96, 6, 16, 32, 32, puyoimg);

	while ( CheckHitKey(KEY_INPUT_M) == 0) 
		{
		}

	//ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		ClearDrawScreen();	//画面をクリアする
		

	

		//ブロック落下のタイミング→自機ブロックが地面に触れる→ブロックの削除→落下処理→自機の移動開始
		//狭いとこでの回転が心配→erse if文が原因
		//上記二つは落下のタイミングの問題
		
		//else if (map[py[2] + 1][px[1] - 1] != 0 &&map[py[2] + 1][px[1] + 1] == 0)//そのまま回転すると壁またはブロックにめり込んでしまう場合
		//上の左の式いらない(念のため)
		 
		//描画＝アンリアル　＋　プログラム＝C＋

		//チェックボックス→横一列なら可能(5個以上の場合一番左が削除されない)
		//必要判定:上、四角、その他

		//次のブロック描画→できてるけど汚い

		//ブロックの判定→左から下がめり込んでしまう→重力→操作受付にしたら改善

		//ブロックの回転が片方を中心とした回転になっていない→できたけど汚い
	
		//削除後の配列の中身が変？→DropBoxがきれいでない→できた(配列が変だった)



		//縦が削除されると上のブロックも消される
		

	//ここからまだできてない

		//上下左右の検証の際、for文を使って行数を節約する
		//UIにこだわる＋画像を本物のぷよに差し替え

		//関数でreturnで値を返し代入させる？
		//voidは値を返さない場合に使用。返す場合は型名+関数名

		//破裂アニメの時点でも破裂前の絵が存在する


		if (GameStart == false)
		{
			BirthBox();
			GameStart = true;
		}
	


				DrawGame();//ゲームの描画
			
			
				GravityDropBox();//一定間隔で落下させる

				PlayerControl();//プレイヤーの操作受付

			
			//ブロックがどちらも床に触れていたら
			if (TouchGround[1] == true && TouchGround[2] == true)
			{
				if (map[2][3] == 0)//上の×にブロックが置かれていないなら
				{
					
					checkBoxClear();//ブロックを消す
						
					DropBox();//ブロックを落下させる
			
					if (DropFlg == false && ChackClearflg == false )//落下中のブロックがないなら
					{
						BirthBox();
					
					}
					
				}
				else
				{
					DrawFormatString(600, 220, GetColor(255, 255, 255), "ゲームオーバー");
				}
			}
			else
			{
				map[py[1]][px[1]] = SetColor[1];
				map[py[2]][px[2]] = SetColor[2];
			}

				//コメントを隠すボックス
			DrawBox(0, 0, 177, 800, 0x000000, true);
			
		
		ScreenFlip();			//裏画面の内容を表画面に反映
		WaitTimer(50);			//一定時間待つ　※これがないと一瞬で描画されてしまう
	}
	DxLib_End();	//DXライブラリの終了処理
	return 0;		//終了
}

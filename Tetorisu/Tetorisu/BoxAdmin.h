#pragma once

#include "Score.h"

#ifndef __BOXADMIN_H__

#define  __BOXADMIN_H__


void ClearBox(int j, int i, bool Clearflg);


//jが縦iが横

//Boxを落下させる.
void DropBox()//map[y][x]
{
	DropFlg = false;
	
		for (int i = WidthSize + 1; -1 < i; i--)
		{
			for (int j = HeightSize; -1 < j; j--)
			{
				
				//消してからこの処理を行う
				if ((map[j][i] != 0 &&map[j][i] != 1)&& (map[j + 1][i] == 0 && j + 1 != HeightSize-1))//マップの下が空いていて一番下でなければ
				{
				
					DropFlg = true;
					ChackClearflg = true;
					map[j + 1][i] = map[j][i];
					map[j][i] = 0;
					DrawGame();
					WaitTimer(20);
				}
			}
		}
	
}

//横一列に箱が並んでいないか判定
void checkBoxClear()//
{
	int px = 0;
	int py = 0;
	int BoxCnt = 0;
	//ブロックが完全に落下しきってから調べる
	if (DropFlg == true)
	{
		return ;
	}

	for (int c = 2; c <= 5; c++)//いろの数文ループ(0,1は空白、壁)
	{
		ChackClearflg = false;
		//よこはんてい
		for (int i = -1; i < WidthSize + 1; i++)
		{
			for (int j = 0; j < HeightSize; j++)
			{
			
				if (map[j][i] == c)
				{
					 //0は下.1左.2上.3右
					ChackBoxY[BoxCnt] = j;
					ChackBoxX[BoxCnt] = i;
					ChackBoxColor[BoxCnt] = map[ChackBoxY[BoxCnt]][ChackBoxX[BoxCnt]];
					map[j + py][i + px] = 0;
					BoxCnt += 1;
				
					//最初の地点から探索を始める
					for (int k = 0; k < BoxCnt; k++)
					{
						//下・左・上・右
						//k = 0で新たなブロックを発見できたら戦闘から検証しなおすようにしている
						//k = 0ではない、別のfor文の先頭への戻り方がありそう
						if (map[ChackBoxY[k] + 1][ChackBoxX[k]] == c)
						{

							ChackBoxY[BoxCnt] = ChackBoxY[k] + 1;
							ChackBoxX[BoxCnt] = ChackBoxX[k];
							ChackBoxColor[BoxCnt] = map[ChackBoxY[BoxCnt]][ChackBoxX[BoxCnt]];
							map[ChackBoxY[BoxCnt]][ChackBoxX[BoxCnt]] = 0;
							BoxCnt += 1;
							k = 0;
						}
						else if (map[ChackBoxY[k]][ChackBoxX[k]-1] == c)
						{

							ChackBoxY[BoxCnt] = ChackBoxY[k];
							ChackBoxX[BoxCnt] = ChackBoxX[k]-1;
							ChackBoxColor[BoxCnt] = map[ChackBoxY[BoxCnt]][ChackBoxX[BoxCnt]];
							map[ChackBoxY[BoxCnt]][ChackBoxX[BoxCnt]] = 0;
							BoxCnt += 1;
							k = 0;
						}
						else if (map[ChackBoxY[k] - 1][ChackBoxX[k]] == c)
						{

							ChackBoxY[BoxCnt] = ChackBoxY[k] - 1;
							ChackBoxX[BoxCnt] = ChackBoxX[k];
							ChackBoxColor[BoxCnt] = map[ChackBoxY[BoxCnt]][ChackBoxX[BoxCnt]];
							map[ChackBoxY[BoxCnt]][ChackBoxX[BoxCnt]] = 0;
							BoxCnt += 1;	
							k = 0;

						}
						else if (map[ChackBoxY[k]][ChackBoxX[k] + 1] == c)
						{

							ChackBoxY[BoxCnt] = ChackBoxY[k];
							ChackBoxX[BoxCnt] = ChackBoxX[k] + 1;
							ChackBoxColor[BoxCnt] = map[ChackBoxY[BoxCnt]][ChackBoxX[BoxCnt]];
							map[ChackBoxY[BoxCnt]][ChackBoxX[BoxCnt]] = 0;
							BoxCnt += 1;
							k = 0;
						}
					}

					//T字の場合等もすべて検証し上でブロックが4個以下なら
					if (BoxCnt < 4)//ブロックのつながりが4以下なら確認で消したブロックを再度配置し直す
					{
						for (int i = 0; i <= BoxCnt; i++)
						{
							map[ChackBoxY[i]][ChackBoxX[i]] = ChackBoxColor[i];
						}
						
					}
					else//4個以上つながっているなら
					{

						//ここでぷよがはじけるアニメーション

						for (int i = 0; i <= BoxCnt;i++)
						{
							DrawDestroy(ChackBoxX[i], ChackBoxY[i], ChackBoxColor[i]);
							
						}
						DrawGame();
						
						ChackClearflg = true;
						DropFlg = true;
						WaitTimer(300);



						AddScore(BoxCnt * 30);
						
					}

						
					
					//各種データをリセットして再度検証できるようにする
					for (int i = 0; i < 30; i++)
					{
						ChackBoxY[i] = 0;
						ChackBoxX[i] = 0;
						ChackBoxColor[i] = 0;
					
					}

					
					px = 0;
					py = 0;
					BoxCnt = 0;
					
				}
				
			}
		}
	}

	
	
}

void PlayerControl()
{
	char keyBuf[256];

	GetHitKeyStateAll(keyBuf);		//キーの入力状態の取得


	if (keyBuf[KEY_INPUT_RIGHT] == 1) //どちらかのブロックが地面に触れていなければ)
	{
		if (TouchGround[1] == false && TouchGround[2] == false)
		{
			BottonCnt[1] += 1;
			//前にブロックがないなら&ボタン長押し

			if (BottonCnt[1] % PutBottonSpan[1] == 0 || BottonCnt[1] == 1)//ボタンが長押しされている又は押された瞬間なら
			{
				if (ReturnBox == 1 || ReturnBox == 3)
				{

					if (map[py[1]][px[1] + 1] == 0 )//横に何もないなら
					{
						px[1] += 1;
						px[2] += 1;
						map[py[1]][px[1] - 1] = 0;
						map[py[2]][px[2] - 1] = 0;
						//	BottonCnt[1] = 2;
					}
				}
				else
				{
					if (map[py[1]][px[1] + 1] == 0 && map[py[2]][px[2] + 1] == 0)//横に何もないなら
					{
						px[1] += 1;
						px[2] += 1;
						map[py[1]][px[1] - 1] = 0;
						map[py[2]][px[2] - 1] = 0;
						//	BottonCnt[1] = 2;
					}
				}
			}
		}
	}
	else
	{
		BottonCnt[1] = 0;
	}

	if (keyBuf[KEY_INPUT_LEFT] == 1)
	{
		if (TouchGround[1] == false && TouchGround[2] == false)
		{
			BottonCnt[2] += 1;

			if (BottonCnt[2] % PutBottonSpan[1] == 0 || BottonCnt[2] == 1)//ボタンが長押しされている又は押された瞬間なら
			{
				if (ReturnBox == 1 || ReturnBox == 3)//回転が0または2の時
				{

					if ( map[py[2]][px[2] - 1] == 0)
					{
						px[1] -= 1;
						px[2] -= 1;
						map[py[1]][px[1] + 1] = 0;
						map[py[2]][px[2] + 1] = 0;
					}
				}
				else
				{
					
					if ((map[py[1]][px[1] - 1] == 0 && map[py[2]][px[2] - 1] == 0))
					{
						px[1] -= 1;
						px[2] -= 1;
						map[py[1]][px[1] + 1] = 0;
						map[py[2]][px[2] + 1] = 0;						
					}
				}
			}
		}



	}
	else
	{
		BottonCnt[2] = 0;
	}


	if (keyBuf[KEY_INPUT_DOWN] == 1)
	{
		if (TouchGround[1] == false && TouchGround[2] == false)//ぷよが空中にいるなら
		{
			DropSpeed += 5;
		}
	}
	

	if (keyBuf[KEY_INPUT_SPACE] == 1 && (TouchGround[1] == false && TouchGround[2] == false))
	{
		BottonCnt[0] += 1;
		if (BottonCnt[0] % PutBottonSpan[0] == 0 || BottonCnt[0] == 1)//ボタンが長押しまたは押された瞬間なら
		{

			//上から左に回転するとき、ブロックにめりこんでしまう→if文でめり込まないようにする

			if (ReturnBox == 0)//上から左
			{
				if (map[py[2] + 1][px[1] - 1] == 0)//移動先が空なら
				{
					px[2] -= 1;
					py[2] += 1;
					map[py[2] - 1][px[2] + 1] = 0;
					ReturnBox += 1;
				}

				else if (map[py[2] + 1][px[1] - 1] != 0 &&map[py[2] + 1][px[1] + 1] == 0)//そのまま回転すると壁またはブロックにめり込んでしまう場合
				{	
					px[1] += 1;
					py[2] += 1;
					map[py[1]][px[1] - 1] = 0;
					map[py[2] - 1][px[2]] = 0;
					ReturnBox += 1;
				}

			}

			else if (ReturnBox == 1)//左から下
			{
				if (map[py[1] + 1][px[1]] == 0)//移動先が空なら
				{
					px[2] += 1;
					py[1] += 1;
					map[py[2]][px[2] - 1] = 0;
					ReturnBox += 1;

					SetColor[0] = SetColor[1];
					SetColor[1] = SetColor[2];
					SetColor[2] = SetColor[0];

				}
				else if (map[py[1] + 1][px[1]] != 0)//そのまま回転すると壁またはブロックにめり込んでしまう場合
				{
					px[2] += 1;
					py[2] -= 1;
					
					map[py[2]+1][px[2] - 1] = 0;
					ReturnBox += 1;
					SetColor[0] = SetColor[1];
					SetColor[1] = SetColor[2];
					SetColor[2] = SetColor[0];
				}
				
			}
			else if (ReturnBox == 2)//下から右
			{
			    if (map[py[2]][px[2] + 1] == 0)//移動先が空なら
				{
					px[1] += 1;
					py[1] -= 1;
					map[py[1] + 1][px[1]-1] = 0;
					ReturnBox += 1;
					
				}	 
				 else if (map[py[2]][px[2] + 1] != 0 && map[py[2]][px[2] - 1] == 0)//そのまま回転すると壁またはブロックにめり込んでしまう場合
				 {
					 px[2] -= 1;
					 py[1] -= 1;
					 map[py[1]+1][px[1]] = 0;
					 ReturnBox += 1;
					
				 }
			}

			else if (ReturnBox == 3)//右から上
			{

				px[1] -= 1;
				py[2] -= 1;
				map[py[2] + 1][px[2] + 1] = 0;

				ReturnBox = 0;
				SetColor[0] = SetColor[1];
				SetColor[1] = SetColor[2];
				SetColor[2] = SetColor[0];
			}
		}
	}
	else
	{
		BottonCnt[0] = 0;
	}



}

void GravityDropBox()//一定間隔で落下
{
	DropSpeed += 1;
	if (DropSpeed > DropSpan)//一定間隔で実行
	{
		if (map[py[1] + 1][px[1]] == 0 && py[1] != HeightSize-2)// || (map[py[1] + 1][px[1]] == map[py[2]][px[2]] &&TouchGround[2] == false))

		{
			py[1] += 1;
			map[py[1] - 1][px[1]] = 0;
		}
		else
		{
			TouchGround[1] = true;

		}
		if (map[py[2] + 1][px[2]] == 0 && py[2] != HeightSize-2)//|| (map[py[2] + 1][px[2]] == map[py[1]][px[1]] && TouchGround[1] == false))
		{
			py[2] += 1;
			map[py[2] - 1][px[2]] = 0;
		}
		else
		{
			TouchGround[2] = true;

		}


		DropSpeed = 0;
	}

	//片方が床に触れたら早くする
	if (TouchGround[1] == true || TouchGround[2] == true)
	{
		DropSpeed += 5;
	}

}


void BirthBox()
{
	
	if (SetColor[1] ==0 || SetColor[2] == 0)
	{
		StaySetColor[1] = GetRand(3) + 2;  //3.2
		StaySetColor[2] = GetRand(3) + 2;
	}

	SetColor[1] = StaySetColor[1];
    SetColor[2] = StaySetColor[2];

	

	StaySetColor[1] = GetRand(3) + 2;
	StaySetColor[2] = GetRand(3) + 2;

	

	px[1] = 3;
	px[2] = 3;
	py[1] = 1;
	py[2] = 0;
	TouchGround[1] = false;
	TouchGround[2] = false;
	ReturnBox = 0;
	


}


#endif
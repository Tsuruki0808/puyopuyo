#pragma once

#ifndef __DRAW_H__

#define __DRAW_H_

void DrawGame()
{
	for (int i = 0; i < WidthSize; i++)
	{
		for (int j = 2; j < HeightSize; j++)
		{
			DrawBox(180 + (i * BoxSize), j * BoxSize, 180 + ((i + 1) * BoxSize), ((j + 1) * BoxSize), 0xffffff, false);//枠の表示



			DrawBox(180 + 3 * BoxSize + 15, BoxSize * 2 + 15, 180 + 4 * BoxSize - 15, BoxSize * 3 - 15, 0xffffff, true);//ミスしるしの表示
			//DrawLine(180 + 3 * BoxSize, 0, 180 + 4 * BoxSize, BoxSize, 0xf00fff, true);

		//	DrawTriangle(180 + 3 * BoxSize+(BoxSize/2), BoxSize/2 -5, 180 + 3 * BoxSize, BoxSize,180 + 4*BoxSize,BoxSize, 0xffffff, true);
			//DrawTriangle(180 + 3 * BoxSize + (BoxSize / 2), BoxSize / 2+5, 180 + 3 * BoxSize, 0, 180 + 4 * BoxSize, 0, 0xffffff, true);
			//数字の表示
			DrawFormatString(160, j * BoxSize, GetColor(255, 255, 255), "%d", j - 2);//画面買いに似ますがある
			DrawFormatString(180 + i * BoxSize, BoxSize * (HeightSize + 2), GetColor(255, 255, 255), "%d", i);

			DrawFormatString(0, 0, GetColor(255, 255, 255), "ChackCnt =%d", ChackCnt);

			DrawFormatString(0, 40, GetColor(255, 255, 255), "py[1] =%d", py[1]);
			DrawFormatString(0, 60, GetColor(255, 255, 255), "py[2] =%d", py[2]);
			DrawFormatString(0, 80, GetColor(255, 255, 255), "px[1] =%d", px[1]);
			DrawFormatString(0, 100, GetColor(255, 255, 255), "px[2] =%d", px[2]);
			DrawFormatString(0, 120, GetColor(255, 255, 255), "ReturnBox =%d", ReturnBox);
			DrawFormatString(0, 140, GetColor(255, 255, 255), "上から左=%d", map[py[2] + 1][px[2] - 1]);
			DrawFormatString(0, 160, GetColor(255, 255, 255), "上から右=%d", map[py[2] + 1][px[2] + 1]);
			DrawFormatString(0, 180, GetColor(255, 255, 255), "ボタン1=%d", BottonCnt[1]);
			DrawFormatString(0, 200, GetColor(255, 255, 255), "ボタン2=%d", BottonCnt[2]);
			DrawFormatString(0, 220, GetColor(255, 255, 255), "DropFlg=%d", DropFlg);
			DrawFormatString(0, 240, GetColor(255, 255, 255), "ChackClearflg=%d", ChackClearflg);

			DrawFormatString(0, 260, GetColor(255, 255, 255), "kakunin=%d", kakuninnum);


			
			DrawFormatString(600, 260, GetColor(255, 255, 255), "Score:%d", Score);



			//DrawBox(BoxSize * (px[1] + 1), (py[2] + 1) * BoxSize, ((px[1]  + 2) * BoxSize), ((py[2]  + 2) * BoxSize), 0xfffff, true);
			//map[py[2] + 1][px[1] + 1] == 0)


			if (map[j][i] != 0)
			{
				if (map[j][i] == 1)//白枠
				{
					DrawBox(180 + (i * BoxSize + 5), j * BoxSize + 5, 180 + ((i + 1) * BoxSize - 5), ((j + 1) * BoxSize - 5), 0xffffff, true);

				
				}
				if (map[j][i] == 2)//赤
				{
					DrawExtendGraph(180 + (i * BoxSize), j * BoxSize , 180 + ((i + 1) * BoxSize), ((j + 1) * BoxSize ), puyoimg[0], TRUE);

				
				}
				if (map[j][i] == 3)//緑
				{
					DrawExtendGraph(180 + (i * BoxSize), j * BoxSize , 180 + ((i + 1) * BoxSize), ((j + 1) * BoxSize ), puyoimg[1], TRUE);

					
				}
				if (map[j][i] == 4)//青
				{
					DrawExtendGraph(180 + (i * BoxSize), j * BoxSize , 180 + ((i + 1) * BoxSize), ((j + 1) * BoxSize), puyoimg[2], TRUE);

					
				}
				if (map[j][i] == 5)//黄色
				{
					DrawExtendGraph(180 + (i * BoxSize ), j * BoxSize , 180 + ((i + 1) * BoxSize), ((j + 1) * BoxSize), puyoimg[3], TRUE);

					
				}
				

			}
			
			
				
				

			
		}
	}


	for (int i = 0; i<3; i++)
	{
		
		if (StaySetColor[i] != 0)
		{
			if (StaySetColor[i] == 2)//赤
			{
				SetC[i] = 0xff0000;
			}
			if (StaySetColor[i] == 3)//緑
			{
				SetC[i] = 0x00ff00;
			}
			if (StaySetColor[i] == 4)//青
			{
				SetC[i] = 0x0000ff;
			}
			if (StaySetColor[i] == 5)//黄色
			{
				SetC[i] = 0xffff00;
			}
			
			
				
		}

	}
	DrawBox(600, 50, 660, 150, 0xffffff, false);
	DrawBox(555+ BoxSize + 5,1 * BoxSize + 5,555 + 2 * BoxSize - 5,2 * BoxSize - 5, SetC[2], true);
	DrawBox(555 + BoxSize + 5, 2 * BoxSize + 5, 555 + 2 * BoxSize - 5, 3 * BoxSize - 5, SetC[1], true);

}

void DrawDestroy(int x, int y, int color)
{
	

	if (color == 2)//赤
	{
		DrawExtendGraph(180 + (x * BoxSize), y * BoxSize, 180 + ((x + 1) * BoxSize), ((y + 1) * BoxSize), puyoimg[35], TRUE);


	}
	if (color == 3)//緑
	{
		DrawExtendGraph(180 + (x * BoxSize), y * BoxSize, 180 + ((x + 1) * BoxSize), ((y + 1) * BoxSize), puyoimg[41], TRUE);


	}
	if (color == 4)//青
	{
		DrawExtendGraph(180 + (x * BoxSize), y * BoxSize, 180 + ((x + 1) * BoxSize), ((y + 1) * BoxSize), puyoimg[47], TRUE);


	}
	if (color == 5)//黄色
	{
		DrawExtendGraph(180 + (x * BoxSize), y * BoxSize, 180 + ((x + 1) * BoxSize), ((y + 1) * BoxSize), puyoimg[53], TRUE);


	}


}

#endif
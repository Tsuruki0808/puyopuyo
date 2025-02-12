#pragma once

#ifndef __DATE_H__

#define __DATE_H__

int px[] = {0,3,4};
int py[] = {0,5,5};

int puyoimg[100];
int puyodate[100] = { 0 };

int mx, my;

int WidthSize = 8;//10描画箇所で+1,-1して左右の描画も
int HeightSize = 15;//22+1
int BoxSize = 50;


int ChackCnt = 0;

int ChackLog = 0; //0は上.1左.2上.3→
int ChackBoxX[30] = { 0 };
int ChackBoxY[30] = { 0 };
int ChackBoxColor[30] = { 0 };
bool ChackClearflg = false;

//int Color[300] = { 0xffffff };//いろの描画
int SetC[2] = { 0xffffff };//右上の次のブロックの描画に使用

int Waitnum = 0;

int Box[4] = { 2,3,3,4, };

int DropSpeed = 0;
int DropSpan =  10 ;//何フレームごとにブロックが落下するか

int PutBottonSpan[2] = { 5,10 };//0スペース,1左右移動(カウントが越えたら一回実行)

int BottonCnt[3] = { 0 };//0スペース,1,→2左

int SetColor[3] = { 0 };

int StaySetColor[3] = {0};

int ReturnBox = 0;//1,2,3,4,で一周の回転


bool GameStart = false;

bool DropFlg = false;

bool fastcnt[] = { 0 };//いろいろな箇所で初回起動時に起動。がありそうだから配列に

bool TouchGround[3] = { false };//ブロックが地面に触れたかの判定

int kakuninnum = 0;

int Score = 0;


//32*32

int map[15][8] = {
	
	
	
	{1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1},
    {1,0,2,3,4,5,0,1},
    {1,2,3,4,5,2,0,1},
    {1,2,3,4,5,2,0,1},
    {1,2,3,4,5,2,0,1},
	{1,1,1,1,1,1,1,1},
	
	/*
	{1,2,0,0,0,0,0,1},
	{1,2,0,0,0,0,0,1},
	{1,2,2,0,2,2,0,1},
	{1,2,1,0,1,2,1,1},
	{1,2,2,0,2,2,2,1},
	{1,1,2,1,1,1,2,1},
	{1,2,2,1,1,2,2,1},
	{1,2,1,1,1,2,1,1},
	{1,2,1,2,1,2,1,1},
	{1,2,1,2,1,2,2,1},
	{1,2,2,2,1,1,1,1},
	{1,2,1,2,2,2,1,1},
	{1,2,1,2,1,2,1,1},
	{1,2,2,2,1,2,2,1},
	{1,1,1,1,1,1,1,1},
	*/


};




	







#endif
#pragma once

#ifndef __DROPBOX_H__

#define __DROPBOX_H__


void DropBox(int j, int i)//map[y][x]
{
	
	if ((map[j][i] == 1 && map[j + 1][i] == 0) && (i != 0 && i != 12 &&j < 22))//ƒ}ƒbƒv‚Ì‰º‚ª‹ó‚¢‚Ä‚¢‚Äˆê”Ô‰º‚Å‚È‚¯‚ê‚Î
	{
		map[j + 1][i] = map[j][i];

		map[j][i] = 0;
	}
	
//	WaitTimer(5);			//ˆê’èŽžŠÔ‘Ò‚Â@¦‚±‚ê‚ª‚È‚¢‚Æˆêu‚Å•`‰æ‚³‚ê‚Ä‚µ‚Ü‚¤

}

#endif
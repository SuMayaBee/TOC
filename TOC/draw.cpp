// Draw on Screen like paint.
#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

// Press Left shift and move cursor to draw on the screen.
// release shift key to stop drawing.

int main()
{
    initwindow(1000, 600);
	
	POINT P, L;    
		
	while(!kbhit()){
		L.x = P.x;
		L.y = P.y;
		if(GetCursorPos(&P) and (GetKeyState(VK_SHIFT) & 0x8000)){
		
			line(L.x,L.y, P.x,P.y);
		}
	}
    getch();
    
    return 0;
}
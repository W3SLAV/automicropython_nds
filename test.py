import nds
# import os



KEY_RIGHT = (1 << 4)   # Keypad RIGHT button.
KEY_LEFT  = (1 << 5)   # Keypad LEFT button.
KEY_UP    = (1 << 6)   # Keypad UP button.
KEY_DOWN  = (1 << 7)   # Keypad DOWN button.
KEY_R     = (1 << 8)   # Right shoulder button.
KEY_L     = (1 << 9)   # Left shoulder button.
KEY_X     = (1 << 10)  # Keypad X button.
while 2>1:\n
   nds.swiWaitForVBlank()\n
   nds.scanKeys()\n
   keys = nds.keysDown()\n
   if (keys == KEY_UP):\n
       print('up!')\n
   if (keys == KEY_DOWN):\n
       print('down!')




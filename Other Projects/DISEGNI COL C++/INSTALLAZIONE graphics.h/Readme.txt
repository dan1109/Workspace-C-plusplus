how to enable graphics in codeblocks

follow theses steps

1. copy graphics.h and winbgim.h in include folder of codeblocks
2. copy libbgi.a in lib folder
3. open codeblock > linker setting > add library and locate libbgi.a > and on right
side paste this command -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
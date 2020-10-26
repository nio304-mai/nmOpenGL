* Модифицировать Makefile для nmopengl-nmc4, nmopengl-x86-x64
Вызывать из nmOpenGL_fork.
```
sed -i -e 's\-std=c++11\-std=c++11 -DTEXTURE_ENABLED\g' make/nmopengl-nmc4/Makefile
sed -i -e 's\DEBUG"\DEBUG", "TEXTURE_ENABLED"\g' make/nmopengl-x86-x64/premake5.lua
```

* Модифицировать Makefile для сборки теста  mc12101 и premake для x86 
Вызывать из test/nmpu1/textureTriangle/.
```
sed -i -e 's\-L "$(NMC_GCC_TOOLPATH)/nmc4-ide/lib"\-L"../../../../lib" -L "$(NMC_GCC_TOOLPATH)/nmc4-ide/lib"\g' make_mc12101_nmpu1_gcc/Makefile
sed -i -e 's\lnmpp-nmc4\lnmopengl-nmc4 -lnmpp-nmc4\g' make_mc12101_nmpu1_gcc/Makefile
sed -i -e 's\"nmpp-x86.lib"\"nmopengl-x86.lib", "nmpp-x86.lib"\g' make_x86/premake5.lua 
sed -i -e 's\"$(NMPP)/lib"\"../../../../lib", "$(nmpp)/lib"\g' make_x86/premake5.lua
```

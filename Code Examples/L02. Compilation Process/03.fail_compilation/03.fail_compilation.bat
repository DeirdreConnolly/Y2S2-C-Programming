cl.exe /Fo03.fail_compilation.obj /Tc03.fail_compilation.c /c
cl.exe /Fo03.res1.obj /Tc03.res1.c /c
cl.exe /Fo03.res2.obj /Tc03.res2.c /c
cl.exe /Fe03.fail_compilation.exe 03.fail_compilation.obj 03.res1.obj 03.res2.obj /link

 
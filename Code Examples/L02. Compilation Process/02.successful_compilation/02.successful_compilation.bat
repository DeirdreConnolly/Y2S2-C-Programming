cl.exe /Fo02.successful_compilation.obj /Tc02.successful_compilation.c /c
cl.exe /Fo02.res1.obj /Tc02.res1.c /c
cl.exe /Fo02.res2.obj /Tc02.res2.c /c
cl.exe /Fe02.successful_compilation.exe 02.successful_compilation.obj 02.res1.obj 02.res2.obj /link

 
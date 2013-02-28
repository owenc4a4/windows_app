// do.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
  printf("%d\n", argc);
  for (int i = 0; i < argc; i++)
    cout << argv[i];
  
  wstring str(argv[1]);
  printf("%s", str.c_str());
  /*
  std::ofstream f;
  printf("%d", argc);

  if (argc == 1)
   f.open("a.txt");
  else 
    f.open(argv[1]);

  f.close();
  */
	return 0;
}


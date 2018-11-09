#define _CRT_SECURE_NO_WARNINGS 
#include <conio.h>
#include <openssl/sha.h>
#include "Hash.h"



int main(int argc, char** argv[])
{

	Hash hashobj("hello world", "ES512", false);
	std::cout << hashobj.getHash().c_str() << std::endl;
	system("pause");
	return 0;

}

